


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

// Porady dotycz??ce rozpoczynania pracy:
//   1. U??yj okna Eksploratora rozwi??za??, aby doda?? pliki i zarz??dza?? nimi
//   2. U??yj okna programu Team Explorer, aby nawi??za?? po????czenie z kontrol?? ??r??d??a
//   3. U??yj okna Dane wyj??ciowe, aby sprawdzi?? dane wyj??ciowe kompilacji i inne komunikaty
//   4. U??yj okna Lista b????d??w, aby zobaczy?? b????dy
//   5. Wybierz pozycj?? Projekt > Dodaj nowy element, aby utworzy?? nowe pliki kodu, lub wybierz pozycj?? Projekt > Dodaj istniej??cy element, aby doda?? istniej??ce pliku kodu do projektu
//   6. Aby w przysz??o??ci ponownie otworzy?? ten projekt, przejd?? do pozycji Plik > Otw??rz > Projekt i wybierz plik sln
