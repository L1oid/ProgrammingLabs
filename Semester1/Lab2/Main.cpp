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
	else cout << "� ������ 86400 ������" << endl << endl;
}

void ex2(double x)
{
	double z;
	if (-2 <= x && x <= 4)
	{
		z = 7 * pow(x, 3) + 5 * pow(x, 2) + x;
	}
	else cout << "X �� �������� ������� ���������." << endl << endl;

	if (x > 0 && x <= 4)
	{
		double y = x + 0.75 * z;
		cout << "f(x) = x, ���� x > 0, y = " << y << endl << endl;
	}
	else if (-1 <= x && x <= 0)
	{
		double y = 0.75 * z;
		cout << "f(x) = 0, ���� x > -1 <= x <= 0, y = " << y << endl << endl;
	}
	else if (x < -1 && x >= -2)
	{
		double y = pow(x, 2) + 0.75 * z;
		cout << "f(x) = x^2, ���� x > x < -1, y = " << y << endl << endl;
	}
}

void ex3(double a, double b, double c)
{
	if (a == 0)
	{
		cout << "������" << endl;
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
		cout << boolalpha<< t << " ��� ������������ ������" << endl << endl;
	}
}

void ex4(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float A = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float B = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	float C = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	if (A + B <= C || A + C <= B || B + C <= A)
	{
		cout << "�� ����������" << endl << endl;
	}
	else if (A != B && A != C && B != C)
	{
		cout << "��������������" << endl << endl;
	}
	else if (A == B && B == C)
	{
		cout << "��������������" << endl << endl;
	}
	else
	{
		cout << "��������������" << endl << endl;
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
		cout << "������!" << endl << endl;
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
			cout << "��� ����� ���������" << endl << endl;
		}
		else cout << "��� ����� �� ���������" << endl << endl;
	}
	else if (n >= 100 && n <= 999)
	{
		int b;
		b = n / 100;
		n = n % 10;
		if (b == n)
		{
			cout << "��� ����� ���������" << endl << endl;
		}
		else cout << "��� ����� �� ���������" << endl << endl;
	}
	else if (n >= 10 && n <= 99)
	{
		int b;
		b = n / 10;
		n = n % 10;
		if (b == n)
		{
			cout << "��� ����� ���������" << endl << endl;
		}
		else cout << "��� ����� �� ���������" << endl << endl;
	}
	else cout << "�� ����� �������� �����." << endl << endl;
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
		cout << "����� �������� ������������ ������������������, � ��� ��� �������������." << endl <<endl;
	}
	else cout << "����� �� �������� ������������ ������������������, ��� �� ��� �� ��� �������������" << endl << endl;
	if (a != b && b != c && c < b && c < a)
	{
		cout << "�� ���� ������� ��������� ����� ���������� �������� C." << endl << endl;
	}
	else cout << "���� ����� ���������, ���� C �� �������� ���������� �� ���" << endl << endl;
	if (x < 0 && y < 0 && z < 0 || x <= 1 && x >= 0 || y <= 1 && y >= 0 || z <= 1 && z >= 0)
	{
		cout << "���� ��� ��� ����� ������������, ���� ���� �� ���� ����������� ������� [0,1]." << endl << endl;
	}
	else cout << "�� ��� ����� ������������, � �� ���� �� ��� �� ����������� ������� [0,1]." << endl << endl;;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << fixed << setprecision(2);
	int choice;
	cout << "�������� �������: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "������ �������: " << endl;
		int second;
		cout << "������� �������: " << endl;
		cin >> second;
		ex1(second);
		break;
	case 2:
		cout << "������ �������: " << endl;
		double x;
		cout << "������� x: " << endl;
		cin >> x;
		ex2(x);
		break;
	case 3:
		cout << "������ �������: " << endl;
		double a, b, c;
		cout << "������� a, b, c: " << endl;
		cin >> a >> b >> c;
		ex3(a, b, c);
		break;
	case 4:
		cout << "�������� �������: " << endl;
		float x1, y1, x2, y2, x3, y3;
		cout << "������� A(x1,y1): " << endl;
		cin >> x1 >> y1;
		cout << "������� B(x2,y2): " << endl;
		cin >> x2 >> y2;
		cout << "������� C(x3,y3): " << endl;
		cin >> x3 >> y3;
		ex4(x1, y1, x2, y2, x3, y3);
		break;
	case 5:
		cout << "����� �������: " << endl;
		int a1, b1;
		cout << "������� a � b: " << endl;
		cin >> a1 >> b1;
		ex5(a1, b1);
		break;
	case 6:
		cout << "������ �������: " << endl;
		int xx, yy;
		cout << "������� x � y: " << endl;
		cin >> xx >> yy;
		ex6(xx, yy);
		break;
	case 8:
		cout << "������� �������: " << endl;
		int n;
		cout << "������� �����: " << endl;
		cin >> n;
		ex8(n);
		break;
	case 9:
		cout << "������� �������: " << endl;
		int aaa;
		cout << "������� �����: " << endl;
		cin >> aaa;
		ex9(aaa);
		break;
	case 10:
		cout << "������� �������: " << endl;
		int aaa1, bbb1, ccc1, xxx1, yyy1, zzz1;
		cout << "������� ����� a, b, c: " << endl;
		cin >> aaa1 >> bbb1 >> ccc1;
		cout << "������� ����� x, y, z: " << endl;
		cin >> xxx1 >> yyy1 >> zzz1;
		ex10(aaa1, bbb1, ccc1, xxx1, yyy1, zzz1);
		break;
	default:
		cout << "������ ������� ���." << endl << endl;
		break;
	}
}