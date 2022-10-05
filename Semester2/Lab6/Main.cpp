#include <iostream>
#include <fstream>
using namespace std;

struct AutoInfo
{
	string name;
	int price;
	string color;
	double rating;
	void Out();
};

struct Tree
{
	AutoInfo data;
	Tree* left; 
	Tree* right;
};

int GetTreeSize(Tree* T)
{
	if (!T)
	{
		return 0;
	}
	if (!T->left && !T->right)
	{
		return 1;
	}
	int left = 0, right = 0; 
	if (T->left)
	{
		left = GetTreeSize(T->left);
	}
	if (T->right)
	{
		right = GetTreeSize(T->right);
	}
	return left + right + 1;
}

void Add(Tree*& T, AutoInfo data, int type)
{
	if (!T)
	{
		T = new Tree; 
		T->data = data; 
		T->left = NULL; 
		T->right = NULL; 
		return;
	}
	if (type == 0)
	{
		if (data.name < T->data.name)
		{
			Add(T->left, data, 0);
		}
		else
		{
			Add(T->right, data, 0);
		}
	}
	else if (type == 1)
	{
		if (data.price < T->data.price)
		{
			Add(T->left, data, 1);
		}
		else
		{
			Add(T->right, data, 1);
		}
	}
}

void PrintLRR(Tree* T, ofstream& SF)
{
	if (!T)
	{
		return;
	}
	PrintLRR(T->left, SF);
	T->data.Out();
	SF << T->data.name << " " << T->data.price << " " << T->data.color << " " << T->data.rating << endl;
	PrintLRR(T->right, SF);
}

void SelectionPrintLRR(Tree* T, AutoInfo Info, int type)
{
	if (!T)
	{
		return;
	}
	SelectionPrintLRR(T->left, Info, type);
	if (type == 0)
	{
		if (T->data.name[0] == Info.name[0])
		{
			T->data.Out();
		}
	}
	else if (type == 1)
	{
		if (T->data.price < Info.price)
		{
			T->data.Out();
		}
	}
	SelectionPrintLRR(T->right, Info, type);
}

Tree* Search(Tree*& T, AutoInfo data)
{
	if (!T)
	{
		return NULL;
	}
	while (T->data.price != data.price)
	{
		if (data.price < T->data.price)
		{
			T = T->left;
		}
		else
		{
			T = T->right;
		}
		if (!T)
		{
			break;
		}
	}
	return T;
}

void Delete(Tree*& T)
{
	if (T)
	{
		if (T->left)
		{
			Delete(T->left);
		}
		if (T->right)
		{
			Delete(T->right);
		}
		delete T; 
		T = NULL;
	}
	else
	{
		cout << "Tree is empty" << endl << endl;
	}
}

void AutoInfo::Out()
{
	cout << "Auto: " << name << "\t\t" << "Price: " << price << "\t" << "Color: " << color << "\t" << "Rating: " << rating << endl << endl;
}

bool FileAdd(Tree*&, int);

int main()
{
	ofstream SF;
	Tree* T = NULL;
	AutoInfo Info;
	char symbol = '0';
	int key = 0;
    do
    {
        cout << "1) Sort by string field" << endl
            << "2) Sort by numeric field" << endl
            << "3) Information up to a given numerical value" << endl
            << "4) Information up to a given symbol" << endl
            << "0) Exit" << endl;
        cout << endl << "Select an action: ";
        cin >> key;
        cout << endl;
        switch (key)
        {
        case 1:
			SF.open("SortAuto.txt");
			FileAdd(T, 0);
			PrintLRR(T, SF);
			cout << "Tree size = " << GetTreeSize(T) << endl << endl;
			Delete(T);
			SF.close();
            break;
        case 2:
			SF.open("SortAuto.txt");
			FileAdd(T, 1);
			PrintLRR(T,SF);
			cout << "Tree size = " << GetTreeSize(T) << endl << endl;
			Delete(T);
			SF.close();
            break;
        case 3:
			cout << "Enter the car price: ";
			cin >> Info.price;
			cout << endl;
			FileAdd(T, 1);
			SelectionPrintLRR(T, Info, 1);
			Delete(T);
            break;
        case 4:
			cout << "Enter the first symbol: ";
			cin >> Info.name;
			cout << endl;
			FileAdd(T, 0);
			SelectionPrintLRR(T, Info, 0);
			Delete(T);
            break;
        default:
            if (key != 0)
            {
                cout << "There is no such action !" << endl << endl;
            }
            break;
        }
    } while (key != 0);
	Delete(T);
}

bool FileAdd(Tree*& T, int type)
{
	AutoInfo Info;
	ifstream F("Auto.txt");
	if (!F)
	{
		cout << "Cant find file" << endl;
		return false;
	}
	while (F >> Info.name >> Info.price >> Info.color >> Info.rating)
	{
		Add(T, Info, type);
	}
	F.close();
}