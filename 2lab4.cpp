#include <iostream>
#include <windows.h>
using namespace std;


int* func(int *array, int index, int size, int &point);

void main()
{
	int point = 0;
	int index;
	int size = 0;
	cout << "Size of array ";
	cin >> size;
	cout << endl << "index ";
	cin >> index;
	cout << endl;

	int *array = new int[size];
	int *new_array = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	cout << endl;

	new_array = func(array, index, size, point);

	for (int i = 0; i < point; i++) {
		cout << " " << new_array[i];
	}
	cout << endl;
	system("pause");
}

int* func(int *array,int index, int size, int &point)
{
	
	int *result = new int[size];
	for (int i = 0; i < index; i++) {
		if (array[i] > array[index]) {
			result[point] = array[i];
			point += 1;
		}

	}

	for (int i = index + 1; i < size; i++) {
		if (array[i] < array[index]) {
			result[point] = array[i];
			point += 1;
		}

	}
	return result;
}
