import struct

from crccheck.crc import Crc16X25
from struct import *
from serial import Serial
from threading import Thread, Lock
from PacketsDefinition_Szymon import *
from time import sleep
import time


class CommmunicationService_Szymon:
	def __init__(self, port: Serial, station_nr: bool, tx_id=TxPacketsEnum, rx_id=RxPacketsEnum,
				 tx_def=TxPackets, rx_def=RxPackets,
				 tx_confirm=TxPacketsConfirmation, rx_confirm=RxPacketsConfirmation):

		self.__tx_id = tx_id
		self.__rx_id = rx_id
		self.__tx_def = tx_def
		self.__rx_def = rx_def
		self.__tx_confirm = tx_confirm
		self.__rx_confirm = rx_confirm
		self.__rx_confirm_nr = 0
		self.__tx_confirm_nr = 0
		self.__station_nr = station_nr

		self.__port = port
		self.__start_char = 0
		self.lock = Lock()
		self.__tx_buffer = {i: [] for i in tx_id}
		self.__rx_buffer = {i: [] for i in rx_id}

		self.__tx_thread = None
		self.__rx_thread = None

		self.__tx_temp_important_data = None
		self.__tx_temp_important_key = None

		self.__start_time = time.time()


	def start(self):

		if not self.__port.is_open:
			self.__port.open()

		self.__tx_thread = Thread(target=self.__tx_thread_runner)
		self.__tx_thread.start()
		self.__rx_thread = Thread(target=self.__rx_thread_runner)
		self.__rx_thread.start()

		pass

	def stop(self):

		self.__tx_thread.join()
		self.__rx_thread.join()
		self.__tx_thread = None
		self.__rx_thread = None
		self.__port.close()

	def __tx_thread_runner(self):

		while True:
			sleep(0.01)
			self.lock.acquire()
			sleep(0.01)

			if not self.__port.isOpen():
				self.lock.release()
				sleep(0.01)
				break

			end_time = time.time()
			dif_tim = end_time - self.__start_time
			if self.__tx_temp_important_data is not None and dif_tim > 1:
				self.__start_time = time.time()
				print("przesyłam znowu")
				packet = bytearray(0)
				packet.append(0x66)
				packet.append(self.__tx_temp_important_key)
				packet.extend(self.__tx_temp_important_data)

				if self.__station_nr:
					packet.append((self.__tx_confirm_nr & 0x0F) << 4 | (self.__rx_confirm_nr & 0x0F))
				else:
					packet.append((self.__rx_confirm_nr & 0x0F) << 4 | (self.__tx_confirm_nr & 0x0F))

				crc = Crc16X25().process(packet)
				packet.extend(crc.finalbytes(byteorder='little'))
				print(packet)
				self.__port.write(packet)


			else:
				for key in self.__tx_buffer.keys():
					if self.__tx_buffer[key]:
						packet = bytearray(0)
						packet.append(0x66)
						packet.append(key.value)
						packet.extend(self.__tx_buffer[key][0])

						if key in self.__tx_confirm:
							end_time = time.time()
							if end_time - self.__start_time < 1:
								break
							self.__start_time = time.time()

							self.__tx_confirm_nr = self.__tx_confirm_nr + 1
							self.__tx_temp_important_data = self.__tx_buffer[key][0]
							self.__tx_temp_important_key = key.value
							if self.__tx_confirm_nr >= 16:
								self.__tx_confirm_nr = 1

						if self.__station_nr:
							rel_byte = (self.__tx_confirm_nr & 0x0F) << 4 | (self.__rx_confirm_nr & 0x0F)
							packet.append((self.__tx_confirm_nr & 0x0F) << 4 | (self.__rx_confirm_nr & 0x0F))
						else:
							rel_byte = (self.__tx_confirm_nr & 0x0F) << 4 | (self.__rx_confirm_nr & 0x0F)
							packet.append((self.__rx_confirm_nr & 0x0F) << 4 | (self.__tx_confirm_nr & 0x0F))

						crc = Crc16X25().process(packet)
						packet.extend(crc.finalbytes(byteorder='little'))

						self.__port.write(packet)
						print(packet)
						self.__tx_buffer[key].remove(self.__tx_buffer[key][0])
						break
			sleep(0.01)
			self.lock.release()

			sleep(0.01)

	def __rx_thread_runner(self):
		id_nr = None
		length=None
		fmt=None
		while True:
			sleep(0.01)
			self.lock.acquire()
			sleep(0.01)
			if not self.__port.isOpen():
				self.lock.release()
				sleep(0.01)
				break

			if self.__start_char == 0:
				len2 = self.__port.inWaiting()
				if len2 > 0:
					if int.from_bytes(self.__port.read(1), byteorder='little') == 0x66:
						# start_byte = self.__port.read(1)
						id_byte = self.__port.read(1)
						id_nr = int.from_bytes(id_byte, byteorder='little')
						self.__start_char = 1

			elif self.__start_char == 1:
				if id_nr == 7:  # numer tego potwierdzenia bajta
					if self.__port.inWaiting() >= 1:
						confirm_rest_bytes = self.__port.read(1)
						confirm_rest_tuple = struct.unpack('B', confirm_rest_bytes)
						confirm_rest = confirm_rest_tuple[0]

						if self.__station_nr:
							self.__rx_confirm_nr = confirm_rest & 0x0F
							self.__tx_confirm_nr = (confirm_rest & 0xF0) >> 4
						else:
							self.__rx_confirm_nr = (confirm_rest & 0xF0) >> 4
							self.__tx_confirm_nr = confirm_rest & 0x0F

					self.__start_char = 0

				if id_nr in [i.value for i in self.__rx_id]:
					package = self.__rx_id(id_nr)
					fmt = self.__rx_def[package]
					length = calcsize(fmt)
					self.__start_char = 2
				else:
					self.__start_char = 0

			elif self.__start_char == 2:
				if self.__port.inWaiting() >= 3 + length:
					rest = self.__port.read(3 + length)

					# temp=id_byte
					# temp.extend(rest[0:-2])
					temp_crc = bytearray(0)
					temp_crc.append(0x66)
					temp_crc.append(id_nr)
					temp_crc.extend(rest[0:-2])
					crc = Crc16X25().process(temp_crc)
					crc = crc.finalbytes(byteorder='little')
					crcp = rest[-2:]

					if crc == crcp:
						# self.__rx_buffer[self.__rx_id(id_nr)] = pack(fmt, rest[0:-3])  # TODO
						self.__rx_buffer[self.__rx_id(id_nr)].append(unpack(fmt, rest[0:-3]))
						print("odebrane")
						print(rest)
					else:
						self.lock.release()
						sleep(0.1)
						break

					temp_check = struct.unpack('B', rest[-3:-2])
					check_confirm_nr = temp_check[0]

					if self.__station_nr:
						check_rx_confirm_nr = check_confirm_nr & 0x0F
						check_tx_confirm_nr = (check_confirm_nr & 0xF0) >> 4
					else:
						check_rx_confirm_nr = (check_confirm_nr & 0xF0) >> 4
						check_tx_confirm_nr = check_confirm_nr & 0x0F

					if check_tx_confirm_nr == self.__tx_confirm_nr:
						self.__tx_temp_important_data = None
						self.__tx_temp_important_key = None
						print("potwierdzam zwrot rejability bajta")

					if self.__tx_confirm_nr != check_tx_confirm_nr:
						print("Utrata cos z reliability byte")

					self.__rx_confirm_nr = check_rx_confirm_nr

					licznik = 0
					for key in self.__tx_buffer.keys():
						if self.__tx_buffer[key]:
							licznik = licznik + 1
							break
					if licznik == 0:  # potwierdzenei klucza gdy nie ma nic do wyslania innego
						packet = bytearray(0)
						packet.append(0x66)
						packet.append(7)  # potwierdzenie klucza bedzie np. 7!!!!!!!!!!!!
						if self.__station_nr:
							packet.append((self.__tx_confirm_nr & 0x0F) << 4 | (self.__rx_confirm_nr & 0x0F))
						else:
							packet.append((self.__rx_confirm_nr & 0x0F) << 4 | (self.__tx_confirm_nr & 0x0F))

						self.__port.write(packet)

				self.__start_char = 0
			else:
				self.__start_char=0

			sleep(0.01)
			self.lock.release()

			sleep(0.01)

	def read(self, packet_id):
		self.lock.acquire()

		if packet_id in self.__rx_id:
			if not not self.__rx_buffer[packet_id]:
				wynik = self.__rx_buffer[packet_id][0]
				self.__rx_buffer[packet_id].remove(self.__rx_buffer[packet_id][0])
				return wynik
			self.lock.release()
			sleep(0.01)
		else:
			self.lock.release()
			sleep(0.01)
			raise TypeError("Jestes idota xd")

	def write(self, packet_id, data: list or tuple):

		self.lock.acquire()
		if packet_id in self.__tx_id:
			self.__tx_buffer[packet_id].append(pack(self.__tx_def[packet_id], *data))
			self.lock.release()
			sleep(0.01)

		else:
			self.lock.release()
			sleep(0.01)
			raise TypeError("Jestes idota")
