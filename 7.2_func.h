#pragma once
#include <iostream>
using namespace std;

float calculateTrace(float** A, int size);
float calculateTrace(float* A, int size);
float** multMatrix(float** A, int size);
float* multMatrix(float* A, int size);
void initMatrix(float** A, int size);
void initMatrix(float* A, int size);
void printMatrix(float** A, int size);
void printMatrix(float* A, int size);