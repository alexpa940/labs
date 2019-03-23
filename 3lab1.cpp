#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;


float spryamoug(float a, float b);


void main()
{
	float a;
	float b;
	int log = 1;
	setlocale(LC_ALL, "RUS");

	do {
		cout << "Вычисление площади прямоугольника ";
		cout << endl;
		cout << "Введите b ";
		cin >> b;
		cout << endl;

		cout << "Введите a ";
		cin >> a;
		cout << endl;

		float s = spryamoug(a, b);
		cout << "Площадь прямоугольника равна " << s;
		cout << endl;

		cout << "Введите значение: 1-Произвести вычисления для новых значений; 0 - завершить программу ";
		cin >> log;

			switch (log)
			{
			case 0:
				cout << "Введен 0. Завершение программы" << endl;
				break;
			case 1:
				break;
			default:
				cout << "Ошибка ввода. Завершение программы" << endl;
				break;
			}

	} while (log != 0);
	
	cout << endl;
	system("pause");
}

float spryamoug(float a, float b)
{
	return a * b;
	
}
