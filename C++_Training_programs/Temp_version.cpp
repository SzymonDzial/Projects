#include <stdio.h>
#include <time.h>
#include <stdlib.h>
float Kelw_na_Cels (float k)
{
    if (k<0)
        return -273.15;
    else
        return k-273.15;
}
float Kelw_na_Fahr (float k)
{
    if (k<0)
       return -459.67;
    else
        return  k*9/5-459.67;
}
float Cels_na_Fahr (float c)
{
    if (c<-273.15)
        return -459.67;
    else
        return c*9/5+32;
}
float Cels_na_Kelw (float c)
{
    if (c<-273.15)
        return 0;
    else
        return c-273.15;
}
float Fahr_na_Cels(float f)
{
    if (f<-459.67)
        return -273.15;
    else
        return (f-32.0)* 5.0 / 9.0;
}
float Fahr_na_Kelw (float f)
{
    if (f<-459.67)
        return 0;
    else
        return (f+459.67) * 5.0/9.0;
}
int sprawdz (float temp,char stopnie)
{
 int b=0;
    if ((temp<0)&&(stopnie=='K'))
    {
      b=1;
    }
     else if  ((temp<-273.15)&&(stopnie=='C'))
    {
      b=1;
    }
     else if  ((temp<-459.67)&&(stopnie=='F'))
    {
      b=1;
    }
      return b;
}
int licznik = 0;
float temp1 [20];
char znak1 [20];
float temp2 [20];
char znak2 [20];

int Dodaj_wiersz (float t1,char z1, float t2,char z2)
{
  {
    temp1 [licznik]=t1;
    znak1 [licznik]=z1;
    temp2 [licznik]=t2;
    znak2 [licznik]=z2;
    licznik++;
  }
 return 0;
}

