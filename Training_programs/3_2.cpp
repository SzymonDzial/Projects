// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>

int fun(int x, int y)
{
    std::string xs = std::to_string(x);
    std::string ys = std::to_string(y);
    std::vector<char> vx(xs.begin(), xs.end());
    std::vector<char> vy(ys.begin(), ys.end());
    int zwrot = 0;
    
    if (vx.size() == vy.size())
    {
    int k = 0;
    int kk = vx.size();
        for (int i = 0; i < vx.size(); i++)
        {
          
            for (int j = 0; j < vy.size(); j++)
            {
                
                if (vx[i] == vy[j])
                {
                    vy.erase(vy.begin() + j);
                    k++;
                }
            }
        }
        if (k == kk)
            zwrot = 1;
    }
    return zwrot;
}


int main()
{
    int x;
    int y;
    std::cout << "wpisz x potem y\n";
    std::cin >> x;
    std::cin >> y;
    int a = fun(x, y);
    std::cout << a;
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
