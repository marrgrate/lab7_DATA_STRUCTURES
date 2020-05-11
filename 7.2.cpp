//��������� �������, ��������� ������������ ��������� ������ ��� ���������� �������, 
//����� ��������� :
//� �������� ��������� ������ ��� ����������, � �������� �������� �������� ������� �� �������� �������;
//� �������� ��������� ������ ��� ��������� �� ������ ����������.

// ���� ������������ ���������� ������� � ������� m, ����������� ����� n.
//��������� ������� ��� ��������� ����� ������ ������ �, �2, � �n.
#include"7.2_func.h"

int main()
{
	int size = 3;	
	unsigned n;
	cout << "Enter natural number\t";
	cin >> n;

//-----------------��������� ������---------------//
	float** A;
	A = new float* [size];
	for (int i = 0; i < size; ++i)
		A[i] = new float[size];

	initMatrix(A, size);
	printMatrix(A, size);

	unsigned degree = 1;
	float sum;
	sum = calculateTrace(A, size);
	cout << "Degree: " << degree << '\t' << sum << endl << endl;
	while (degree < n)
	{
		A = multMatrix(A, size);
		printMatrix(A, size);
		sum += calculateTrace(A, size);
		cout << "Degree: " << degree << '\t' << sum << endl << endl;
		degree++;
	}
	for (int i = 0; i < size; i++)
		delete A[i];
	delete[] A;
//-----------------���������� ������----------------//
	cout << "\n________________________________\n";
	float* B = new float[size*size];
	initMatrix(B, size);
	
	for (int i = 0; i < size * size; i++)
		cout << B[i] << ' ';
	cout << endl << endl;
	printMatrix(B, size);
	cout << endl;
	

	degree = 1;
	sum = 0;
	sum = calculateTrace(B, size);
	cout << "Degree: " << degree << '\t' << sum << endl << endl;

	while (degree < n)
	{
		B = multMatrix(B, size);
		printMatrix(B, size);
		sum += calculateTrace(B, size);
		cout << "Degree: " << degree << '\t' << sum << endl << endl;
		degree++;
	}
	delete[] B;
}

