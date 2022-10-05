#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

float* MemoryArray(int count);
int DimensionFile();
void OutputArray(int dimension, float* arr);
void AddElements(float*& arr, int& dimension, int index, float number);
void AddElementsAfter(float*& arr, int& dimension, float check_num, float number);
void DeleteElements(float*& arr, int& dimension, int index);
void DeleteGivenElements(float*& arr, int& dimension, float number);

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int keylocale = 0, key = 0, dimension, index;
	float number, check_num;
	dimension = DimensionFile();
	float* arr = MemoryArray(dimension);
	cout << "Колличество элементов в массиве: " << dimension << endl;
	cout << "Стартовый массив: ";
	OutputArray(dimension, arr);
	do
	{
		cout << "1) добавить элемент в конец массива" << endl
			<< "2) добавить элемент в начало массива" << endl
			<< "3) добавить элемент на k-ую позицию в массиве" << endl
			<< "4) удалить последний элемент массива" << endl
			<< "5) удалить первый элемент массива" << endl
			<< "6) удалить k-ый элемент массива" << endl
			<< "7) добавить элемент массива после первого встреченного элемента с заданным значением" << endl
			<< "8) удалить все элементы массива с заданным значением, если такого значения нет" << endl
			<< "0) выход" << endl;
		cout << endl << "Выберите действие: ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			cout << "Задайте число, которое будет добавляться: "; 
			cin >> number;
			cout << endl;
			AddElements(arr, dimension, dimension, number);
			break;
		case 2:
			cout << "Задайте число, которое будет добавляться: ";
			cin >> number;
			cout << endl;
			AddElements(arr, dimension, 0, number);
			break;
		case 3:
			cout << "1) Рандомный" << endl
				<< "2) Свой" << endl << endl
				<< "Выберите действие: ";
			cin >> keylocale;
			cout << endl;
			switch (keylocale)
			{
			case 1:
				cout << "Задайте число, которое будет добавляться: ";
				cin >> number;
				index = (rand() % (dimension - (0 + 1) + 0));
				cout << "Рандомный индекс: " << index;
				cout << endl << endl;
				AddElements(arr, dimension, index, number);
				break;
			case 2:
				cout << "Задайте число, которое будет добавляться: ";
				cin >> number;
				cout << "Задайте индекс изменяемого элемента: ";
				cin >> index;
				cout << endl;
				AddElements(arr, dimension, index, number);
				break;
			default:
				if (keylocale != 0)
				{
					cout << "Такого действия нет !" << endl << endl;
				}
				break;
			}
			break;
		case 4:
			DeleteElements(arr, dimension, dimension - 1);
			break;
		case 5:
			DeleteElements(arr, dimension, 0);
			break;
		case 6:
			cout << "Задайте индекс удаляемого элемента: ";
			cin >> index;
			cout << endl;
			DeleteElements(arr, dimension, index);
			break;
		case 7:
			cout << "Задайте число, которое будет добавляться: ";
			cin >> number;
			cout << "Задайте число после которого будет добавлено другое число: ";
			cin >> check_num;
			cout << endl;
			AddElementsAfter(arr, dimension, check_num, number);
			break;
		case 8:
			cout << "Задайте число, которое нужно удалить: ";
			cin >> number;
			cout << endl;
			DeleteGivenElements(arr, dimension, number);
			break;
		default:
			if (key != 0)
			{
				cout << "Такого действия нет !" << endl << endl;
			}
			break;
		}
	} while (key != 0);
	delete[] arr;
	arr = nullptr;
	return 0;
}

float* MemoryArray(int dimension)
{
	float* arr = new float[dimension];
	ifstream f("Array.txt");
	for (int i = 0; i < dimension; i++)
	{
		f >> arr[i];
	}
	f.close();
	return arr;
}

void AddElements(float*& arr, int& dimension, int index, float number)
{
	bool exit = 0;
	if (index < 0 || index > dimension + 1)
	{
		exit = 0;
	}
	else
	{
		float* buff = new float[dimension + 1];
		for (int i = 0; i < index; i++)
		{
			buff[i] = arr[i];
		}
		buff[index] = number;
		for (int i = index + 1; i < dimension + 1; i++)
		{
			buff[i] = arr[i - 1];
		}
		exit = 1;
		delete[] arr;
		arr = buff;
		dimension += 1;
	}
	if (exit == 0)
	{
		cout << "Ошибка ! Вы вышли за пределы массива !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "Действие выполнено !" << endl << endl;
	}
}

void DeleteElements(float*& arr, int& dimension, int index)
{
	bool exit = 0;
	if (index < 0 || index >= dimension)
	{
		exit = 0;
	}
	else
	{
		float* buff = new float[dimension - 1];
		for (int i = 0; i < index; i++)
		{
			buff[i] = arr[i];
		}
		for (int i = index; i < dimension; i++)
		{
			buff[i] = arr[i + 1];
		}
		exit = 1;
		delete[] arr;
		arr = buff;
		dimension -= 1;
	}
	if (exit == 0)
	{
		cout << "Ошибка ! Вы вышли за пределы массива !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "Действие выполнено !" << endl << endl;
	}
}

void AddElementsAfter(float*& arr, int& dimension, float check_num, float number)
{
	bool exit = 0;
	for (int i = 0; i < dimension; i++)
	{
		if (arr[i] == check_num)
		{
			int index = 0;
			float* buff = new float[dimension + 1];
			for (int i = 0, j = 0; i < dimension; i++, j++)
			{
				buff[j] = arr[i];
				if (arr[i] == check_num)
				{
					buff[j + 1] = number;
					break;
				}
				index++;
			}
			for (; index < dimension; index++)
			{
				buff[index + 2] = arr[index + 1];
			}
			exit = 1;
			delete[] arr;
			arr = buff;
			dimension += 1;
			break;
		}
	}
	if (exit == 0)
	{
		cout << "Такой цифры в массиве нет !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "Действие выполнено !" << endl << endl;
	}
}

void DeleteGivenElements(float*& arr, int& dimension, float number)
{
	int count = 0;
	bool exit = 0;
	for (int i = 0; i < dimension; i++)
	{
		if (arr[i] == number)
		{
			int index = 0;
			float* buff = new float[dimension];
			for (int i = 0, j = 0; i < dimension; i++, j++)
			{
				buff[j] = arr[i];
				if (arr[i] == number)
				{
					while (arr[i] == arr[i + 1])
					{
						i++;
						count++;
					}
					buff[j] = arr[i + 1];
					count++;
					i++;
				}
			}
			dimension -= count;
			exit = 1;
			delete[] arr;
			arr = buff;
			break;
		}
	}
	if (exit == 0)
	{
		cout << "Такой цифры в массиве нет !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "Действие выполнено !" << endl << endl;
	}
}

int DimensionFile()
{
	ifstream f("Array.txt");
	float check;
	int count = 0;
	while (f >> check)
	{
		count++;
	}
	f.close();
	if (count == 0)
	{
		cout << "Внимание, файл пуст или отсутсвует ! Замените файл и перезапустите программу." << endl;
		exit(0);
	}
	else return count;
}

void OutputArray(int dimension, float* arr)
{
	for (int i = 0; i < dimension; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}