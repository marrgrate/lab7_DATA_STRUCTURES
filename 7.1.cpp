//10. ��������� �������, ��������� ������������ ��������� ������ ��� ����������� �������.
//����(� ��������� �����) n > 1e9 ����������� �����(������ ����� >1e4)
//����������� �� ����� ������������ ������ 1 ��. �������� ������ �� ���� �������� ��������� �����:
//������������ �� ��������� ����������� ��������� ��������� ������ � ���� �� ����� 
//�� ����������� ��������;

#include <iostream>
#include <fstream>

#define n 1e4
using namespace std;

void initArray(bool* array);
void printArray(int* array, int size);

int main()
{
	/*���������� �����
	ofstream file1(, ios::in);
	for (unsigned int i = 0; i < 1e9; ++i)
		file1 << rand() % 10000 + 1 << endl;
	file1.close();*/

	fstream file("numbers.txt", ios::out);

	int number;
	bool* numbers = new bool[n];
	initArray(numbers);

	int cntr = 0;
	while (!file.eof() && cntr != n)
	{
		file >> number;
		if (!numbers[number])
		{
			numbers[number] = true;
			++cntr;
		}
	}
	int* new_array = new int[cntr];
	cout << endl;

	//������������ new_array
	int i = 0;
	for (int j = 0; j < n; j++)
		if (numbers[j])
		{
			new_array[i] = j;
			++i;
		}

	printArray(new_array, cntr);
	file.close();
	delete[] numbers;
	delete[] new_array;
	return 0;
}

void initArray(bool* array)
{
	for (int i = 0; i < n; ++i)
		array[i] = false;
}
void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << ' ';
}