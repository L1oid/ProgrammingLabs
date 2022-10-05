#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct PenInfo
{
	string pen;
	int price;
	double rating;
	int year;
	void Out();
	bool Seria(char*& data, int& n);
};

void PenInfo::Out()
{
	cout << "Pen: " << pen << "\t" << "Price: " << price << "\t" << "Rating: " << rating << "\t" << "Year: " << year << endl << endl;
}

bool PenInfo::Seria(char*& data, int& n)
{
	size_t s = pen.size();

	int n0 = sizeof(size_t);
	int n1 = s;
	int n2 = sizeof(int);
	int n3 = sizeof(double);
	int n4 = sizeof(int);

	n = n0 + n1 + n2 + n3 + n4;

	data = new char[n];

	char* d0 = reinterpret_cast<char*>(&s);
	char* d1 = const_cast<char*>(pen.c_str());
	char* d2 = reinterpret_cast<char*>(&price);
	char* d3 = reinterpret_cast<char*>(&rating);
	char* d4 = reinterpret_cast<char*>(&year);

	for (int i = 0; i < n0; i++) data[i] = d0[i];
	for (int i = 0; i < n1; i++) data[i + n0] = d1[i];
	for (int i = 0; i < n2; i++) data[i + n0 + n1] = d2[i];
	for (int i = 0; i < n3; i++) data[i + n0 + n1 + n2] = d3[i];
	for (int i = 0; i < n4; i++) data[i + n0 + n1 + n2 + n3] = d4[i];

	return true;
}

PenInfo DeSeria(char* data, int n)
{
	PenInfo temp;
	int n0, n1, n2, n3, n4;
	n0 = sizeof(size_t);
	n2 = sizeof(int);
	n3 = sizeof(double);
	n4 = sizeof(int);

	size_t s = *reinterpret_cast<size_t*>(data);
	n1 = s;

	string ss(data + n0, s);
	temp.pen = ss;
	temp.price = *reinterpret_cast<int*>(data + n0 + n1);
	temp.rating = *reinterpret_cast<double*>(data + n0 + n1 + n2);
	temp.year = *reinterpret_cast<int*>(data + n0 + n1 + n2 + n3);

	return temp;
}

struct MyQueue
{
	struct Node
	{
		int n;
		char* data;
		Node* next;
	};
	Node* First = NULL;
	string Top;
	int Count = 0;
	bool Push(char*, int);
	bool Pop(char*&, int&);
	void Info();
};

bool MyQueue::Push(char* data, int n)
{
	if (!First)
	{
		First = new Node;
		First->next = NULL;
		First->data = new char[n];
		for (int i = 0; i < n; i++)
		{
			First->data[i] = data[i];
		}
		First->n = n;
		Count = 1;
	}
	else
	{
		Node* temp;
		temp = First;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new Node;
		temp->next->next = NULL;
		temp->next->data = new char[n];
		for (int i = 0; i < n; i++)
		{
			temp->next->data[i] = data[i];
		}
		temp->next->n = n;
		Count++;
	}
	return true;
}

bool MyQueue::Pop(char*& data, int& n)
{
	if (!First) return false;
	Node* temp = First->next;
	n = First->n;
	data = new char[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = First->data[i];
	}
	delete First->data;
	delete First;
	First = temp;
	Count--;
	return true;
}

void MyQueue::Info()
{
	if (!First) cout << "Queue is empty" << endl << endl;
	else
	{
		cout << "Queue info: " << endl;
		cout << "Queue size = " << Count << endl << endl;
		cout << "First node:" << endl;
		cout << "Seria lenght = " << First->n << endl;
		PenInfo Info;
		Info = DeSeria(First->data, First->n);
		Info.Out();
	}
}

PenInfo DeSeria(char*, int);
void PrintBinaryFile(char*, int);
void ClearBinaryFile();
bool InputBinaryFile(MyQueue&);
void GetPen(MyQueue&, PenInfo&);
bool RemovePen(MyQueue&, PenInfo&);

