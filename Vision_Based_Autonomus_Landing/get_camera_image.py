#!/usr/bin/env python
from __future__ import print_function
import sys
import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import detect_aruco
from std_msgs.msg import Int32MultiArray

# klasa subskrybująca oraz udostępniająca tematy ROS związane z kamerą
class image_converter:

  # inicjalizacja tematów dla subsrybowanych i udostępnianych danych
  def __init__(self):
    self.bridge = CvBridge()
    self.image_sub = rospy.Subscriber("/webcam/image_raw",Image,self.callback)
    self.data_pub=rospy.Publisher('centre_edge', Int32MultiArray,queue_size=10)

  # funkcja odbierająca, przerabiająca, a następnie udostępniająca obrobiony obraz z kamery
  def callback(self,data):
    try:
      cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    except CvBridgeError as e:
      print(e)
    edge_centre=detect_aruco.find_aruco(cv_image)
    msg = Int32MultiArray()
    msg.data = edge_centre  
    self.data_pub.publish(msg)
    
# funkcja główna cyklicznie wykorzystująca powyższą klasę  
def main(args):
    ic = image_converter()
    rospy.init_node('image_converter', anonymous=True)
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main(sys.argv)