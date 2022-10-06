#include <iostream>
#define _USE_MATH_DEFINES
#define MAX_N 100
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int NaturalGetN();
void SizeArr(int&);
void OutputArr(double[], int);
void RandArr(double[], int);
double MaxArr(double[], int, int&);
double MinArr(double[], int, int&);
void Swap(double[], double, int, double, int);
void CountDiff(double[], int, double count[][2]);
void NormDiff(int, double arr[][2]);
void OutputArrDiff(int, double arr[][2]);
void SumToNeg(double[], int);
void Сompression(int, double[], double, double);

int main()
{
	setlocale(LC_ALL, "ru");
	double arr[MAX_N], count[MAX_N][2], MaxNum, MinNum, A, B;
	int n, MaxI, MinI, key = 0;
	SizeArr(n);
	RandArr(arr, n);
	cout << "Начальный массив: " << endl;
	OutputArr(arr, n);
	do
	{
		cout << endl << "Выберите задание(9 - заполнение массива другими числами, 0 - выход): ";
		cin >> key;
		switch (key)
		{
		case 9:
			SizeArr(n);
			RandArr(arr, n);
			cout << "Начальный массив: " << endl;
			OutputArr(arr, n);
			break;
		case 1:
			cout << "Максимальный элемент массива: " << MaxArr(arr, n, MaxI) << endl;
			cout << "Минимальный элемент массива: " << MinArr(arr, n, MinI) << endl;
			break;
		case 2:
			MaxNum = MaxArr(arr, n, MaxI);
			MinNum = MinArr(arr, n, MinI);
			Swap(arr, MaxNum, MaxI, MinNum, MinI);
			cout << "Изменённый массив:" << endl;
			OutputArr(arr, n);
			break;
		case 3:
			CountDiff(arr, n, count);
			NormDiff(n, count);
			OutputArrDiff(n, count);
			break;
		case 4:
			cout << "Максимальный элемент массива: " << MaxArr(arr, n, MaxI) << endl;
			SumToNeg(arr, n);
			OutputArr(arr, n);
			cout << "Введите A: ";
			A = NaturalGetN();
			cout << "Введите B: ";
			B = NaturalGetN();
			Сompression(n, arr, A, B);
			OutputArr(arr, n);
			break;
		default:
			if (key != 0)
			{
				cout << "Такого задания нет !" << endl;
			}
			break;
		}
	} while (key != 0);
}

int NaturalGetN()
{
	float n;
	do
	{
		cin >> n;
		if (n < 0 || n - (int)n != 0 || n > INT_MAX)
			cout << "Ошибка! Введите другое число: ";
	} while (n < 0 || n - (int)n != 0 || n > INT_MAX);
	return n;
}

void SizeArr(int &n)
{
	do 
	{
		cout << "Введите размер массива: ";
		cin >> n;
		if (n <= 0 || n > MAX_N || (n - (int)n)) 
		{
			cout << "Ошибка, попробуйте снова." << endl;
		}
	} while (n <= 0 || n > MAX_N || (n - (int)n));
}

void OutputArr(double arr[], int n)
{
	for (int i = 0; i < n; i++) cout << "[" << i << "] " << arr[i] << endl;
	cout << endl;
}

void RandArr(double arr[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() % (100 - (-100) + 1) + (-100)) / (float)(rand() % 10 + 1);
	}
}

double MaxArr(double arr[], int n, int &NumI)
{
	double maxNum = INT_MIN;
	NumI = 0;
	for (int i = 0; i < n; ++i)
	{
		if (maxNum < arr[i])
		{
			maxNum = arr[i];
			NumI = i;
		}
	}
	return maxNum;
}

double MinArr(double arr[], int n, int &NumI)
{
	double minNum = INT_MAX;
	NumI = 0;
	for (int i = 0; i < n; ++i)
	{
		if (minNum > arr[i])
		{
			minNum = arr[i];
			NumI = i;
		}
	}
	return minNum;
}

void Swap(double arr[], double MaxNum, int MaxI, double MinNum, int MinI)
{
	arr[MaxI] = MinNum;
	arr[MinI] = MaxNum;
}

void CountDiff(double arr[], int n, double count[][2])
{
	int counter = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i] == arr[j] && i != j)
			{
				counter++;
			}
		}
		count[i][0] = arr[i];
		count[i][1] = counter;
		counter = 1;
	}
}

void NormDiff(int n, double arr[][2])
{
	for (int j = 0; j < n; ++j)
	{
		for (int i = j; i < n; ++i)
		{
			if (arr[i][0] == arr[j][0] && i != j)
			{
				arr[j][1] = 0;
			}
		}
	}
}

void OutputArrDiff(int n, double arr[][2])
{
	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i][1] != 0)
		{
			counter++;
			cout << "Число: " << "[" << i << "] " << arr[i][0] << " встречается " << arr[i][1] << " раз" << endl;
		}
	}
	cout << endl << "Всего уникальных элементов: " << counter << endl;
}

void SumToNeg(double arr[], int n)
{
	double sum = 0;
	int k = n;
	while (arr[k] < 0)
	{
		k--;
	}
	for (int i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	cout << "Сумма элементов до последнего положительного элемента равна: " << sum << endl;
}

void Сompression(int n, double arr[], double A, double B)         //Сжатие массива
{
	cout << "Сжатие массива:" << endl;
	int i = 0;
	int m = n;
	while (i < m)
	{
		if (abs(arr[i]) <= B && abs(arr[i]) >= A)
		{
			m -= 1;
			for (int j = i; j < m; j++)
			{
				arr[j] = arr[j + 1];
			}
		}
		else i += 1;
	}
	for (i = m; i < n; i++) arr[i] = 0;
}