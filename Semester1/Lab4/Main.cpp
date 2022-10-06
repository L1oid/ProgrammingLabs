#include <iostream> 
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;

int ex1()
{
	double x[5] = { 1,1.2,1.5,1.8,2 }, y, eps = 1e-7;
	double sum, s = 0, n = 0;

	for (int i = 0; i < 5; i++)
	{
		y = log(x[i]);
		s = pow((x[i] - 1), (2 * n + 1)) / ((2. * n + 1) * pow((x[i] + 1), (2 * n + 1)));
		sum = 0;
		cout << "При х = " << x[i] << " y(x) =  " << y << endl << endl;
		for (int n = 0; fabs(s) >= eps; n++)
		{
			s = pow((x[i] - 1), (2 * n + 1)) / ((2. * n + 1) * pow((x[i] + 1), (2 * n + 1)));
			sum += s;
			cout << '[' << n << "]" << "   Sum = " << setw(10) << sum * 2 << "   |r| = " << setw(10) << fabs(sum * 2 - y) << endl;
		} 
		cout << endl;
	}
	return(0);
}

int ex2()
{
	double x[5] = { 1,1.2,1.5,1.8,2 }, y, eps = 1e-7;
	double sum, s, n = 0;
	for (int i = 0; i < 5; i++)
	{
		y = log(x[i]);
		s = pow(-1, n) * pow((x[i] - 1), (n + 1)) / (n + 1);
		sum = 0;
		cout << "При х = " << x[i] << " y(x) =  " << y << endl << endl;
		for (int n = 0; fabs(s) >= eps; n++)
		{
			s = (pow(-1, n) * pow((x[i] - 1), (n + 1))) / (n + 1.);
			sum += s;
			cout << '[' << setw(2) << n << "]" << "   Sum = " << setw(10) << sum << "   |r| = " << setw(10) << fabs(sum - y) << endl;
			if (n >= 30) break;
		}
		cout << endl;
	}
	return(0);
}

int ex3()
{
	double x[5] = { 1,1.2,1.5,1.8,2 }, y, eps = 1e-7;
	double sum, s, n = 0;
	for (int i = 0; i < 5; i++)
	{
		y = log(x[i]);
		s = pow((x[i] - 1), (n + 1)) / ((n + 1) * pow(x[i], (n + 1)));
		sum = 0;
		cout << "При х = " << x[i] << " y(x) =  " << y << endl << endl;
		for (int n = 0; fabs(s) >= eps; n++)
		{
			s = pow((x[i] - 1), (n + 1)) / ((n + 1.) * pow(x[i], (n + 1)));
			sum += s;
			cout << '[' << setw(2) << n << "]" << "   Sum = " << setw(10) << sum << "   |r| = " << setw(10) << fabs(sum - y) << endl;
		}
		cout << endl;
	}
	return(0);
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int key;
	do
	{
		cout << "Введите задание(0 - выход): ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1: 
		{
			ex1(); 
			break;
		}
		case 2: 
		{
			ex2(); 
			break;
		}
		case 3: 
		{
			ex3(); 
			break;
		}
		default:
			if (key != 0)
			{
			cout << "Такого задания нет !" << endl;
			}
		break;
		}
	} while (key != 0);
	return 0;
}