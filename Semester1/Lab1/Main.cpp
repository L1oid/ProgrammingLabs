#include <iostream>
#include <cmath>
#include <math.h>

#define M_PI 3.14159265358979323846
using namespace std;

void ex1(float x1, float x2)
{
	float y = (exp(-x1) + exp(-x2)) / 2;
	cout << "y = " << y << endl << endl;
}

void ex2(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << "Площадь s = " << s << endl << endl;
}

void ex3(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	float ha = 2 * s / a;
	float hb = 2 * s / b;
	float hc = 2 * s / c;
	cout << "Высоты равны: " << endl << "ha = " << ha << " hb = " << hb << " hc = " << hc << endl << endl;
}
void ex4(float r1, float r2, float l, float h)
{
	float s = M_PI * (r1 + r2) * l + M_PI * pow(r1, 2) + M_PI * pow(r2, 2);
	float v = (1 / 3.0) * (pow(r1, 2) + pow(r2, 2) + r1 * r2) * h * M_PI;
	cout << "Площадь s = " << s << " Объём v = " << v << endl << endl;
}

void ex5(float a, float omega, float phi)
{
	float x = (M_PI / 2) - phi;
	float y = a * exp(-a * omega * x) * sin(omega * x);
	cout << "x = " << x << " y = " << y << endl << endl;
}

void ex6(int number)
{
	int result;
	result = number / 100 % 10;
	cout << "Третий справа разряд целого числа: " << result << endl << endl;
}

void ex7(float number)
{
	float var;
	var = number * 10;
	int result = var;
	result %= 10;
	cout << "Первый после десятичной точки разряд дробной части: " << result << endl << endl;
}

void ex8(float c, float d)
{
	float a = c / d;
	float b = (c * d) * 3;
	cout << "a) Разность = " << a << " Утроенное произведение = " << b << endl;
	float x1 = c, x2 = d;
	x1 = x1 + x2;
	x2 = x1 - x2;
	x1 = x1 - x2;
	cout << "б) Изначальный вектор: x(" << c << "," << d << ")" << " Изменённый вектор : x(" << x1 << "," << x2 << ")" << endl;
	float nx1, nx2;
	nx1 = x1 + x2;
	nx2 = x1 * x2;
	cout << "в) Изначальный вектор: x(" << c << "," << d << ")" << " Изменённый вектор : x(" << nx1 << "," << nx2 << ")" << endl << endl;
}

void ex9(float a, float b, float c, float x)
{
	float result1 = 3 + ((a + b + c) / abs(a + b + c) + 1);
	float result2 = sin(a + b + c) + 5 * pow(x + a - c, 4);
	float finalresult = result1 / result2;
	cout << "Результат = " << finalresult << endl;
}

int main()
{
	////////////////////////////////////
	setlocale(LC_ALL, "ru");
	cout << "Первое задание: " << endl;
	int x1, x2;
	cout << "Введите x1 и x2: " << endl;
	cin >> x1 >> x2;
	ex1(x1, x2);
	////////////////////////////////////
	cout << "Второе задание: " << endl;
	int a, b, c;
	cout << "Введите стороны треугольника a, b ,c: " << endl;
	cin >> a >> b >> c;
	ex2(a, b, c);
	////////////////////////////////////
	cout << "Третье задание: " << endl;
	ex3(a, b, c);
	////////////////////////////////////
	cout << "Четвёртое задание: " << endl;
	int r1, r2, l, h;
	cout << "Введите r1, r2, l, h:" << endl;
	cin >> r1 >> r2 >> l >> h;
	ex4(r1, r2, l, h);
	////////////////////////////////////
	cout << "Пятое задание: " << endl;
	float a2, omega, phi;
	cout << "Введите a, omega, phi: " << endl;
	cin >> a2 >> omega >> phi;
	ex5(a2, omega, phi);
	////////////////////////////////////
	cout << "Шестое задание: " << endl;
	int number1;
	cout << "Введите число: " << endl;
	cin >> number1;
	ex6(number1);
	////////////////////////////////////
	cout << "Седьмое задание: " << endl;
	float number2;
	cout << "Введите число: " << endl;
	cin >> number2;
	ex7(number2);
	////////////////////////////////////
	cout << "Восьмое задание: " << endl;
	int n1, n2;
	cout << "Введите два числа: " << endl;
	cin >> n1 >> n2;
	ex8(n1, n2);
	////////////////////////////////////
	cout << "Девятое задание: " << endl;
	int a1, b1, c1, x;
	cout << "Введите четыре числа: " << endl;
	cin >> a1 >> b1 >> c1 >> x;
	ex9(a1, b1, c1, x);
}