// ConsoleApplication73.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include <iostream>
#include<iomanip>
using namespace std;

void pirwszy(int tab[], int n)
{

	int j;
	for (int i = 1; i < n; i++)
	{
		int pom = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = pom;
	}
}


void drugi(int tab[], int n)
{
	int i, j, pom;
	for (i = 0; i < n; i++)
	{

		for (j = i + 1; j < n; j++)
		{
			if (tab[i] > tab[j])
			{
				pom = tab[j];
				tab[j] = tab[i];
				tab[i] = pom;
			}
		}
	}
}

void kopiec(int tab[], int n)
{
	int pom;
	for (int i = n; i > 0; i--)
	{
		tab[i] = tab[i - 1];

	}
	int i, j, k;
	for (i = 2; i <= n; i++)
	{
		j = i; k = j / 2;
		pom = tab[i];
		while (k > 0 && tab[k] < pom)
		{
			tab[j] = tab[k];
			tab[k] = pom;
			j = k; k = j / 2;
		}

	}



}

void szybki(int tab[], int lewy, int prawy)
{
	int div = 2;
	int i = lewy;
	int j = prawy;
	int pom = tab[int((lewy + prawy) / 2)];
	do
	{
		while (tab[i] < pom)
			i++;
		while (tab[j] > pom)
			j--;
		if (i <= j)
		{
			swap(tab[i], tab[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (lewy < j)
		szybki(tab, lewy, j);
	if (prawy > i)
		szybki(tab, i, prawy);

}

int main()
{
	int i; int n;
	cout << "podaj n ";
	cin >> n;
	int tab[50];
	for (i = 0; i < n; i++) tab[i] = rand() % 100;
	for (i = 0; i < n; i++) cout << setw(4) << tab[i];
	cout << endl;
	pirwszy(tab, n);
	for (i = 0; i < n; i++) cout << setw(4) << tab[i];
	cout << endl;
	cout << "podaj n ";
	cin >> n;

	for (i = 0; i < n; i++) tab[i] = rand() % 100;
	for (i = 0; i < n; i++) cout << setw(4) << tab[i];
	cout << endl;
	drugi(tab, n);
	for (i = 0; i < n; i++) cout << setw(4) << tab[i];
	cout << endl;

	cout << endl;
	cout << "podaj n ";
	cin >> n;

	for (i = 0; i < n; i++) tab[i] = rand() % 100;
	for (i = 0; i < n; i++) cout << setw(4) << tab[i];
	cout << endl;
	szybki(tab, 0, n - 1);
	for (i = 0; i < n; i++) cout << setw(4) << tab[i];
	cout << endl;

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