void main()
{
	PenInfo Info;
	MyQueue Queue;
	int key = 0;
	char* data; int ssize;
	InputBinaryFile(Queue);
	do
	{
		cout << "1) Add product" << endl
			<< "2) Pull out product" << endl
			<< "3) Empty Cart" << endl
			<< "4) Cart Info" << endl
			<< "5) Seria Data" << endl
			<< "6) Clear File" << endl
			<< "0) Exit" << endl;
		cout << endl << "Select an action: ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			cout << "Enter the title: ";
			cin >> Info.pen;
			cout << endl;
			cout << "Enter the price: ";
			cin >> Info.price;
			cout << endl;
			cout << "Enter the rating: ";
			cin >> Info.rating;
			cout << endl;
			cout << "Enter the year: ";
			cin >> Info.year;
			cout << endl;
			Info.Seria(data, ssize);
			Queue.Push(data, ssize);
			Queue.Info();
			delete[] data;
			break;
		case 2:
			cout << "Enter the title: ";
			cin >> Info.pen;
			cout << endl;
			cout << "Enter the price: ";
			cin >> Info.price;
			cout << endl;
			cout << "Enter the rating: ";
			cin >> Info.rating;
			cout << endl;
			cout << "Enter the year: ";
			cin >> Info.year;
			cout << endl;
			RemovePen(Queue, Info);
			Queue.Info();
			break;
		case 3:
			while (Queue.Pop(data, ssize))
			{
				Info = DeSeria(data, ssize);
				Info.Out();
				delete[] data;
			}
			Queue.Info();
			break;
		case 4:
			Queue.Info();
			break;
		case 5:
			cout << "Enter the title: ";
			cin >> Info.pen;
			cout << endl;
			cout << "Enter the price: ";
			cin >> Info.price;
			cout << endl;
			cout << "Enter the rating: ";
			cin >> Info.rating;
			cout << endl;
			cout << "Enter the year: ";
			cin >> Info.year;
			cout << endl;
			Info.Seria(data, ssize);
			PrintBinaryFile(data, ssize);
			delete[] data;
			break;
		case 6:
			ClearBinaryFile();
			cout << "File is clear" << endl;
			break;
		default:
			if (key != 0)
			{
				cout << "There is no such action !" << endl << endl;
			}
			if (key == 0)
			{
				while (Queue.Pop(data, ssize))
				{
					delete[] data;
				}
				Queue.Info();
			}
			break;
		}
	} while (key != 0);
}

void PrintBinaryFile(char* data, int n)
{
	fstream out("out.dat", ios::app | ios::binary);
	out.write((char*)&n, sizeof(int));
	out.write(data, n);
	out.close();
}

void ClearBinaryFile()
{
	fstream out("out.dat", ios::out | ios::binary);
	out.close();
}

bool InputBinaryFile(MyQueue& Queue)
{
	fstream in("out.dat", ios::in | ios::binary);
	if (!in)
	{
		cout << "Error, there are no input binary file" << endl;
		return false;
	}

	int i = 1, n;
	PenInfo Info;

	while (!in.eof())
	{
		if (in.read((char*)&n, sizeof(int)))
		{
			cout << i << ")" << " Seria length: " << n << endl << endl;
			char* data = new char[n];
			in.read(data, n);
			i++;
			Queue.Push(data, n);
			Info = DeSeria(data, n);
			Info.Out();
			delete[] data;
		}
	}
	in.close();
	return true;
}

bool RemovePen(MyQueue& Queue, PenInfo& TempInfo)
{
	MyQueue QueueTemp;
	PenInfo Info;
	char* data = NULL;
	int n;
	bool stopFind = false, find = false;
	while (stopFind == false)
	{
		Info = DeSeria(Queue.First->data, Queue.First->n);
		if ((Info.pen == TempInfo.pen) && (Info.price == TempInfo.price) && (Info.rating == TempInfo.rating) && (Info.year == TempInfo.year))
		{
			Queue.Pop(data, n);
			find = true;
			stopFind = true;
			delete[] data;
			break;
		}
		QueueTemp.Push(Queue.First->data, Queue.First->n);
		Queue.Pop(data, n);
		delete[] data;
		if (Queue.First == NULL)
		{
			stopFind = true;
			break;
		}
	}
	if (find == true)
	{
		cout << endl << "Succesfuly remove pen!" << endl << endl;
	}
	else
	{
		cout << endl << "Can't find pen!" << endl << endl;
	}
	stopFind = false;
	while (stopFind == false)
	{
		if (find != true)
		{
			Queue.Push(QueueTemp.First->data, QueueTemp.First->n);
			QueueTemp.Pop(data, n);
			delete[] data;
		}
		find = false;
		if (QueueTemp.First == NULL) stopFind = true;
	}
	find = false;
	return true;
}