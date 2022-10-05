#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void GetMatr(double**, int, int); //������� ���������� ������� ������ ����������
void Dimension(int&, int&); //������� �����������
void PrintMatr(double**, int, int, const char*); //������� ������ �������
void PrintVect(double*, int, const char*); //������� ������ �������
void NewMatr(double**&, int, int); //������� ��������� ������
void DelMatr(double**&, int, int); //������� ������������ ������
void GetRandMatr(double**, int, int, int, int); //������� ���������� ���������� �������
bool TriangMatr(double**, double**, double&, int); //������� ������������ �������
bool Solve(double**, double**, double*, double&, int); //������� ������� �������
void Delta(double**, double*, int, int); //������� �����������
void HilbertMatrix(double**, int, int); //

int main()
{
	setlocale(LC_ALL, "Rus");
	int key = 0;
	int n, m;
	double determ = 1;
	double** A;
	double** B;
	Dimension(n, m);
	double* x = new double[n];
	do
	{
		cout << "1) Random matrix" << endl
			<< "2) Another matrix" << endl
			<< "3) Change dimension" << endl
			<< "4) Hilbert Matrix" << endl
			<< "0) Exit" << endl;
		cout << endl << "Select an action: ";
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
			NewMatr(A, n, m);
			NewMatr(B, n, m);
			GetRandMatr(A, n, m, 1, 10);
			PrintMatr(A, n, m, "A");
			if (Solve(A, B, x, determ, n))
			{
				PrintVect(x, n, "x");
				Delta(A, x, n, m);
			}
			DelMatr(A, n, m);
			DelMatr(B, n, m);
			break;
		case 2:
			NewMatr(A, n, m);
			NewMatr(B, n, m);
			GetMatr(A, n, m);
			PrintMatr(A, n, m, "A");
			if (Solve(A, B, x, determ, n))
			{
				PrintVect(x, n, "x");
				Delta(A, x, n, m);
			}
			DelMatr(A, n, m);
			DelMatr(B, n, m);
			break;
		case 3:
			Dimension(n, m);
			cout << "Dimension changed" << endl;
			break;
		case 4:
			NewMatr(A, n, m);
			NewMatr(B, n, m);
			HilbertMatrix(A, n, m);
			PrintMatr(A, n, m, "A");
			if (Solve(A, B, x, determ, n))
			{
				PrintVect(x, n, "x");
				Delta(A, x, n, m);
			}
			DelMatr(A, n, m);
			DelMatr(B, n, m);
			break;
		default:
			if (key != 0)
			{
				cout << "������ �������� ��� !" << endl << endl;
			}
			break;
		}
	} while (key != 0);
	delete[]x;
	x = nullptr;
}

void HilbertMatrix(double** M, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			M[i][j] = (1.0/(j + i + 1));
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element [" << i + 1 << "][" << m - 1 << "]: ";
		cin >> M[i][m - 1];
	}
}

void GetMatr(double** M, int n, int m)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> M[i][j];
		}
	}
}

void Dimension(int& n, int& m)
{
	cout << "Enter the dimension of the matrix:" << endl
		<< "n: "; cin >> n;
	cout << "m: "; cin >> m; cout << endl;
	m = m + 1;
}

void PrintMatr(double** M, int n, int m, const char* namematr)
{
	cout << endl << " " << namematr << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(14) << M[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void PrintVect(double* x, int n, const char* namevect)
{
	cout << " " << namevect << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(14) << x[i];
	}
	cout << endl << endl;
}

void NewMatr(double**& M, int n, int m)
{
	cout << "\t-New double matr-" << endl;
	M = new double* [n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new double[m];
	}
}

void DelMatr(double**& M, int n, int m)
{
	cout << "\t-Delete double matr-" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		delete[] M[i];
	}
	delete[] M;
	M = nullptr;
}

void GetRandMatr(double** M, int n, int m, int a, int b)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			M[i][j] = rand() % (b - a - 1) + a;
		}
	}
}

bool TriangMatr(double** A, double** B, double& determ, int n) //������������ ������� + ������������
{
	determ = 1;
	double koef;
	double max = 0;
	double zeroCheck;
	unsigned int maxIndex;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	for (int k = 0; k < n; k++) //������������ ���������
	{
		if (B[k][k] == 0) //����� �������� �������
		{
			for (int i = k + 1; i < n; i++) //����� ���������� ������
			{
				if (fabs(B[i][k]) > max) 
				{
					max = fabs(B[i][k]);
					maxIndex = i;
				}
			}
			if (max > 0) 
			{
				for (int j = 0; j < n + 1; j++) 
				{
					swap(B[k][j], B[maxIndex][j]);
				}
				determ *= -1;
			}
			else 
			{
				cout << endl << "Unable to select leading element" << endl << endl;
				return false;
			}
		}
		zeroCheck = 0;
		for (int i = 0; i < n + 1; i++) zeroCheck += B[k][i];
		if (zeroCheck == 0) 
		{
			cout << endl << "Collinear or null strings are available" << endl << endl;
			return false;
		}
		for (int i = k + 1; i < n; i++) 
		{
			koef = -1 * B[i][k] / B[k][k];
			for (int j = k; j < n + 1; j++) B[i][j] = B[i][j] + B[k][j] * koef;//�������������� ����������� �����
		}
		determ *= B[k][k];//���������� ������������
	}
	PrintMatr(B, n, n + 1, "B");
	cout << " Matrix determinant = " << determ << endl << endl;
	return true;
}

bool Solve(double** A, double** B, double* x, double& determ, int n) // ������� �� �����
{
	double res = 0;
	double zeroCheck;
	if (TriangMatr(A, B, determ, n) == true) //������� �������-�������
	{
		for (int i = n - 1; i >= 0; i--) 
		{
			res = 0;
			for (int j = i + 1; j <= n - 1; j++) res = res - x[j] * B[i][j];
			res += B[i][n];
			x[i] = res / B[i][i];
		}
		for (int i = 0; i < n; i++) //�������� �� ������� ������
		{
			zeroCheck = 0;
			for (int j = 0; j < n + 1; j++) 
			{
				zeroCheck += B[i][j];
			}
			if (zeroCheck == 0) 
			{
				cout << endl << "Collinear or null strings are available" << endl << endl;
				return false;
			}
		}
		return true;
	}
	cout << endl << "The system has no single solution" << endl << endl;
	return false;
}

void Delta(double **A, double* x, int n, int m)
{
	double* y = new double[n];
	for (int i = 0; i < n; i++) 
	{
		double res = 0;
		for (int j = 0; j < n; j++) 
		{
			res += A[i][j] * x[j];
		}
		y[i] = res;
	}
	double max;
	max = fabs(y[0] - A[0][m - 1]);
	for (int i = 1; i < n; i++) 
	{
		if (fabs(y[i] - A[i][m - 1]) > max)
		{
			max = fabs(y[i] - A[i][m - 1]);
		}
	}
	delete[] y;
	y = NULL;
	cout << " Delta = " << max << endl << endl;
}