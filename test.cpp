#include <ctime>
#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;



struct deposid
{
	int  ID;
	char*	Last_name;
	char*	First_name;
	double	Summ;

};

deposid add_deposid();
void print_deposid(deposid* info, int count_p);
void count_deposid_b_summ(deposid* info, int count_p, int max);
void count_deposid_b_L_N_and_F_N(deposid* info, int count_p, char* L_N, char* F_N);


int main()
{

	unsigned int start_time = clock();

	int flag = 9;
	int count_p;
	int max = 0;
	char* L_N = new char[256];
	char* F_N = new char[256];



	cout << "1------------Add deposid" << endl;
	cout << "2------------Print deposid" << endl;
	cout << "3------------Count deposid by summ" << endl;
	cout << "4------------Count deposid by Last and First name" << endl;
	cout << "0------------Exit" << endl;

	cout << "Input count of people" << endl;
	cin >> count_p;


	deposid* info = new deposid[count_p];


	for (int i = 0; i < count_p; i++)

	{
		info[i].Last_name = new char[256];
		info[i].First_name = new char[256];
	}




	//начало заполнение
	for (int i = 0; i < count_p; i++)

	{
		cout << "Input ID_" << i << "_" << endl;
		cin >> info[i].ID;

		info[i].Last_name = new char[256];
		cout << "Input LastName_" << i << "_" << endl;
		cin >> info[i].Last_name;

		info[i].First_name = new char[256];
		cout << "Input FirstName_" << i << "_" << endl;
		cin >> info[i].First_name;

		cout << "Input SUmm_" << i << "_" << endl;
		cin >> info[i].Summ;

	}
	//конец заполнения
















	while (flag != 0)
	{
		cout << "Input flag" << endl;
		cin >> flag;

		switch (flag)
		{
		case 1:



			count_p++;
			info = (deposid*)realloc(info, sizeof(deposid)*count_p);
			info[count_p - 1] = add_deposid();

			break;
		case 2:

			print_deposid(info, count_p);

			break;
		case 3:
			cout << "Input max Summ" << endl;
			cin >> max;
			count_deposid_b_summ(info, count_p, max);
			break;
		case 4:

			cout << "Input Last_name" << endl;
			cin >> L_N;

			cout << "Input First_name" << endl;
			cin >> F_N;

			count_deposid_b_L_N_and_F_N(info, count_p, L_N, F_N);


			break;
		deault:
			cout << "bb" << endl;
		}

	}





	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "search_time= " << search_time / 1000.0 << "_msc" << endl;



	system("pause>>0");
	return 0;
}













deposid add_deposid()
{

	deposid info;

	info.ID = 0;
	cout << "Input ID_" << endl;
	cin >> info.ID;

	info.Last_name = new char[256];
	cout << "Input LastName_" << endl;
	cin >> info.Last_name;

	info.First_name = new char[256];
	cout << "Input FirstName_" << endl;
	cin >> info.First_name;

	info.Summ = 0;
	cout << "Input SUmm_" << endl;
	cin >> info.Summ;



	return(info);
}

void print_deposid(deposid* info, int count_p)
{
	cout << "|------| |------------------| |-------------------| |--------------|" << endl;
	cout << "|--ID--| |-----Last_name----| |----First_name-----| |-----Summ-----|" << endl;
	cout << "|------| |------------------| |-------------------| |--------------|" << endl;
	for (int i = 0; i < count_p; i++)
	{

		cout << "|";
		cout << setw(6) << left << info[i].ID;
		cout << "|";

		cout << " |";
		cout << setw(18) << left << info[i].Last_name;
		cout << "|";

		cout << " |";
		cout << setw(19) << left << info[i].First_name;
		cout << "|";

		cout << " |";
		cout << setw(14) << left << info[i].Summ;
		cout << "|" << endl;

		cout << "|------| |------------------| |-------------------| |--------------|" << endl;



	}


}

void count_deposid_b_summ(deposid* info, int count_p, int max)
{
	cout << "|------| |------------------| |-------------------| |--------------|" << endl;
	cout << "|--ID--| |-----Last_name----| |----First_name-----| |-----Summ-----|" << endl;
	cout << "|------| |------------------| |-------------------| |--------------|" << endl;
	for (int i = 0; i < count_p; i++)
	{
		if (info[i].Summ > max)
		{




			cout << "|";
			cout << setw(6) << left << info[i].ID;
			cout << "|";

			cout << " |";
			cout << setw(18) << left << info[i].Last_name;
			cout << "|";

			cout << " |";
			cout << setw(19) << left << info[i].First_name;
			cout << "|";

			cout << " |";
			cout << setw(14) << left << info[i].Summ;
			cout << "|" << endl;

			cout << "|------| |------------------| |-------------------| |--------------|" << endl;




		}
	}
}

void count_deposid_b_L_N_and_F_N(deposid* info, int count_p, char* L_N, char* F_N)
{
	cout << "|------| |------------------| |-------------------| |--------------|" << endl;
	cout << "|--ID--| |-----Last_name----| |----First_name-----| |-----Summ-----|" << endl;
	cout << "|------| |------------------| |-------------------| |--------------|" << endl;
	for (int i = 0; i < count_p; i++)
	{
		if ((strcmp(info[i].Last_name, L_N) || strcmp(info[i].First_name, F_N)) == 0)
		{




			cout << "|";
			cout << setw(6) << left << info[i].ID;
			cout << "|";

			cout << " |";
			cout << setw(18) << left << info[i].Last_name;
			cout << "|";

			cout << " |";
			cout << setw(19) << left << info[i].First_name;
			cout << "|";

			cout << " |";
			cout << setw(14) << left << info[i].Summ;
			cout << "|" << endl;

			cout << "|------| |------------------| |-------------------| |--------------|" << endl;




		}
	}

}
