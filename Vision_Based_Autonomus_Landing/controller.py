from math import sin, cos,radians,degrees,atan2,asin,sqrt,pow
import quaternion
from angle_on_image import get_angle_image_centre
import numpy as np
import rotation_matrix
from speed_control import fuzzy_ctr

def controller(size,width,xcen,ycen,psi,quaternion_vect,FSxy,FSz):

    #zamiana z kwaternionów na kąty Eulera
    euler_angles=quaternion.euler_from_quaternion(quaternion_vect.x, quaternion_vect.y, quaternion_vect.z, quaternion_vect.w)

    #wyliczanie przesunięcia w pikselach
    dify=639-ycen
    difx=639-xcen

    #wyliczanie przesunięcia rzeczywistego
    w_small=width
    x_small=size*difx/w_small
    y_small=size*dify/w_small
    h_small=(size*1280/w_small)/1.6846

    #wyliczanie kątów Eulera dla markera i kamery
    angley=get_angle_image_centre(dify,1,0)
    anglex=get_angle_image_centre(difx,0,angley)

    #Zamiana kątów Eulera na macierze obrotu, minus jest spowodowany innym zwrotem kąta teta dla układu współrzędnych domyślnego drona
    R1=rotation_matrix.mac(euler_angles[0],-euler_angles[1],0)
    R2=rotation_matrix.mac(anglex,angley,0)

    #kalkulowanie sumarycznego obrotu
    R=np.dot(R1,R2)

    #powrót na kąty Eulera
    yaw=-atan2(R[1][0],R[0][0])
    pitch=-asin(R[2][0])
    roll=atan2(R[2][1],R[2][2])

    #wyliczanie przesunięcia dla ziemskiego układu odniesienia
    l_small=sqrt(pow(h_small,2)+pow(x_small,2)+pow(y_small,2))
    ly=l_small*cos(roll)*sin(pitch)*cos(yaw)-l_small*sin(roll)*sin(yaw)
    lx=l_small*cos(roll)*sin(pitch)*sin(yaw)+l_small*sin(roll)*cos(yaw)
    lz=sqrt(pow(l_small,2)-pow(ly,2)-pow(lx,2))

    #sterowanie prędkością na podstawie przesunięcia względem markerów
    vx=-fuzzy_ctr(FSxy,lx)
    vy=fuzzy_ctr(FSxy,ly)
    vz=-fuzzy_ctr(FSz,lz)

    #przeniesienie prędkości z układu związanego z dronem, na ziemski układ odniesienia
    vxr=cos(radians(90-psi))*vx+sin(radians(90-psi))*vy
    vyr=-sin(radians(90-psi))*vx+cos(radians(90-psi))*vy
    return [vxr,vyr,vz/2]