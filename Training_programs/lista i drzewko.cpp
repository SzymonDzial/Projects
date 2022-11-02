// ConsoleApplication83.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


#include <iostream>
#include <cstdlib>  
#include <time.h> 
using namespace std;

struct drzewo {
	int dane;
	drzewo* left;
	drzewo* right;
};
struct lista
{
	int dane;
	lista* next;
};
void wpisz(int n, drzewo* korzen)
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
			wpisz(n, korzen->right);
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
			wpisz(n, korzen->left);
	}
}

void wypisz(drzewo* temp)
{
	if (temp == NULL)
		return;
	wypisz(temp->left);
	cout << temp->dane << " ";
	wypisz(temp->right);
}


int main()
{
	srand(time(NULL));
	int ciag[100], n;
	cout << "daj dlugosc ciagu n, taki do 100";
	cin >> n;
	int i = 0;
	while (i < n)
	{
		ciag[i] = rand() % 99;
		for (int j = 0; j < i; j++)
		{
			if (ciag[j] == ciag[i])
				i--;
		}
		i++;
	}
	for (i = 0; i < n; i++)
	{
		cout << ciag[i] << " ";
	}
	cout << endl << endl;

	lista* head, * temp, * now, * tail, * cyk;
	int v, k;
	k = 1;
	head = new lista;
	head->next = new lista;
	head->next->next = NULL;
	head->next->dane = ciag[0];
	tail = head->next;
	tail->next = NULL;
	for (int i = 1; i < n; i++)
	{
		temp = new lista;
		now = new lista;
		temp->dane = ciag[i];

		if (ciag[i] < head->next->dane)
		{
			temp->next = head->next;
			head->next = temp;
		}
		if (ciag[i] > tail->dane)
		{
			tail->next = temp;
			temp->next = NULL;
			tail = tail->next;
		}
		if ((ciag[i] > head->next->dane) && (ciag[i] < tail->dane))
		{
			now = head->next;
			while (now->next->dane < ciag[i])
			{
				now = now->next;
			}
			temp->next = now->next;
			now->next = temp;
		}
	}
	now = head->next;
	for (int j = 0; j < n; j++)
	{
		cout << now->dane << " ";
		now = now->next;
	}



	int f;
	f = 0;
	k = 1;
	drzewo* korzen = new drzewo;
	for (i = 0; i < n; i++)
	{

		if (f == 0)
		{

			korzen->dane = ciag[i];
			korzen->right = NULL;
			korzen->left = NULL;

		}
		else
			wpisz(ciag[i], korzen);


		f++;
	}

	cout << endl << endl;
	wypisz(korzen);





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
