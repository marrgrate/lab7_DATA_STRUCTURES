#pragma once
#pragma once
#include <iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	string date_of_birth;
	unsigned int course; // 0 < course < 6
	float gpa; //grade point average
	Student* next;
};


int valid_input_age(int num);
int valid_input_course(int num);
float valid_input_gpa(float num);

void setData(Student& element);
void getAverage(Student* top, float &average);
void addNode(Student*& top, Student data);
void findEqual(Student* top, float key, Student*& ppv);
void menu();
void findGreaterThan(Student* top, string key, Student*& ppv);
void deleteNode(Student*& top, Student*& p);
void printList(Student* top);
