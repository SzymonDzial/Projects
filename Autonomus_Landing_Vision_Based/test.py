#! /usr/bin/env python
import rospy
from iq_gnc.py_gnc_functions import *
from iq_gnc.PrintColours import *

# połączenie z dronem oraz przeprowadzenie startu w celu przygotowania drona do przeprowadzenia automatycznego lądowania
rospy.init_node("drone_controller", anonymous=True)
drone = gnc_api()
drone.wait4connect()   
drone.set_mode("GUIDED") 
drone.initialize_local_frame()
drone.takeoff(7)
drone.set_destination(-6,-6,10,90) 
rate = rospy.Rate(3)  