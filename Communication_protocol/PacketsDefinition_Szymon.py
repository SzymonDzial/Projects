from enum import Enum


class TxPacketsEnum(Enum):
	null = 0
	null_confirmation = 1
	mode = 10
	relays = 20
	drive = 30
	mani_power = 40
	cam_switch = 70
	message = 120
	message_autonomus = 121


class RxPacketsEnum(Enum):
	null = 0
	null_confirmation = 1
	mode = 10
	modules_status = 11
	relays = 20
	cam_switch = 70
	ahrs = 90
	gps = 91
	voltage = 100
	current = 101
	power = 102
	message = 120
	message_autonomus = 121


TxPackets = {
	# key: value
	# klucz - identyfikator pakietu
	# value - format string
	TxPacketsEnum.null: '',
	TxPacketsEnum.null_confirmation: '',
	TxPacketsEnum.mode: 'b',
	TxPacketsEnum.relays: 'b',
	TxPacketsEnum.drive: 'bbbb',
	TxPacketsEnum.mani_power: 'bbbb bbbb',
	TxPacketsEnum.cam_switch: 'bb',
	TxPacketsEnum.message: '16c',
	TxPacketsEnum.message_autonomus: '16c'
}

RxPackets = {
	RxPacketsEnum.null: '',
	RxPacketsEnum.null_confirmation: '',
	RxPacketsEnum.mode: 'b',
	RxPacketsEnum.modules_status: 'bbbb',
	RxPacketsEnum.relays: 'b',
	RxPacketsEnum.ahrs: '3f',
	RxPacketsEnum.gps: '3f',
	RxPacketsEnum.cam_switch: 'bb',
	RxPacketsEnum.voltage: '6b',
	RxPacketsEnum.current: '6b',
	RxPacketsEnum.power: '6b',
	RxPacketsEnum.message: '16c',
	RxPacketsEnum.message_autonomus: '16c'}
#


TxPacketsConfirmation = (
TxPacketsEnum.null_confirmation, TxPacketsEnum.mode, TxPacketsEnum.relays, TxPacketsEnum.cam_switch,
TxPacketsEnum.message, TxPacketsEnum.message_autonomus)
RxPacketsConfirmation = (
RxPacketsEnum.null_confirmation, RxPacketsEnum.mode, RxPacketsEnum.relays, RxPacketsEnum.cam_switch,
RxPacketsEnum.message, RxPacketsEnum.message_autonomus)
