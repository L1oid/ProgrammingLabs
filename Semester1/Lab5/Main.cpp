#include <iostream>
#define M_PI 3.14159265358979323846
using namespace std;

int IntGetN();
int NaturalGetN();
float NaturalFloatGetN();
int ex1(int, int);
int ex2nod(int, int);
int ex2nok(int, int);
double ex3(double);
void ex4(int, int, int, int);
void ex5(int, int);
long long int ex5fact(int);
void ex6(int);
int ex6sum(int);
int ex7(int);
double ex8circle(double);
double ex8rectangle(double, double);
double ex8rightTriangle(double, double);

int main()
{
	int key = 0;
	setlocale(LC_ALL, "ru");
	do
	{
		cout << endl << "�������� �������(0 - �����): ";
		cin >> key;
		switch (key)
		{
		case 1: //1 �������
			int a, b;
			do
			{
				do
				{
					cout << "������� a: ";
					a = NaturalGetN();
					if (a <= 1)
						cout << "����� ������ ���� ������ ��� ����� 2" << endl;
				} while (a <= 1);
				cout << "������� b: ";
				b = NaturalGetN();
				if (a >= b)
					cout << "����� ������ a ���� ������ ����� b" << endl;
			} while (a >= b);
			ex1(a, b);
			cout << endl;
			break;
		case 2: //2 �������
			int aa, bb, cc;
			cout << "������� ��� �����:" << endl;
			cout << "1) ";
			aa = NaturalGetN();
			cout << "2) ";
			bb = NaturalGetN();
			cout << "3) ";
			cc = NaturalGetN();
			cout << "��� ��� ����� �����: " << ex2nod(ex2nod(aa, bb), cc) << endl;
			cout << "��� ��� ����� �����: " << ex2nok(ex2nok(aa, bb), cc);
			cout << endl;
			break;
		case 3: // 3 �������
			double aaa;
			do
			{
				cout << "������� ������� ����������� ������������: ";
				aaa = NaturalFloatGetN();
				if (aaa <= 0) cout << "����� ������ ���� ������ ����." << endl;
			} while (aaa <= 0);
			cout << "������� ����������� �������������� �� �������� " << aaa << " �����: " << 6 * ex3(aaa);
			cout << endl;
			break;
		case 4: // 4 �������
			int aaaa, bbbb, cccc, dddd;
			cout << "������� �����: " << endl;
			cout << "a = ";
			aaaa = NaturalGetN();
			cout << "b = ";
			bbbb = NaturalGetN();
			cout << "c = ";
			cccc = NaturalGetN();
			cout << "d = ";
			dddd = NaturalGetN();
			cout << "������ �����: " << aaaa << " \\ " << bbbb << endl;
			cout << "������ �����: " << cccc << " \\ " << dddd << endl;
			ex4(aaaa, bbbb, cccc, dddd);
			cout << endl;
			break;
		case 5: // 5 �������
			int m, n;
			do
			{
				cout << "������� �������� ����� �� m �� n(�� ������ 20-��): " << endl;
				cout << "m) ";
				m = NaturalGetN();
				do
				{
					cout << "n) ";
					n = NaturalGetN();
				} while (n > 20);
				if (m >= n)
				{
					cout << "����� ������ n ���� ������ ����� m" << endl;
				}
			} while (m >= n);
			ex5(m, n);
			cout << endl;
			break;
		case 6: // 6 �������
			int amount;
			cout << "����� ���������� ����� �� ������ ������: ";
			amount = NaturalGetN();
			ex6(amount);
			cout << endl;
			break;
		case 7: // 7 �������
			int num1, num2;
			cout << "������� ������ �����: ";
			num1 = IntGetN();
			cout << "������� ������ �����: ";
			num2 = IntGetN();
			if (ex7(num1) == ex7(num2))
			{
				cout << "� ����� " << num1 << " ������� �� ����, ������� � ����� " << num2 << endl;
			}
			else if (ex7(num1) > ex7(num2))
			{
				cout << "� ����� " << num1 << " ������ ���� ��� � ����� " << num2 << endl;
			}
			else
			{
				cout << "� ����� " << num2 << " ������ ���� ��� � ����� " << num1 << endl;
			}
			cout << endl;
			break;
		case 8: // 8 �������
			int keyLocal;
			do
			{
				cout << endl << "�������� ������(1 - ����, 2 - �������������, 3 - ������������� �����������, 0 - �����): ";
				cin >> keyLocal;
				switch (keyLocal)
				{
				case 1:
					double r;
					cout << "������� ������ �����: ";
					r = NaturalFloatGetN();
					cout << "������� ����� � �������� " << r << " �����: " << ex8circle(r) << endl;
					break;
				case 2:
					double a1, b1;
					cout << "������� ������� ��������������:" << endl;
					cout << "a = ";
					a1 = NaturalFloatGetN();
					cout << "b = ";
					b1 = NaturalFloatGetN();
					cout << "������� �������������� �� ��������� " << a1 << " � " << b1 << " �����: " << ex8rectangle(a1, b1) << endl;
					break;
				case 3:
					double a2, b2;
					cout << "������� ������ �������������� ������������:" << endl;
					cout << "����� a = ";
					a2 = NaturalFloatGetN();
					cout << "����� b = ";
					b2 = NaturalFloatGetN();
					cout << "������� �������������� ������������ � �������� " << a2 << " � " << b2 << " �����: " << ex8rightTriangle(a2, b2) << endl;
					break;
				default:
					if (keyLocal != 0)
					{
						cout << "����� ������ ��� !" << endl;
					}
					break;
				}
			} while (keyLocal != 0);
			cout << endl;
			break;
		default:
			if (key != 0)
			{
				cout << "������ ������� ��� !" << endl;
			}
			break;
		}
	} while (key != 0);
}

