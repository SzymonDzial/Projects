import matplotlib as mpl
import matplotlib.pyplot as plt
import pickle 

# funkcja przygotowująca pliki dla funkcji plot, która wyświetla wykresy
def do(nazwa,opis,linestyle):
   with open(nazwa, 'rb') as f:
    p1 = pickle.load(f) 
    plot(p1[0],p1[1],p1[2],p1[3],opis,linestyle)

# funkcja wyświetlająca wykresy oraz określająca ich wizualną reprezentację
def plot(x,y,z,t,numer,line_style):

    dpi=300

    mpl.rcParams['legend.fontsize'] = 10

    fig = plt.figure(1)
    ax = fig.gca(projection='3d')
    ax.plot(x, y, z, label=numer, linestyle=line_style, color='black')
    ax.legend()
    ax.set_xlabel('x [m]')
    ax.set_ylabel('y [m]')
    ax.set_zlabel('z [m]')
    plt.savefig('1.png',dpi=dpi)

    plt.figure(2)
    plt.plot(x,z, label=numer, linestyle=line_style, color='black')
    plt.legend()
    plt.title("z(x)")
    plt.xlabel("x [m]")
    plt.ylabel("z [m]")
    plt.savefig('2.png',dpi=dpi)

    plt.figure(3)
    plt.plot(y,z, label=numer, linestyle=line_style, color='black')
    plt.title("z(y)")
    plt.xlabel("y [m]")
    plt.ylabel("z [m]")
    plt.legend()
    plt.savefig('3.png',dpi=dpi)

    plt.figure(4)
    plt.plot(x,y, label=numer, linestyle=line_style, color='black')
    plt.title("y(x)")
    plt.xlabel("x [m]")
    plt.ylabel("y [m]")
    plt.legend()
    plt.savefig('4.png',dpi=dpi)

    t2=[]
    z2=[]
    for i in range(len(t)):
        if i>0:
            if z[i]==z[i-1]: 
                continue
    
        t2.append(t[i])
        z2.append(z[i])

    plt.figure(5)
    plt.plot(t2,z2, label=numer, linestyle=line_style, color='black')
    plt.title("z(t)")
    plt.xlabel("t [s]")
    plt.ylabel("z [m]") 
    plt.legend()
    plt.savefig('5.png',dpi=dpi)

    t2=[]
    x2=[]
    for i in range(len(t)):
        if i>0:
            if x[i]==x[i-1]: 
                continue
    
        t2.append(t[i])
        x2.append(x[i])

    plt.figure(6)
    plt.plot(t2,x2, label=numer, linestyle=line_style, color='black')
    plt.title("x(t)")
    plt.xlabel("t [s]")
    plt.ylabel("x [m]") 
    plt.legend()
    plt.savefig('6.png',dpi=dpi)

    t2=[]
    y2=[]
    for i in range(len(t)):
        if i>0:
            if y[i]==y[i-1]: 
                continue
    
        t2.append(t[i])
        y2.append(y[i])

    plt.figure(7)
    plt.plot(t2,y2, label=numer, linestyle=line_style, color='black')
    plt.title("y(t)")
    plt.xlabel("t [s]")
    plt.ylabel("y [m]")   
    plt.legend()
    plt.savefig('7.png',dpi=dpi)

do('p1','Model 1','solid')
do('p8','Model 8','dashed')
do('p9','Model 9','dotted')

plt.show()