from math import sin,cos

# funkcja tworząca macierz obrotu na podstawie kątów Eulera
def mac(u,v,w):
    R= [[cos(v)*cos(w), sin(u)*sin(v)*cos(w)-cos(u)*sin(w), sin(u)*sin(w)+cos(u)*sin(v)*cos(w)],
    [cos(v)*sin(w), cos(u)*cos(w)+sin(u)*sin(v)*sin(w),cos(u)*sin(v)*sin(w)-sin(u)*cos(w)],
    [-sin(v), sin(u)*cos(v),cos(u)*cos(v)]]
    return R