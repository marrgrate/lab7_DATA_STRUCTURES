#pragma once
#include <iostream>
using namespace std;

struct Node
{
	double num;
	Node* next;
	Node* prev;
};
void addNode(Node*& head, Node*& tail, double num);
double findMax(Node* head, Node* tail);
void printListHead(Node* head);
