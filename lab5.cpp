#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct credit
{
	int  ID;
	char*	Last_name;
	char*	First_name;
	double	Summ;
	int     percent;
};

struct savedata
{
	char*	Last_name;
	char*	First_name;
};

credit add_credit();
void print_credit(credit* info, int count_p);
void print_savedata(savedata* info1, int saved_count);
void same_percent(credit* info, savedata* info1, int count_p, int per, int saved_count);
void count_credit_b_L_N_and_F_N(credit* info, int count_p, char* L_N, char* F_N);

int main()
{


	int flag = 9;
	int count_p;
	int saved_count = 0;
	int per = 0;
	char* L_N = new char[256];
	char* F_N = new char[256];


	cout << "1------------Add credit" << endl;
	cout << "2------------Print credits" << endl;
	cout << "3------------Count credit by Last and First name" << endl;
	cout << "4------------Find person by percent" << endl;
	cout << "0------------Exit" << endl;
	

	cout << "Input count of people" << endl;
	cin >> count_p;


	credit* info = new credit[count_p];
	savedata* info1 = new savedata[count_p];


	for (int i = 0; i < count_p; i++)

	{
		info[i].Last_name = new char[256];
		info[i].First_name = new char[256];

		info1[i].Last_name = new char[256];
		info1[i].First_name = new char[256];
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

		cout << "Input percent_" << i << "_" << endl;
		cin >> info[i].percent;

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
			info = (credit*)realloc(info, sizeof(credit)*count_p);
			info[count_p - 1] = add_credit();
			info1 = (savedata*)realloc(info1, sizeof(savedata)*count_p);
			info1[count_p - 1].First_name = new char[256];
			info1[count_p - 1].Last_name = new char[256];

			break;
		case 2:

			print_credit(info, count_p);

			break;

		case 3:

			cout << "Input Last_name" << endl;
			cin >> L_N;

			cout << "Input First_name" << endl;
			cin >> F_N;

			count_credit_b_L_N_and_F_N(info, count_p, L_N, F_N);


			break;

		case 4:
				cout << "Input percent" << endl;
				cin >> per ;

				same_percent(info, info1, count_p, per, saved_count);

				cout << "Printing saved data" << endl;
				print_savedata(info1, count_p);
				break;
		default:
			cout << "bb" << endl;
			break;
		}

	}

	

	system("pause>>0");
	return 0;
}






credit add_credit()
{

	credit info;

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

	info.percent = 0;
	cout << "Input percent_" << endl;
	cin >> info.percent;


	return(info);
}

void print_credit(credit* info, int count_p)
{
	cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;
	cout << "|--ID--| |-----Last_name----| |----First_name-----| |-----Summ-----| |percent|" << endl;
	cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;
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
		cout << "|" ;

		cout << " |";
		cout << setw(7) << left << info[i].percent;
		cout << "|" << endl;


		cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;



	}


}


void print_savedata(savedata* info1, int saved_count)
{
	
	cout << "|------------------| |-------------------|" << endl;
	cout << "|-----Last_name----| |----First_name-----|" << endl;
	cout << "|------------------| |-------------------|" << endl;
	for (int i = 0; i < saved_count; i++)
	{

		cout << " |";
		cout << setw(18) << left << info1[i].Last_name;
		cout << "|";

		cout << " |";
		cout << setw(19) << left << info1[i].First_name;

		cout << "|" << endl;


		cout << "|------------------| |-------------------|" << endl;
	}
}

void same_percent(credit* info, savedata* info1, int count_p, int per, int saved_count)
{

	cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;
	cout << "|--ID--| |-----Last_name----| |----First_name-----| |-----Summ-----| |percent|" << endl;
	cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;
	for (int i = 0; i < count_p; i++)
	{
		if (info[i].percent == per)
		{
			saved_count++;
			info1[i].Last_name = info[i].Last_name;
			info1[i].First_name = info[i].First_name;

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
			cout << "|" ;

			cout << " |";
			cout << setw(8) << left << info[i].percent;
			cout << "|" << endl;

			cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;



		}
	}

}




void count_credit_b_L_N_and_F_N(credit* info, int count_p, char* L_N, char* F_N)
{
	cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;
	cout << "|--ID--| |-----Last_name----| |----First_name-----| |-----Summ-----| |percent|" << endl;
	cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;
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
			cout << "|" ;

			cout << " |";
			cout << setw(8) << left << info[i].percent;
			cout << "|" << endl;

			cout << "|------| |------------------| |-------------------| |--------------| |-------|" << endl;




		}
	}

}