int IntGetN() //������� �����
{
	float n;
	do 
	{
		cin >> n;
		if (n - (int)n != 0 || n > INT_MAX)
			cout << "������! ������� ������ �����: ";
	} while (n - (int)n != 0 || n > INT_MAX);

	return n;
}

int NaturalGetN() //������� �����
{
	float n;
	do
	{
		cin >> n;
		if (n <= 0 || n - (int)n != 0 || n > INT_MAX)
			cout << "������! ������� ������ �����: ";
	} while (n <= 0 || n - (int)n != 0 || n > INT_MAX);

	return n;
}

float NaturalFloatGetN() // ������� �����
{
	float n;
	do
	{
		cin >> n;
		if (n <= 0 || n > INT_MAX)
			cout << "������! ������� ������ �����: ";
	} while (n <= 0 || n > INT_MAX);

	return n;
}

int ex1(int a, int b) // 1 �������
{
	int k = 0;
	int* AllNum = new int[b + 1];
	for (int i = 0; i <= b; i++)
	{
		AllNum[i] = i;
	}
	int* primeNum = new int[b];
	cout << "������� �����: ";
	for (int i = a; i <= b; i++)
	{
		for (int j = 2; j <= sqrt((double)AllNum[i]); j++)
		{
			if (AllNum[i] % j == 0 && AllNum[i] != j)
			{
				AllNum[i] = 0;
				break;
			}
		}
		if (AllNum[i] != 0)
		{
			primeNum[k] = AllNum[i];
			k++;
			cout << AllNum[i] << " ";
		}
	}
	primeNum[k] = 0;
	cout << "������������� �����: ";
	for (int i = 0; primeNum[i] != 0; i++)
	{
		if (primeNum[i + 1] - primeNum[i] == 2)
		{
			cout << "(" << primeNum[i] << " " << primeNum[i + 1] << ")";
		}
	}
	delete[] AllNum;
	AllNum = nullptr;
	delete[] primeNum;
	primeNum = nullptr;
	return 0;
}

int ex2nod(int a, int b) // 2 �������
{
	int nod = 0;
	for (int i = a; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			nod = i;
			break;
		}
	}
	return nod;
}

int ex2nok(int a, int b) // 2 �������
{
	int nok = (a * b) / ex2nod(a, b);
	return nok;
}

double ex3(double a) // 3 �������
{
	double s = ((a * a) * sqrt(3)) / 4;
	return s;
}

void ex4(int a, int b, int c, int d) // 4 �������
{
	int k1 = a * d;
	int d1 = b * c;
	cout << "1) " << a << " \\ " << b << " : " << c << " \\ " << d << " = " << k1 << " \\ " << d1 << endl;
	int k2 = a * c;
	int d2 = b * d;
	cout << "2) " << a << " \\ " << b << " * " << c << " \\ " << d << " = " << k2 << " \\ " << d2 << endl;
	int k3 = (a * d) + (b * c);
	int d3 = ex2nok(b, d);
	cout << "3) " << a << " \\ " << b << " + " << c << " \\ " << d << " = " << k3 << " \\ " << d3 << endl;
}

void ex5(int m, int n) // 5 �������
{
	long long int sum = 0;
	for (int i = m; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			cout << i << "! = " << ex5fact(i) << endl;
			sum += ex5fact(i);
		}
	}
	cout << "����� ������ ����������� = " << sum << endl;
}

long long int ex5fact(int n) // 5 �������
{
	if (n == 1) return 1;
	return n * ex5fact(n - 1);
}

void ex6(int amount) // 6 �������
{
	int m, k, s;
	int max_m = 0, max_s = 0;
	int min_m = 0, min_s = INT_MAX;
	int* arr = new int[amount];
	cout << "������� " << amount << " ����������x �����: " << endl;
	for (int i = 0; i < amount; i++)
	{
		arr[i] = NaturalGetN();
	}
	for (int i = 0; i < amount; i++)
	{
		k = arr[i];
		while (k != 0)
		{
			m = k;
			s = 0;
			while (k != 0)
			{
				s += k % 10;
				k = k / 10;
			}
			if (s > max_s)
			{
				max_s = s;
				max_m = m;
			}
			if (s < min_s)
			{
				min_s = s;
				min_m = m;
			}
		}
	}
	cout << "�����: " << max_m << " ����� ������������ ����� ���� = " << max_s << endl;
	cout << "�����: " << min_m << " ����� ����������� ����� ���� = " << min_s << endl;

	delete[] arr;
	arr = nullptr;
}

int ex6sum(int n) // 6 �������
{
	int sum = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return abs(sum);
}

int ex7(int n) // 7 �������
{
	int count = 0;
	while (n != 0)
	{
		n % 10;
		count++;
		n /= 10;
	}
	return count;
}

double ex8circle(double r) // 8 �������
{
	double s = M_PI * (r * r);
	return s;
}

double ex8rectangle(double a, double b) // 8 �������
{
	double s = a * b;
	return s;
}

double ex8rightTriangle(double a, double b) // 8 �������
{
	double s = (a * b) / 2;
	return s;
}