int main ()
{
 
  float temp;
  char stopnie;
    while (1)
  {
      int g=0;
     int menu;
      
	  
	  
	  
      printf ("1- C na K\n2- C na F\n3- F na K\n4- F na C\n5- K na F\n6- K na C\n7- koniec\n8-tabela\n9-usuwanie wiersza\n");
      printf ("10-modyfikacja wiersza\n11-wype³nienie tablic losowymi wartoœciami\n12-inteligentne losowanie\n");
      printf ("13-inteligentna modyfikacja temperatur\n14-dany zakres tablicy\n15-modyfikacja usuwania\n");
      printf ("Podaj cyfre od 1 do 15: ");
      scanf ("%d",&menu);
      
     if(menu>0&&menu<16)
     {
	 
    
     
     
	 
     
	 
      switch (menu)
      {
        case 1:
         {
           printf ("Podaj C: ");
           scanf ("%f",&temp);
           stopnie='C';
           Dodaj_wiersz (temp,'C',Cels_na_Kelw(temp),'K');
           g=sprawdz(temp,stopnie);
           printf ("K =%.2f\n\n",Cels_na_Kelw(temp));
           break;
         }
        case 2:
         {
           printf ("Podaj C: ");
           scanf ("%f",&temp);
           Dodaj_wiersz (temp,'C',Cels_na_Fahr(temp),'F');
           stopnie='C';
           g=sprawdz(temp,stopnie);
           printf ("F =%.2f\n\n",Cels_na_Fahr(temp));
           break;
         }
        case 3:
         {
            printf ("Podaj F: ");
            scanf ("%f",&temp);
            Dodaj_wiersz (temp,'F',Fahr_na_Kelw(temp),'K');
            stopnie='F';
            g=sprawdz(temp,stopnie);
            printf ("K =%.2f\n\n",Fahr_na_Kelw(temp));
            break;
         }
        case 4:
         {
            printf ("Podaj F: ");
            scanf ("%f",&temp);
            Dodaj_wiersz (temp,'F',Fahr_na_Cels(temp),'C');
            stopnie='F';
            g=sprawdz(temp,stopnie);
            printf ("C =%.2f\n\n",Fahr_na_Cels(temp));
            break;
         }
        case 5:
         {
            printf ("Podaj K: ");
            scanf ("%f",&temp);
            Dodaj_wiersz (temp,'K',Kelw_na_Fahr(temp),'F');
            stopnie='K';
            g=sprawdz(temp,stopnie);
            printf ("F =%.2f\n\n",Kelw_na_Fahr(temp));
            break;
         }
        case 6:
         {
            printf ("Podaj K: ");
            scanf ("%f",&temp);
            Dodaj_wiersz (temp,'K',Kelw_na_Cels(temp),'C');
            stopnie='K';
            g=sprawdz (temp,stopnie);
            printf ("C =%.2f\n\n",Kelw_na_Cels (temp));
            break;
         }
        case 7:
            {
                break;
            }
        case 8:
         {
            licznik=0;
            while (licznik<20)
            {
                if (znak1[licznik]==0)
                 {
                     break;
                 }
               else
                 {
                printf ("%d %.2f %c\t %.2f %c\n",licznik,temp1[licznik],znak1[licznik],temp2[licznik],znak2[licznik]);
                 }

               licznik++;
            }
            break;
         }
        case 9:
            {
               int w;
               printf ("Który numer wiersza chcesz usun¹æ?\n");
               scanf ("%d",&w);
               int i;
               for (i=w;i<licznik;i++)
               {

                   temp1[i]=temp1[i+1];
                   znak1[i]=znak1[i+1];
                   temp2[i]=temp2[i+1];
                   znak2[i]=znak2[i+1];
               }
               i--;
            }
            break;

        case 10:
            {
                int y;
                printf ("Wybierz wiersz, który chcesz zmodyfikowaæ\n");
                scanf ("%d",&y);
                printf ("Wpisz nowe temperatury razem ze znakami\n");
                float t1,t2;
                char z1,z2;
                scanf ("%f\n%c\n%f\n%c",&t1,&z1,&t2,&z2);
                temp1[y]=t1;
                znak1[y]=z1;
                temp2[y]=t2;
                znak2[y]=z2;
                printf ("%d\t%.2f%c\t%.2f%c\n",y,t1,z1,t2,z2);
                break;
            }
        case 11:
            {
                int m;
                srand(time(NULL));
                int m1,m2;
                char k1,k2;
                for(m=0;m<=19;m++)
                {
                  temp1[m]=rand();
                  m1=rand()%3;
                  if (m1==0)
                  {
                      k1='F';
                  }
                  else if (m1==1)
                  {
                      k1='C';
                  }
                  else if (m1==2)
                  {
                      k1='K';
                  }
                  znak1[m]=k1;
                  temp2[m]=rand();
                  int m2=rand()%3;
                  if (m2==0)
                  {
                      k2='F';
                  }
                  else if (m2==1)
                  {
                      k2='C';
                  }
                  else if (m2==2)
                  {
                      k2='K';
                  }
                  znak2[m]=k2;
                }
            }
            break;
        case 12:
            {
                int m;
                srand(time(NULL));
                char k1;
                int o;
                for(m=0;m<=19;m++)
                {
                  temp1[m]=rand();
                  int m1=rand()%3;
                  if (m1==0)
                  {
                      k1='F';
                      o=rand()%2;
                      if (o==0)
                      {
                        Dodaj_wiersz (temp1[m],k1,Fahr_na_Cels(temp1[m]),'C');
                      }
                      else
                      {
                        Dodaj_wiersz (temp1[m],k1,Fahr_na_Kelw(temp1[m]),'K');
                      }
                  }
                  else if (m1==1)
                  {
                      k1='C';
                      o=rand()%2;
                      if (o==0)
                      {
                        Dodaj_wiersz (temp1[m],k1,Cels_na_Fahr(temp1[m]),'F');
                      }
                      else
                      {
                          Dodaj_wiersz (temp1[m],k1,Cels_na_Kelw(temp1[m]),'K');
                      }
                  }
                  else if (m1==2)
                  {
                      k1='K';
                      o=rand()%2;
                      if (o==0)
                      {
                          Dodaj_wiersz (temp1[m],k1,Kelw_na_Fahr(temp1[m]),'F');
                      }
                      else
                      {
                          Dodaj_wiersz (temp1[m],k1,Kelw_na_Cels(temp1[m]),'C');
                      }
                  }


                }
            }
            break;

        case 13:
            {
                int y;
                printf ("Wybierz wiersz, który chcesz zmodyfikowaæ\n");
                scanf ("%d",&y);
                printf ("Wpisz now¹ temperaturê razem ze znakami\n");
                float t1;
                char z1;
                scanf ("%f\n%c",&t1,&z1);
                temp1[y]=t1;
                znak1[y]=z1;
                if (znak2[y]=='C'&&z1=='K')
                {
                    temp2[y]=Kelw_na_Cels (temp1[y]);
                }
                else if (znak2[y]=='C'&&z1=='F')
                {
                    temp2[y]=Fahr_na_Cels (temp1[y]);
                }
                else if (znak2[y]=='K'&&z1=='F')
                {
                   temp2[y]=Fahr_na_Kelw (temp1[y]);
                }
                else if (znak2[y]=='K'&&z1=='C')
                {
                    temp2[y]=Cels_na_Kelw (temp1[y]);
                }
                else if (znak2[y]=='F'&&z1=='C')
                {

                   temp2[y]=Cels_na_Fahr (temp1[y]);
                }
                else if (znak2[y]=='F'&&z1=='K')
                {
                    temp2[y]=Kelw_na_Fahr (temp1[y]);
                }
                else if (znak2[y]=='F'&&z1=='F')
                {
                    temp2[y]=temp1[y];
                }
                 else if (znak2[y]=='K'&&z1=='K')
                {
                    temp2[y]=temp1[y];
                }
                 else if (znak2[y]=='C'&&z1=='C')
                {
                    temp2[y]=temp1[y];
                }
            }
            break;

        case 14:
            {
                int z,c;
                printf ("Iloœæ elementów w tablicy: %d\n",licznik);
                printf ("Od którego wiersza wpisaæ?\n");
                scanf ("%d",&z);
                if (licznik<=z)
                {
                    printf ("Jest mniej elementów w tablicy\n");
                    break;
                }
                if (z<0)
                {
                    printf ("Wiersz nie mo¿e byæ ujemny\n");
                    break;
                }
                printf ("Na którym wierszu zakoñczyæ?\n");
                scanf ("%d",&c);
                if (licznik<=c)
                {
                    printf ("Jest mniej elementów w tablicy\n");
                    break;
                }
                if (c<z)
                {
                    printf ("Wiersz pocz¹tkowy nie mo¿e byæ wiêkszy ni¿ koñcz¹cy\n");
                    break;
                }

                licznik=z;
                while (licznik<=c)
                {
                    printf ("%d %.2f %c\t %.2f %c\n",licznik,temp1[licznik],znak1[licznik],temp2[licznik],znak2[licznik]);
                    licznik++;
                }
            }
            break;
        case 15:
            {
            while (1)
            {
               int w;
               do
               {
               
               printf ("Który numer wiersza chcesz usun¹æ?\n");
               scanf ("%d",&w);
               }
               while (w>licznik||w<0);
               int i;
               for (i=w;i<licznik;i++)
               {
                   temp1[i]=temp1[i+1];
                   znak1[i]=znak1[i+1];
                   temp2[i]=temp2[i+1];
                   znak2[i]=znak2[i+1];
               }
                i--;
                licznik=0;
                while (licznik<20)
               {
                   if (znak1[licznik]==0)
                 {
                     break;
                 }
               else
                 {
                printf ("%d %.2f %c\t %.2f %c\n",licznik,temp1[licznik],znak1[licznik],temp2[licznik],znak2[licznik]);
                 }
                 licznik++;
               }
              printf ("Czy usun¹æ kolejny wiersz? Tak - wpisz 1, Nie - wpisz 2\n");
              int t;
              scanf ("%d",&t);
              if (t==1)
                continue;
              if (t==2)
                break;
            }
            }
             break;


         default:
          {
              printf ("Nie ma takiej liczby\n");
          }
      }

        if (licznik>19)
          {
              printf ("Tablica jest pe³na, kolejne przeliczenia nie bêd¹ zapisywane\n");
          }
        if(g==1)
          {
              printf("Nie ma takiej temperatury\n\n");
    
	      }
	  
   }
   else
     return 0;	
	  
  }
  return 0;
}
