


#include <iostream>
#include<math.h>
#include<ctime>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

struct wierzch
{
	int liczba;
	int visited;
};

void dfs_macierz(int wizytka[], vector<int> wezel, vector<vector<int> >macierz, int nr)
{
	
	if(wizytka[nr]==0)
	{
		wizytka[nr] = 1;
		cout << wezel[nr] << "  ";
		for (int i = 0; i < macierz[nr].size(); i++)
		{
			if (macierz[nr][i] == 1)
				dfs_macierz(wizytka, wezel, macierz, i);
		}
	}
}

void Wszerz_macierz(int wizytka[], vector<int> wezel, vector<vector<int> >macierz, int pierwszy)
{
	int t=0;
	queue < int > kolejka;
	kolejka.push(pierwszy);
	while (!kolejka.empty())
	{
		t=kolejka.front();
		for (int i = 0; i < macierz[t].size(); i++)
		{
			if (macierz[t][i] == 1&& wizytka[i]==0)
			{
				kolejka.push(i);
				wizytka[i] = 1;
			}
		}
		cout << wezel[ kolejka.front()] << "  ";
		kolejka.pop();
	}
	
}


int main()
{
	srand(time(NULL));
	int n;
	cout << "Podaj ilosc wezlow ";
	cin >> n;
	vector<int>wierzch;
	int k;
	int i;
	for (i = 0; i < n; i++)
	{
		k = rand() % 100;
		wierzch.push_back(k);
	}

	i = 0;
	for (i = 0; i < wierzch.size(); i++)
	{
		cout << wierzch[i] << endl;

	}

	vector < vector < int > > macsas(n, vector<int>(n));
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (j > i)
				macsas[i][j] = 1;
			else
				macsas[i][j] = 0;
	}

	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << macsas[i][j] << "   ";

		cout << endl;
	}
	int j;
	vector< vector<int> >listsas;


	for (i = 0; i < n; i++)
	{
		vector<int>temp;
		for (j = i + 1; j < n; j++)
		{
			temp.push_back(j);
		}
		listsas.push_back(temp);
	}

	for (i = 0; i < n; i++)
	{

		for (int j = 0; j < listsas[i].size(); j++)
		{
			cout << listsas[i][j] << "  ";
		}
		cout << endl;

	}

	int wizytka[50];
	for (i = 0; i < n; i++)
		wizytka[i] = 0;

	int pierwszy = 0;

	dfs_macierz(wizytka, wierzch, macsas, pierwszy);
	cout << endl << endl;

	for (i = 0; i < n; i++)
		wizytka[i] = 0;


	pierwszy = 0;
	Wszerz_macierz(wizytka, wierzch, macsas, pierwszy);
	

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
