#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void ex1(int second)
{
	if (second <= 86400)
	{
		int hh = second / 3600;
		int mm = (second % 3600) / 60;
		cout << "hh.mm = " << hh << "." << mm << endl << endl;
	}
	else cout << "В сутках 86400 секунд" << endl << endl;
}

void ex2(double x)
{
	double z;
	if (-2 <= x && x <= 4)
	{
		z = 7 * pow(x, 3) + 5 * pow(x, 2) + x;
	}
	else cout << "X за пределом области значейний." << endl << endl;

	if (x > 0 && x <= 4)
	{
		double y = x + 0.75 * z;
		cout << "f(x) = x, если x > 0, y = " << y << endl << endl;
	}
	else if (-1 <= x && x <= 0)
	{
		double y = 0.75 * z;
		cout << "f(x) = 0, если x > -1 <= x <= 0, y = " << y << endl << endl;
	}
	else if (x < -1 && x >= -2)
	{
		double y = pow(x, 2) + 0.75 * z;
		cout << "f(x) = x^2, если x > x < -1, y = " << y << endl << endl;
	}
}

void ex3(double a, double b, double c)
{
	if (a == 0)
	{
		cout << "Ошибка" << endl;
		return;
	}
	double D = pow(b, 2) - (4 * a * c);
	if (D == 0)
	{
		double x1 = ((-b + sqrt(D)) / (2 * a));
		bool t(true);
		cout << boolalpha << t << " x1 = " << x1 << endl << endl;
	}
	else if (D > 0) 
	{
		double x1 = ((-b + sqrt(D)) / (2 * a));
		double x2 = ((-b - sqrt(D)) / (2 * a));
		bool t(true);
		cout << boolalpha << t << " x1 = " << x1 << " x2 = " << x2 << endl << endl;
	}
	else
	{
		bool t(false);
		cout << boolalpha<< t << " Нет вещественных корней" << endl << endl;
	}
}

void ex4(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float A = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float B = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	float C = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	if (A + B <= C || A + C <= B || B + C <= A)
	{
		cout << "Не существует" << endl << endl;
	}
	else if (A != B && A != C && B != C)
	{
		cout << "Разносторонний" << endl << endl;
	}
	else if (A == B && B == C)
	{
		cout << "Равносторонний" << endl << endl;
	}
	else
	{
		cout << "Равнобедренный" << endl << endl;
	}
}

void ex5(int a, int b)
{
	double x = pow(a, 2) - 1;
	double y = pow(b, 2) - pow(a, 2);
	double z = sqrt(abs(a + b));
	double min = x, max = x;
	if (y < min) 
	{
		min = y;
	}
	if (z < min) 
	{
		min = z;
	}
	if (y > max) 
	{
		max = y;
	}
	double T = (abs(x) + min) / (abs(y) + max);
	cout << "x = " << x << " y = " << y << " z = " << z << endl;
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	cout << "T = " << T << endl << endl;
}

void ex6(double x, double y)
{
	double min, max;
	if (y > x)
	{
		max = y * x * 2;
		min = (y + x) / 2;
		cout << "Y = " << max << " X = " << min << endl << endl;
	}
	else if (y < x)
	{
		max = y * x * 2;
		min = (y + x) / 2;
		cout << "Y = " << min << " X = " << max << endl << endl;
	}
	else if (x = y)
	{
		cout << "Ошибка!" << endl << endl;
	}
}

void ex8(int n)
{
	if (n >= 1000 && n <= 9999)
	{
		int b, c, e;
		b = n / 1000;
		n = n % 1000;
		c = n / 100;
		n = n % 100;
		e = n / 10;
		n = n % 10;
		if (b == n && c == e)
		{
			cout << "Это число палиндром" << endl << endl;
		}
		else cout << "Это число не палиндром" << endl << endl;
	}
	else if (n >= 100 && n <= 999)
	{
		int b;
		b = n / 100;
		n = n % 10;
		if (b == n)
		{
			cout << "Это число палиндром" << endl << endl;
		}
		else cout << "Это число не палиндром" << endl << endl;
	}
	else if (n >= 10 && n <= 99)
	{
		int b;
		b = n / 10;
		n = n % 10;
		if (b == n)
		{
			cout << "Это число палиндром" << endl << endl;
		}
		else cout << "Это число не палиндром" << endl << endl;
	}
	else cout << "Вы ввели неверное число." << endl << endl;
}

