#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846

using namespace std;

void var5ex1(int number)
{
	int mul = 1;
	while (number != 0)
	{
		mul *= number % 10;
		number /= 10;
	}
	cout << "Произведение цифр числа = " << abs(mul) << endl;
}

void var5ex3()
{
	for (float a = 1; a <= 19; a +=3)
	{
		if (a - 4 == 0)
		{
			cout << "Ошибка !" << endl;
		}
		else
		{
			float answer = (3 + a) / ((a - 4) * (a - 4));
			cout << answer << endl;
		}
	}
}

void var5ex4()
{
	float a[16];
	float b[16];
	a[1] = 1;
	b[1] = 1;
	for (int i = 2; i < 16; i++)
	{
		a[i] = 3 * b[i - 1] + 2 * a[i - 1];
		cout << "a[" << i << "]" << a[i] << endl;
		b[i] = 2 * a[i - 1] + b[i - 1];
		cout << "b[" << i << "]" << b[i] << endl;
	}
}

void ex1(int m)
{
	int b = 0;
	while (m)
	{
		b = b * 2 + m % 2;
		m /= 2;
	}
	cout << "Конвертированное число: "<< b << endl;
}

void ex2(int number)
{
	int div = 2;
	cout << number << " = 1";
	while (number > 1)
	{
		while (number % div == 0)
		{
			cout << " * " << div;
			number /= div;
		}
		div++;
	}
}

void ex3(int number)
{
	int var1[100] = {};
	int var2 = number;
	int i, rev = 0, sum = 0, k = 0;
	for(i = 0; number != 0; i++)
	{
		var1[i] = number % 10;
		number /= 10;
		k++;
		sum += var1[i];
	}
	for (i = 0; i < k; i++)
	{
		rev = rev * 10 + var1[i];
	}

	cout << "а) " << k << endl
		<< "б) " << sum << endl
		<< "в) " << var1[k - 1] << endl
		<< "г) " << rev << endl;
}

void ex4(int number)
{
	int i = 1;
	int n2 = number * number;
	int s = i;
	cout << number << "^2=";
	while (s <= n2)
	{
		if (s < n2)
		{
			cout << i << "+";
		}
		else cout << i << "=";
		i = i + 2;
		s = s + i;
	}
	cout << s - i << endl;
}

void ex5(int start, int final)
{
	int m, k, s, max_m = 0, max_s, min_m = 0, min_s;
	max_s = 0;
	min_s = 2147483647;
	if (start < 0)
	{
		cout << "Вы ввели отрицательное число !" << endl;
	}
	else
	{
		for (int i = start + 1; i <= final - 1; i++)
		{
			k = i;
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
		cout << "Число: " << max_m << " имеет максимальную сумму цифр = " << max_s << endl;
		cout << "Число: " << min_m << " имеет минимальную сумму цифр = " << min_s << endl;
	}
}

void ex6()
{
	double a = 0, b = 2;
	double eps = 1e-5;
	double x, y;
	int k = 0;
	do
	{
		k++;
		x = (a + b) / 2;
		y = log(1 + x) / x - 2 / M_PI;
		if ((log(1 + a) / a - 2 / M_PI) * y < 0)
		{
			b = x;
		}
		else a = x;
		cout << k << ": [" << a << " , " << b << "]" << "   ";
		cout << x << "  " << y << endl;
	} while (fabs(y) > eps);
	cout << x << "  " << y << endl;
}

void ex8(int number)
{
	int k;
	for (int i = 3; i <= number; i++)
	{
		k = 0;
		for (int j = 1; j <= i - 1; j++)
		{
			if (i % j == 0)
			{
				k = k + j;
			}
		}
		if (k == i)
		{
			cout << i << endl;
		}
	}
}

void ex9(int diap)
{
	int best = 0,
		sum,
		max = 0;
	for (int i = 1; i < diap; i++)
	{
		sum = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				sum = sum + j;
			}
		}
		if (best < sum)
		{
			best = sum;
			max = i;
		}
	}
	cout << "Число с максимальной суммой делителей: " << max << endl;
}

void ex10(int number)
{
	int rev = 0;
	for (int i = 0; number != 0; i++)
	{
		rev = rev * 10 + number % 10;
		number /= 10;
	}
	cout << "Перевёрнутое число: " << rev << endl;
}

void ex11(int number)
{
	if (number == 1) cout << "Минимальный нечётный делитель: " << number << endl;
	else
	{
		int k = 3;
		while (k > 0)
		{
			if (number % k == 0) break;
			else k = k + 2;
		}
		cout << "Минимальный нечётный делитель: " << k << endl;
	}
}

void ex12(int number)
{
	int a, i, l;
	cout << endl;
	for (i = number; i > 0; i--) 
	{
		a = i;
		while (a > 0) 
		{
			l = a % 10;
			if (l == 0 || i % l != 0) break;
			else a = a / 10;
		}
		if (a == 0) cout << i << endl;
	}
}

void ex13(int number)
{
	int m[100], m2[100], k = 0, j = 0;
	for (int i = 0; number != 0; i++)
	{
		m[i] = number % 2;
		number /= 2;
		k++;
	}
	for (int i = k - 1; i != -1; i--)
	{
		for (j; j < k; )
		{
			m2[j] = m[i];
			j++;
			break;
		}
	}
	cout << "Число в двоичной системе: ";
	for (int i = 0; i < k; i++)
	{
		cout << m2[i];
	}
	cout << endl;
}

