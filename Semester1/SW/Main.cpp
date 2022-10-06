#include <iostream>
#include <fstream>
#include <ctime>
#define MAX_N 10000
using namespace std;

int GetN();
void AlmostOrderedArray(int[], int);
void PoorlyOrderedArray(int[], int);
void RandomNumbersArray(int[], int);
void FirstInclusionSort(int[], int);
void SecondInclusionSort(int[], int);
void ThirdInclusionSort(int[], int);
void FirstShellSort(int[], int);
void SecondShellSort(int[], int);
void ThirdShellSort(int[], int);
int Comp(int, int, int&);

int main()
{
	setlocale(LC_ALL, "ru");
	int key;
	int FirstArray[MAX_N], SecondArray[MAX_N], ThirdArray[MAX_N];
	int n;
	cout << "Введите размерность: ";
	n = GetN();
	cout << "1)Сортировка прямым включением первого массива" << endl
		<< "2)Сортировка прямым включением второго массива" << endl
		<< "3)Сортировка прямым включением третьего массива" << endl
		<< "-----------------------------------------------" << endl
		<< "4)Сортировка Шелла первого массива" << endl
		<< "5)Сортировка Шелла второго массива" << endl
		<< "6)Сортировка Шелла третьего массива" << endl
		<< "Выберите действие: ";
	do
	{
		cin >> key;
		switch (key)
		{
		case 1:
			AlmostOrderedArray(FirstArray, MAX_N);
			FirstInclusionSort(FirstArray, n);
			cout << "Сортировка первого массива закончена!" << endl;
			break;
		case 2:
			PoorlyOrderedArray(SecondArray, MAX_N);
			SecondInclusionSort(SecondArray, n);
			cout << "Сортировка второго массива закончена!" << endl;
			break;
		case 3:
			RandomNumbersArray(ThirdArray, MAX_N);
			ThirdInclusionSort(ThirdArray, n);
			cout << "Сортировка третьего массива закончена!" << endl;
			break;
		case 4:
			AlmostOrderedArray(FirstArray, MAX_N);
			FirstShellSort(FirstArray, n);
			cout << "Сортировка первого массива закончена!" << endl;
			break;
		case 5:
			PoorlyOrderedArray(SecondArray, MAX_N);
			SecondShellSort(SecondArray, n);
			cout << "Сортировка второго массива закончена!" << endl;
			break;
		case 6:
			RandomNumbersArray(ThirdArray, MAX_N);
			ThirdShellSort(ThirdArray, n);
			cout << "Сортировка третьего массива закончена!" << endl;
			break;
		default:
			if (key != 0)
			{
				cout << "Вы ввели неверный номер! Выберите действие: ";
			}
			break;
		}
	} while (key != 0);
}

int GetN()
{
	int n;
	do
	{
		cin >> n;
		if (n < 10 || n - (int)n != 0 || n > MAX_N)
			cout << "Ошибка! Введите другое число: ";
	} while (n < 10 || n - (int)n != 0 || n > MAX_N);
	return n;
}

void AlmostOrderedArray(int arr[], int n)
{
	ifstream f("FirstArray.txt");
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
}

void PoorlyOrderedArray(int arr[], int n)
{
	ifstream f("SecondArray.txt");
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
}

void RandomNumbersArray(int arr[], int n)
{
	ifstream f("ThirdArray.txt");
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		f >> arr[i];
	}
	f.close();
}

void FirstInclusionSort(int arr[], int n)
{
	unsigned int start_time = clock();
	int count = 0, m = 0;
	for (int i = 1; i < n; i++)
	{
		int value = arr[i];
		m++;
		int index = i;
		while ((index > 0) && Comp(arr[index - 1], value, count))
		{
			m++;
			arr[index] = arr[index - 1];
			index--; 
		}
		arr[index] = value;
		m++;
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	ofstream f("InclusionAssortedFirstArray.txt");
	f << "C = " << count << endl;
	f << "M = " << m << endl;
	f << "N = " << n << endl;
	f << "Time = " << search_time << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}

void SecondInclusionSort(int arr[], int n)
{
	unsigned int start_time = clock();
	int count = 0, m = 0;
	for (int i = 1; i < n; i++)
	{
		int value = arr[i];
		m++;
		int index = i;
		while ((index > 0) && Comp(arr[index - 1], value, count))
		{
			m++;
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = value;
		m++;
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	ofstream f("InclusionAssortedSecondArray.txt");
	f << "C = " << count << endl;
	f << "M = " << m << endl;
	f << "N = " << n << endl;
	f << "Time = " << search_time << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}

void ThirdInclusionSort(int arr[], int n)
{
	unsigned int start_time = clock();
	int count = 0, m = 0;
	for (int i = 1; i < n; i++)
	{
		int value = arr[i];
		m++;
		int index = i;
		while ((index > 0) && Comp(arr[index - 1], value, count))
		{
			m++;
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = value;
		m++;
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	ofstream f("InclusionAssortedThirdArray.txt");
	f << "C = " << count << endl;
	f << "M = " << m << endl;
	f << "N = " << n << endl;
	f << "Time = " << search_time << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}

void FirstShellSort(int arr[], int n)
{
	unsigned int start_time = clock();
	int step, i, j, tmp;
	int m = 0, count = 0;
	// Выбор шага
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && Comp(arr[j], arr[j + step], count); j -= step)
			{
				m = m + 3;
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	ofstream f("ShellAssortedFirstArray.txt");
	f << "C = " << count << endl;
	f << "M = " << m << endl;
	f << "N = " << n << endl;
	f << "Time = " << search_time << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}

void SecondShellSort(int arr[], int n)
{
	unsigned int start_time = clock();
	int step, i, j, tmp;
	int m = 0, count = 0;
	// Выбор шага
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && Comp(arr[j], arr[j + step], count); j -= step)
			{
				m = m + 3;
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	ofstream f("ShellAssortedSecondArray.txt");
	f << "C = " << count << endl;
	f << "M = " << m << endl;
	f << "N = " << n << endl;
	f << "Time = " << search_time << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}

void ThirdShellSort(int arr[], int n)
{
	unsigned int start_time = clock();
	int step, i, j, tmp;
	int m = 0, count = 0;
	// Выбор шага
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && Comp(arr[j], arr[j + step], count); j -= step)
			{
				m = m + 3;
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	ofstream f("ShellAssortedThirdArray.txt");
	f << "C = " << count << endl;
	f << "M = " << m << endl;
	f << "N = " << n << endl;
	f << "Time = " << search_time << endl;
	for (int i = 0; i < n; i++)
	{
		f << arr[i] << endl;
	}
	f.close();
}

int Comp(int a, int b, int &count)
{
	bool c = false;
	if (a > b)
	{
		c = true;
	}
	count++;
	return c;
}