void ex9(double a)
{
	if (a <= 0)
	{
		cout << "F(a) = " << 0 << endl << endl;
	}
	else if (a > 0 && a <= 1)
	{
		cout << "F(a) = " << a << endl << endl;
	}
	else cout << "F(a) = " << pow(a, 3) << endl << endl;
}

void ex10(int a, int b, int c, int x, int y, int z)
{
	if (a < b && b < c && a > 0)
	{
		cout << "Числа образуют возрастающую последовательность, и все они положительные." << endl <<endl;
	}
	else cout << "Числа не образуют возрастающую последовательность, или не все из них положительные" << endl << endl;
	if (a != b && b != c && c < b && c < a)
	{
		cout << "Из трех попарно различных чисел наименьшим является C." << endl << endl;
	}
	else cout << "Либо числа совпадают, либо C не является наименьшим из них" << endl << endl;
	if (x < 0 && y < 0 && z < 0 || x <= 1 && x >= 0 || y <= 1 && y >= 0 || z <= 1 && z >= 0)
	{
		cout << "Либо все три числа отрицательны, либо хотя бы одно принадлежит отрезку [0,1]." << endl << endl;
	}
	else cout << "Не все числа отрицательны, и ни одно из них не принадлежит отрезку [0,1]." << endl << endl;;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << fixed << setprecision(2);
	int choice;
	cout << "Выберите задание: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Первое задание: " << endl;
		int second;
		cout << "Введите секунду: " << endl;
		cin >> second;
		ex1(second);
		break;
	case 2:
		cout << "Второе задание: " << endl;
		double x;
		cout << "Введите x: " << endl;
		cin >> x;
		ex2(x);
		break;
	case 3:
		cout << "Третье задание: " << endl;
		double a, b, c;
		cout << "Введите a, b, c: " << endl;
		cin >> a >> b >> c;
		ex3(a, b, c);
		break;
	case 4:
		cout << "Четвёртое задание: " << endl;
		float x1, y1, x2, y2, x3, y3;
		cout << "Введите A(x1,y1): " << endl;
		cin >> x1 >> y1;
		cout << "Введите B(x2,y2): " << endl;
		cin >> x2 >> y2;
		cout << "Введите C(x3,y3): " << endl;
		cin >> x3 >> y3;
		ex4(x1, y1, x2, y2, x3, y3);
		break;
	case 5:
		cout << "Пятое задание: " << endl;
		int a1, b1;
		cout << "Введите a и b: " << endl;
		cin >> a1 >> b1;
		ex5(a1, b1);
		break;
	case 6:
		cout << "Шестое задание: " << endl;
		int xx, yy;
		cout << "Введите x и y: " << endl;
		cin >> xx >> yy;
		ex6(xx, yy);
		break;
	case 8:
		cout << "Восьмое задание: " << endl;
		int n;
		cout << "Введите число: " << endl;
		cin >> n;
		ex8(n);
		break;
	case 9:
		cout << "Девятое задание: " << endl;
		int aaa;
		cout << "Введите число: " << endl;
		cin >> aaa;
		ex9(aaa);
		break;
	case 10:
		cout << "Десятое задание: " << endl;
		int aaa1, bbb1, ccc1, xxx1, yyy1, zzz1;
		cout << "Введите число a, b, c: " << endl;
		cin >> aaa1 >> bbb1 >> ccc1;
		cout << "Введите число x, y, z: " << endl;
		cin >> xxx1 >> yyy1 >> zzz1;
		ex10(aaa1, bbb1, ccc1, xxx1, yyy1, zzz1);
		break;
	default:
		cout << "Такого задания нет." << endl << endl;
		break;
	}
}