void ex14(int a, int b)
{
	if (a < 0 || b < 0)
	{
		cout << "Вы ввели отрицательное число !" << endl;
	}
	else
	{
		int nod = 0;
		int nok = 0;
		for (int i = a; i > 0; i--)
		{
			if (a % i == 0 && b % i == 0)
			{
				nod = i;
				break;
			}
		}
		cout << "НОД = " << nod << endl;
		nok = (a * b) / nod;
		cout << "НОК = " << nok << endl;
	}
}

void ex15(int n)
{
	double s = 0, k = 0;
	for (int i = 1; i <= n; i++)
	{
		k += sin(i);
		s += 1 / k;
	}
	cout << "S = " << s << endl;
}

void ex16(int n, double x)
{
	double S = 0, si, si_1;
	si_1 = sin(x);
	S = si_1;
	for (int k = 2; k <= n; k++)
	{
		si = sin(si_1);
		S += si;
		si_1 = si;
	}
	cout << "S = " << S << endl;
}

void ex17(int n, double x)
{
	double s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += sin(pow(x, i));
	}
	cout << "S = " << s << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << fixed;
	cout.precision(8);
	int choice;
	do
	{
		cout << endl << "Выберите задание(введите 0 чтобы выйти): " << endl;
		cin >> choice;
		switch (choice)
		{
		case 51:
			cout << "Пятый вариант Первое задание: " << endl << endl;
			int number;
			cout << "Введите число: " << endl;
			cin >> number;
			var5ex1(number);
			break;
		case 53:
			cout << "Пятый вариант Третье задание: " << endl << endl;;
			var5ex3();
			break;
		case 54:
			cout << "Пятый вариант Четвёртое задание: " << endl << endl;;
			var5ex4();
			break;
		case 1:
			cout << "Первое задание: " << endl << endl;
			int m;
			cout << "Введите число: " << endl;
			cin >> m;
			ex1(m);
			break;
		case 2:
			cout << "Второе задание: " << endl << endl;
			int number1;
			cout << "Введите число: " << endl;
			cin >> number1;
			ex2(number1);
			break;
		case 3:
			cout << "Третье задание: " << endl << endl;
			int number2;
			cout << "Введите число: " << endl;
			cin >> number2;
			ex3(number2);
			break;
		case 4:
			cout << "Четвёртое задание: " << endl << endl;
			int number3;
			cout << "Введите число: " << endl;
			cin >> number3;
			ex4(number3);
			break;
		case 5:
			cout << "Пятое задание: " << endl << endl;
			int start, final1;
			cout << "Введите диапазон натуральных чисел: " << endl;
			cin >> start >> final1;
			ex5(start, final1);
			break;
		case 6:
			cout << "Шестое задание: " << endl << endl;
			ex6();
			break;
		case 8:
			cout << "Восьмое задание: " << endl << endl;
			int number4;
			cout << "Введите число: " << endl;
			cin >> number4;
			ex8(number4);
			break;
		case 9:
			cout << "Девятое задание: " << endl << endl;
			int diap;
			cout << "Введите число: " << endl;
			cin >> diap;
			ex9(diap);
			break;
		case 10:
			cout << "Десятое задание: " << endl << endl;
			int number5;
			cout << "Введите число: " << endl;
			cin >> number5;
			ex10(number5);
			break;
		case 11:
			cout << "Одиннадцатое задание: " << endl << endl;
			int number6;
			cout << "Введите число: " << endl;
			cin >> number6;
			ex11(number6);
			break;
		case 12:
			cout << "Двенадцатое задание: " << endl << endl;
			int number7;
			cout << "Введите число: " << endl;
			cin >> number7;
			ex12(number7);
			break;
		case 13:
			cout << "Тринадцатое задание: " << endl << endl;
			int number8;
			cout << "Введите число: " << endl;
			cin >> number8;
			ex13(number8);
			break;
		case 14:
			cout << "Четырнадцатое задание: " << endl << endl;
			int a, b;
			cout << "Введите два числа: " << endl;
			cin >> a >> b;
			ex14(a, b);
			break;
		case 15:
			cout << "Пятнадцатое задание: " << endl << endl;
			int n2;
			do
			{
				cout << "Введите натуральное число n: ";
				cin >> n2;
				if (n2 <= 0) cout << "Число меньше либо равно 0. Введите другое число !" << endl;
			} while (n2 <= 0);
			ex15(n2);
			break;
		case 16:
			cout << "Шестнадцатое задание: " << endl << endl;
			int n;
			double x;
			do
			{
				cout << "Введите натуральное число n: ";
				cin >> n;
				if (n <= 0) cout << "Число меньше либо равно 0. Введите другое число !" << endl;
			} while (n <= 0);
			cout << "Введите x: ";
			cin >> x;
			ex16(n, x);
			break;
		case 17:
			cout << "Семнадцатое задание: " << endl << endl;
			int n1;
			double x1;
			do
			{
				cout << "Введите натуральное число n: ";
				cin >> n1;
				if (n1 <= 0) cout << "Число меньше либо равно 0. Введите другое число !" << endl;
			} while (n1 <= 0);
			cout << "Введите x: ";
			cin >> x1;
			ex17(n1, x1);
			break;
		default:
			if (choice != 0)
			{
				cout << "Такого задания нет !" << endl;
			}
			break;
		}
	} while (choice != 0);
}