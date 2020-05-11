#include "7.2_func.h"

void initMatrix(float** A, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			A[i][j] = rand() % 10;
}
void initMatrix(float* A, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			A[i * size + j] = rand() % 10;
}
void printMatrix(float** A, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}
}
void printMatrix(float* A, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << A[i * size + j] << ' ';
		cout << endl;
	}
}
float calculateTrace(float** A, int size)
{
	float trace = 0;
	for (int i = 0, j = 0; i < size && j < size; ++i, ++j)
		trace += A[i][j];
	return trace;
}
float calculateTrace(float* A, int size)
{
	float trace = 0;
	for (int i = 0, j = 0; i < size && j < size; ++i, ++j)
		trace += A[i * size + j];
	return trace;
}
float** multMatrix(float** A, int size)
//matrixes multiplication
{
	float** B;
	B = new float* [size];
	for (int i = 0; i < size; ++i)
		B[i] = new float[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			B[i][j] = 0;
			for (int k = 0; k < size; k++)
				B[i][j] += A[i][k] * A[k][j];
		}
	return B;
}
float* multMatrix(float* A, int size)
//matrixes multiplication
{
	float* B = new float[size * size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			B[i * size + j] = 0;
			for (int k = 0; k < size; k++)
				B[i * size + j] += A[i * size + k] * A[k * size + j];
		}
	return B;
}
