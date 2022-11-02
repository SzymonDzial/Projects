// erystos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

void erystos(int n, std::vector<int>* v)
{

    if (n != 0)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % (i) == 0)
                v->push_back(i);

        }
        for (int i = 0; i < (*v).size(); i++)
            std::cout << (*v)[i] << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < (*v).size(); i++)
        {
            for (int j = i + 1; j < (*v).size(); j++)
            {
                if ((*v)[j] % (*v)[i] == 0)
                {
                    v->erase((*v).begin() + j);
                    std::cout << "xxx" << std::endl;
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

        a = rand() % 20;
        std::cout << a << std::endl;
        (*vn).push_back(a);
        
    }



    std::cout << std::endl;
    std::vector<int>* v = new std::vector<int>();
    erystos(1, v);




    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
