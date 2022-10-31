#! /usr/bin/env python
import rospy
from iq_gnc.py_gnc_functions import *
from iq_gnc.PrintColours import *
import time
import get_parameters
import controller
import speed_control
import pickle

def main():
    
    # nawiązanie połączenia z dronem, ustawienie trybu i częstotliwości odświeżania
    rospy.init_node("drone_controller", anonymous=True)
    drone = gnc_api()
    drone.wait4connect()   
    drone.set_mode("GUIDED") 
    drone.initialize_local_frame()
    rate = rospy.Rate(3)    

    # odbiór danych z kamery, stworzenie instancji klasy odpowiedzialnej za sterowanie oraz utworzenie pustych wektorów służących do zapisu parametrów lotu
    get_par=get_parameters.get_param()
    FSxy=speed_control.create_fuzzy_xy()
    FSz=speed_control.create_fuzzy_z()
    p=[]
    x=[]
    y=[]
    z=[]
    time_simul=[]

    while not rospy.is_shutdown():  

        # pobranie danych z tematu udostępniającego parametry po obróbce obrazu
        get_par.get_param2()  
        
        # zapis położenia drona w odniesieniu do czasu (wykonany w stałych odstępach) w celu wykonania wykresów 
        if len(time_simul)==0:
            time_check=time.time()
            start=time.time()
            time_simul.append(0)
            x.append(drone.get_current_location().x)
            y.append(drone.get_current_location().y)
            z.append(drone.get_current_location().z)
        elif time.time()-time_check>0.05:
            time_check=time.time()
            time_simul.append(time.time()-start)
            x.append(drone.get_current_location().x)
            y.append(drone.get_current_location().y)
            z.append(drone.get_current_location().z)

        # sterowanie prędkością drona w zależności od wielkości wykrytego znacznika    
        if get_par.mydata[5]>0:
            v=controller.controller(0.18,get_par.mydata[1],get_par.mydata[4],get_par.mydata[5],drone.current_heading_g,drone.current_pose_g.pose.pose.orientation,FSxy,FSz)
            drone.set_velocity(v[0], v[1], v[2], 0,0,0,0)
        elif get_par.mydata[3]>0:
            v=controller.controller(1,get_par.mydata[0],get_par.mydata[2],get_par.mydata[3],drone.current_heading_g,drone.current_pose_g.pose.pose.orientation,FSxy,FSz)
            drone.set_velocity(v[0], v[1], v[2], 0,0,0,0)
        
        # wyłączenie silników na niewielkiej wysokości
        if drone.get_current_location().z<0.131:
            break
        time.sleep(0.0001)
    drone.land()

    # zapis do pliku danych uzyskanych w celu wykonania wykresu 
    p.append(y)
    p.append(z)
    p.append(time_simul)
    with open("p9", 'wb') as f:
        pickle.dump(p, f)

if __name__ == '__main__':
    try:       
        main()
    except KeyboardInterrupt:
        exit()
