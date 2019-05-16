#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <cctype>
//isupper(ch) !=0  <--- буква верхнего регистра латиницы
using namespace std;

int main()
{
	int i, j, k, n, count_str;

	k = 0;

	vector <string> text;   //создание текста
	vector <string> text_copy;
	vector <int> arr;
	//буфер для ввода

	string buffer = "";

	string zvezdochka = "*";


	cout << "Input text" << endl;
	cout << "Input empty string at the end of the input" << endl;


	do
	{
		getline(cin, buffer);
		if (buffer.size() > 0)
		{
			text.push_back(buffer);
		}
	} while (buffer != "");

	cout << "count_str= " << text.size() << endl; //выводит количество строк


	count_str = text.size();

	int *max_l = new int[count_str];


	text_copy = text;   //копирует текст в другой вектор



	//Подсчёт слов в каждой строке 
	for (i = 0; i < count_str; i++)
	{
		if ((isalpha(text[i][0]) != 0) || (isdigit(text[i][0]) != 0))
		{
			k = k + 1;
		}

		for (j = 0; j < text[i].size(); j++)
		{
			if ((text[i][j] == ' ') && ((isalpha(text[i][j + 1]) != 0) || (isdigit(text[i][j + 1]) != 0))
				|| (text[i][j] == '	') && ((isalpha(text[i][j + 1]) != 0) || (isdigit(text[i][j + 1]) != 0)))
			{
				k = k + 1;
			}
		}



		int b = (int)k;
		char* c = new char[255];
		c = _itoa(b, c, 10);

		text[i].push_back(' ');
		text[i].push_back(' ');
		text[i].push_back('=');
		text[i].push_back(' ');
		text[i].push_back(*c);
		if (k % 10 == 0)	text[i].push_back('0');
		text[i].push_back(' ');
		text[i].push_back(' w');
		text[i].push_back(' o');
		text[i].push_back(' r');
		text[i].push_back(' d');
		text[i].push_back(' s');

		cout << text[i] << endl;

		k = 0;
	}

	//Конец подсчёта слов в каждой строке 

	cout << " " << endl;


	k = 0;
	i = 0;
	j = 0;
	int words = 0;

	count_str = text_copy.size();
	for (i = 0; i < count_str; i++)
	{
		text_copy[i].push_back(' ');
	}

	//Начало подсчёта букв в каждом слове


	for (i = 0; i < count_str; i++)
	{
		j = 0;
		//подсчёт букв первого слова
		if ((isalpha(text_copy[i][0]) != 0) || (isdigit(text_copy[i][0]) != 0))
		{
			do
			{
				k = k + 1;
				j = j + 1;
				if (isspace(text_copy[i][j]) != 0)
				{
					words = words + 1;
					break;
				}

			} while (true);


			cout << "count letters in the " << i + 1 << " str and in " << words << " word " << " = " << k << endl;

			max_l[i] = k;
			k = 0;
		}

		//конец подсчёта букв первого слова

		k = 0;
		words = 0;


		//подсчёт букв всех слов
		while (j < text_copy[i].size() - 1)
		{


			if (((isalpha(text_copy[i][j + 1]) != 0) || (isdigit(text_copy[i][j + 1]) != 0))
				&& isspace(text_copy[i][j]) != 0)
			{
				do
				{
					k = k + 1;
					j = j + 1;
					if (((isalpha(text_copy[i][j]) != 0) || (isdigit(text_copy[i][j]) != 0))
						&& isspace(text_copy[i][j + 1]) != 0)
					{
						words = words + 1;
						break;
					}

				} while (true);


				cout << "count letters in the " << i + 1 << " str and in " << words + 1 << " word " << " = " << k << endl;
				if (k > max_l[i])
					max_l[i] = k;
				k = 0;
			}
			else
			{
				j = j + 1;
			}
		}
		cout << " " << endl;
		//конец подсчёта букв остальных слов
		words = 0;
	}
	


	//Конец подсвчёта слов в аждом слове


	cout << "Input max dlina" << endl;
	cin >> n;
	cout << endl;

	cout << " " << endl;

	for (int i = 0; i < count_str; i++)
		cout << max_l[i] << " ";


	cout << " " << endl;



	for (int i = 0; i < count_str; i++)
	{
		if (max_l[i] > n)
			text_copy[i] = zvezdochka + text_copy[i];
	}
	

	for (i = 0; i < count_str; i++)
	{
		cout << text_copy[i] << endl;
	}

	cout << " " << endl;

	system("pause>>0");
	return 0;
}
