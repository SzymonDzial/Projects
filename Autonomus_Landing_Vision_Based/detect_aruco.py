#!/usr/bin/env python
import cv2
from math import *

# funkcja wyliczająca przybliżonego środka markera
def centre_count(x1,x3):
    centre_x=min(x1[0],x3[0])+abs(x1[0]-x3[0])/2
    centre_y=min(x1[1],x3[1])+abs(x1[1]-x3[1])/2
    return [int(centre_x),int(centre_y)]

# funkcja wyliczająca środek i długość boku dla wykrytego markera
def find_aruco(image):
    # wykrycie markera i utworzenie wektorów zawierających dane o położeniu środka oraz długości krawędzi
    arucoDict = cv2.aruco.Dictionary_get(cv2.aruco.DICT_4X4_100)
    arucoParams = cv2.aruco.DetectorParameters_create()
    (corners, ids, rejected) = cv2.aruco.detectMarkers(image, arucoDict,
	parameters=arucoParams)
    edge_length=[0,0]
    centre=[[0,0],[0,0]]

    # ustawienie parametrów obrabianego obrazu, uzupełnienie danych w wektorach i dorysowanie linii na krawędziach, świadczących o wykryciu znacznika
    for i in range(len(corners)):
        font = cv2.FONT_HERSHEY_SIMPLEX
        org = (int(corners[i][0][0][0]-30),int(corners[i][0][0][1]-30))
        fontScale = 1
        color = (255, 0, 0)
        thickness = 2
        image = cv2.putText(image, str(ids[i]), org, font, 
                        fontScale, color, thickness, cv2.LINE_AA)

        # wyliczanie długości krawędzi oraz środka markera w zależności od wykrycia obu lub jednego ze znaczników               
        if len(ids)==2:
            if ids[i]==5:
                edge_length[1]=int(sqrt(pow(corners[i][0][0][0]-corners[i][0][1][0],2)+pow(corners[i][0][0][1]-corners[i][0][1][1],2)))
                centre[1]=centre_count(corners[i][0][0],corners[i][0][2])
            else:
                edge_length[0]=int(sqrt(pow(corners[i][0][0][0]-corners[i][0][1][0],2)+pow(corners[i][0][0][1]-corners[i][0][1][1],2)))
                centre[0]=centre_count(corners[i][0][0],corners[i][0][2])  
        elif len(ids)==1:
            if ids[i]==5:
                edge_length[1]=int(sqrt(pow(corners[i][0][0][0]-corners[i][0][1][0],2)+pow(corners[i][0][0][1]-corners[i][0][1][1],2)))
                edge_length[0]=0
                centre[1]=centre_count(corners[i][0][0],corners[i][0][2])
                centre[0]=[0,0]
            else:
                edge_length[0]=int(sqrt(pow(corners[i][0][0][0]-corners[i][0][1][0],2)+pow(corners[i][0][0][1]-corners[i][0][1][1],2)))
                edge_length[1]=0
                centre[0]=centre_count(corners[i][0][0],corners[i][0][2])
                centre[1]=[0,0]

        # dorysowywanie zielonych linii zakreślających wykryty marker na obrabianym obrazie 
        for j in range(len(corners[i][0])):
            if j<3:
                cv2.line(image,(corners[i][0][j][0],corners[i][0][j][1]),(corners[i][0][j+1][0],corners[i][0][j+1][1]),(255,0,0),5)
            else:
                cv2.line(image,(corners[i][0][j][0],corners[i][0][j][1]),(corners[i][0][0][0],corners[i][0][0][1]),(255,0,0),5)

    # wyświetlenie obrobionego obrazu oraz przekazanie danych o położeniu środka markera oraz długości jego krawędzi
    return_array=[edge_length[0],edge_length[1],centre[0][0],centre[0][1],centre[1][0],centre[1][1]]
    image = cv2.resize(image, (900, 900)) 
    cv2.imshow("pic2",image)
    cv2.waitKey(3)
    return return_array