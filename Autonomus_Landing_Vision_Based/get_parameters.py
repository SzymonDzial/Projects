#! /usr/bin/env python
# Import ROS.
import rospy
# Import the API.
from iq_gnc.py_gnc_functions import *
# To print colours (optional).
from iq_gnc.PrintColours import *
#from get_camera_image import *
from std_msgs.msg import Int32MultiArray


# klasa służąca do odbierania obrobionych danych z kamery
class get_param:

    # stworzenie wektora zerowego oraz utworzenie subskrybującego tematu
    def __init__(self):
        self.mydata=[0,0,0,0,0,0]
        rospy.Subscriber("centre_edge", Int32MultiArray, self.callback)

    # odbiór danych z kamery
    def get_param2(self):
        rospy.Subscriber("centre_edge", Int32MultiArray, self.callback)

    # funkcja odbierająca dane
    def callback(self,data):
        self.mydata=data.data