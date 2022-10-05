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
	cout << "����������� ��������� � �������: " << dimension << endl;
	cout << "��������� ������: ";
	OutputArray(dimension, arr);
	do
	{
		cout << "1) �������� ������� � ����� �������" << endl
			<< "2) �������� ������� � ������ �������" << endl
			<< "3) �������� ������� �� k-�� ������� � �������" << endl
			<< "4) ������� ��������� ������� �������" << endl
			<< "5) ������� ������ ������� �������" << endl
			<< "6) ������� k-�� ������� �������" << endl
			<< "7) �������� ������� ������� ����� ������� ������������ �������� � �������� ���������" << endl
			<< "8) ������� ��� �������� ������� � �������� ���������, ���� ������ �������� ���" << endl
			<< "0) �����" << endl;
		cout << endl << "�������� ��������: ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			cout << "������� �����, ������� ����� �����������: "; 
			cin >> number;
			cout << endl;
			AddElements(arr, dimension, dimension, number);
			break;
		case 2:
			cout << "������� �����, ������� ����� �����������: ";
			cin >> number;
			cout << endl;
			AddElements(arr, dimension, 0, number);
			break;
		case 3:
			cout << "1) ���������" << endl
				<< "2) ����" << endl << endl
				<< "�������� ��������: ";
			cin >> keylocale;
			cout << endl;
			switch (keylocale)
			{
			case 1:
				cout << "������� �����, ������� ����� �����������: ";
				cin >> number;
				index = (rand() % (dimension - (0 + 1) + 0));
				cout << "��������� ������: " << index;
				cout << endl << endl;
				AddElements(arr, dimension, index, number);
				break;
			case 2:
				cout << "������� �����, ������� ����� �����������: ";
				cin >> number;
				cout << "������� ������ ����������� ��������: ";
				cin >> index;
				cout << endl;
				AddElements(arr, dimension, index, number);
				break;
			default:
				if (keylocale != 0)
				{
					cout << "������ �������� ��� !" << endl << endl;
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
			cout << "������� ������ ���������� ��������: ";
			cin >> index;
			cout << endl;
			DeleteElements(arr, dimension, index);
			break;
		case 7:
			cout << "������� �����, ������� ����� �����������: ";
			cin >> number;
			cout << "������� ����� ����� �������� ����� ��������� ������ �����: ";
			cin >> check_num;
			cout << endl;
			AddElementsAfter(arr, dimension, check_num, number);
			break;
		case 8:
			cout << "������� �����, ������� ����� �������: ";
			cin >> number;
			cout << endl;
			DeleteGivenElements(arr, dimension, number);
			break;
		default:
			if (key != 0)
			{
				cout << "������ �������� ��� !" << endl << endl;
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
		cout << "������ ! �� ����� �� ������� ������� !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "�������� ��������� !" << endl << endl;
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
		cout << "������ ! �� ����� �� ������� ������� !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "�������� ��������� !" << endl << endl;
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
		cout << "����� ����� � ������� ��� !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "�������� ��������� !" << endl << endl;
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
		cout << "����� ����� � ������� ��� !" << endl << endl;
	}
	else
	{
		OutputArray(dimension, arr);
		cout << "�������� ��������� !" << endl << endl;
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
		cout << "��������, ���� ���� ��� ���������� ! �������� ���� � ������������� ���������." << endl;
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