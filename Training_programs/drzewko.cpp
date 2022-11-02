// ConsoleApplication79.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct drzewo {
	int dane;
	drzewo *left;
	drzewo *right;
};

void funkcja(int n, drzewo korzen)
{
	if (n > korzen->dane)
	{
		if (korzen->right == NULL)
		{
			korzen->right = new drzewo;
			korzen->right->dane = n;
			korzen->right->right = NULL;
			korzen->right->left = NULL;
			return;
		}
		else
			funkcja(n, korzen->right);
	}
	if (n < korzen->dane)
	{
		if (korzen->left == NULL)
		{
			korzen->left = new drzewo;
			korzen->left->dane = n;
			korzen->left->right = NULL;
			korzen->left->left = NULL;
			return;
		}
		else
			funkcja(n, korzen->left);
	}
}


int main()
{
	int n,f;
	f = 0;
	int k = 1;
	drzewo *korzen = new drzewo;
	while (k == 1)
	{
		cout << "podaj liczbe";
		cin >>n;
		if (f == 0)
		{
			
			korzen->dane = n;
			korzen->right = NULL;
			korzen->left = NULL;

		}
		else
			funkcja(n, korzen);

		cout << "chcesz dodac?, tak to daj 1 ";
			cin >> k;
			f++;
	}
	cout << endl;
	cout << korzen->dane;
	cout << endl;
	cout << korzen->right->dane;
	cout << endl;
	cout << korzen->left->dane;
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
