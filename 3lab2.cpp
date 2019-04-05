#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;

void FillArray(double** X, int n, int m, double s);
void printMatrix(double** X, int n, int m);
double upSumMatrix(double** X, int n, int m);

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int n;
	int m;
	double s;
	cout << "������� ���������� ����� ";
	cin >> n;
	cout << endl;
	cout << "������� ���������� ������� ";
	cin >> m;
	cout << endl;
	cout << "������� ���������� ������ ����� ������� ";
	cin >> s;
	cout << endl;

	double **X = new double*[n]; 
	for (int i = 0; i < m; i++)
		X[i] = new double[m];


	double **Y = new double*[n]; 
	for (int i = 0; i < m; i++)
		Y[i] = new double[m];

	FillArray(X,n,m,s);
	FillArray(Y,n,m,s);

	printMatrix(X,n,m);

	cout << endl;
	cout << endl;

	printMatrix(Y,n,m);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	double sum1 = upSumMatrix(X,n,m);
	double sum2 = upSumMatrix(Y,n,m);


	if (sum1 > sum2)
		cout << "���������� ����� � ������ ������� � ��� ����� " << sum1;

	if (sum2 > sum1)
		cout << "���������� ����� � ������ ������� � ��� ����� " << sum2;

	if (sum2 == sum1)
		cout << "����� ������ ��������� � ��� ����� " << sum1;

	cout << endl;

	system("pause");
}



double upSumMatrix(double** X, int n, int m)
{
	double result = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < m; j++)
			result += X[i][j];
	return result;
}

void FillArray(double** X, int n, int m , double s) {
	 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
		
			X[i][j]=(rand() % 899 +100) +(rand())*(1/pow(10,s));
			
		}
	}
}

void printMatrix(double** X, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << X[i][j] << " ";
		}
		cout << endl;
	}
}

