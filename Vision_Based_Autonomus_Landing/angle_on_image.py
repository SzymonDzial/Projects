from math import atan,cos

# wyliczanie kątów Eulera dla wykrytego markera względem kamery
def get_angle_image_centre(dif,k,angley):
    if k==1:
        # wyliczanie kąta przy uzyciu znanej wartości FOV kamery
        angle=atan(dif*1.68457676/1280)
    else:
        # ze względu na zależność kąta przechylenia od przesunięcia w osi y, pojawia się również cos(angley)
        angle=atan((dif*1.68457676/1280)*cos(angley))
    return angle