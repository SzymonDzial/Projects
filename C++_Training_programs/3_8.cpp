// 3_8.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>



void erystos(int n, std::vector<int>* v)
{
    (*v).clear();
    if (n != 0)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % (i) == 0)
                v->push_back(i);

        }

        for (int i = 0; i < (*v).size(); i++)
        {
            for (int j = i + 1; j < (*v).size(); j++)
            {
                if ((*v)[j] % (*v)[i] == 0)
                {
                    v->erase((*v).begin() + j);                  
                    j--;
                }
            }
        }

    }
    else
        (*v).clear();
    std::cout << "liczba " << n << std::endl;
    for (int i = 0; i < (*v).size(); i++)
        std::cout << "dzielnik jej " << (*v)[i] << std::endl;
}


void jest_czy_nie(int indeks, std::vector<int>* vn, std::vector<int>* v)
{
    std::cout << "Jedziemy tutej" << std::endl;
    if (indeks == (*vn).size() - 1)
        std::cout << "UDALO SIE" << std::endl;
    else if (indeks < (*vn).size() - 1)
    {
        //sprawdzenie jakie są liczby pierwsze danej liczby
        erystos((*vn)[indeks], v);
        for (int i = 0; i < (*v).size(); i++)
            jest_czy_nie(indeks + (*v)[i], vn, v);
       
    }
}

int main()
{
    int a;
    int n;
    std::vector<int>* vn = new std::vector<int>();
    std::cout << "wpisz n\n";
    std::cin >> n;
    int max;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        
        a = rand() % 100;
        std::cout << a << std::endl;
        (*vn).push_back(a);
       
    }
    


    std::cout << std::endl;
    std::vector<int>* v = new std::vector<int>();
    jest_czy_nie(0,vn,v);
   



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
