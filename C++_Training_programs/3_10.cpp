// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    int a;
    int n;
    std::vector<int>v;
    std::cout << "wpisz n\n";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        a = rand()%5;
        std::cout << a<<std::endl;
        v.push_back(a);
       // v.push_back(i);
    } 

    int k = 0;
    int kk = 0;
    int indeks;
    int roznica;
    for (int i = 0; i < n-1; i++)
    {   if (i==0)
        {
            roznica = v[i + 1] - v[i];
            indeks = 0;
        }
        else
        {

            if (roznica == v[i + 1] - v[i])
            {
                k++;
                if (k > kk)
                {
                    kk = k;
                    indeks = i;

                }
            }
            else
                k = 0;

            
            roznica = v[i + 1] - v[i];
        }
    }
    int dlugosc = kk + 2;
    int indeksik = indeks + 1;
    std::cout <<std::endl;
    std::cout << std::endl;
    std::cout << dlugosc << std::endl;
    std::cout << indeksik;
    std::cout << std::endl;
    std::cout << std::endl;



    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
