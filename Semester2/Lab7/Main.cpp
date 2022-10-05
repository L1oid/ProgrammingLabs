#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void InitMatr(int**&, int&);
void PrintMatr(int**&, int&);
void PrintResults(int*&, int*&, int&, int&, int&);
void Deixtra(int**&, int*&, int*&, int*&, int&, int&, int&, int&);

int main()
{
    setlocale(LC_ALL, "ru");
    int** matr;
    int* distance;
    int* tops;
    int* shortcut;
    int size;
    int k = 1;
    int begin_index = 0; //����� �� ������� ����������� ���������� (������� - 1)
    int end;
    cout << "������� ������� �� ������� ����� ����� ���������� �������: ";
    cin >> end;
    end = end - 1;
    int end1 = end;
    InitMatr(matr, size);
    PrintMatr(matr, size);
    Deixtra(matr, distance, tops, shortcut, size, k, begin_index, end);
    PrintResults(shortcut, distance, size, k, end1);
}

void InitMatr(int**& matr, int &size)
{
    ifstream f("MatrixInput.txt");
    int count = 0;
    while (!f.eof())
    {
        int temp;
        f >> temp;
        count++;
    }
    count = sqrt(count);
    size = count;
    f.seekg(0);
    matr = new int* [size];
    for (int i = 0; i < size; i++)
    {
        matr[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            f >> matr[i][j];
        }
    }
    f.close();
}

void PrintMatr(int**& matr, int& size)
{
    cout << "�������:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(5) << matr[i][j];
        }
        cout << endl;
    }
}

void PrintResults(int*& shortcut, int*& distance, int& size, int& k, int& end)
{
    ofstream f("MatrixOuput.txt");
    cout << "���������� ���������� �� ������:" << endl;
    f << "���������� ���������� �� ������:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "�������" << "[" << i + 1 << "]" << " " << distance[i] << endl;
        f << "�������" << "[" << i + 1 << "]" << " " << distance[i] << endl;
    }
    cout << endl;
    cout << "���������� ���� �� 1 �� " << end + 1 << endl;
    f << endl;
    f << "���������� ���� �� 1 �� " << end + 1 << endl;
    for (int j = k - 1; j >= 0; j--)
    {
        cout << setw(5) << shortcut[j];
        f << " " << shortcut[j];
    }
    f.close();
}

void Deixtra(int**& matr, int*& distance, int*& tops, int*& shortcut, int& size, int& k, int& begin_index, int& end)
{
    int temp, minindex, min;
    distance = new int[size];
    tops = new int[size];
    shortcut = new int[size];
    for (int i = 0; i < size; i++)
    {
        distance[i] = 10000;
        tops[i] = 1;
    }
    distance[begin_index] = 0;
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < size; i++)
        {
            if ((tops[i] == 1) && (distance[i] < min))
            {
                min = distance[i];
                minindex = i;
            }
        }
        if (minindex != 10000)
        {
            for (int i = 0; i < size; i++)
            {
                if (matr[minindex][i] > 0)
                {
                    temp = min + matr[minindex][i];
                    if (temp < distance[i])
                    {
                        distance[i] = temp;
                    }
                }
            }
            tops[minindex] = 0;
        }
    } while (minindex < 10000);
    shortcut[0] = end + 1;
    int weight = distance[end];
    while (end != begin_index)
    {
        for (int i = 0; i < size; i++)
        {
            if (matr[i][end] != 0)
            {
                int temp = weight - matr[i][end];
                if (temp == distance[i])
                {
                    weight = temp;
                    end = i;
                    shortcut[k] = i + 1;
                    k++;
                }
            }
        }
    }
}