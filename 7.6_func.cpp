#include "7.6_func.h"

void addNode(Node*& head, Node*& tail, double num)
{
	Node* nv = new Node;
	nv->num = num;
	nv->next = NULL;
	nv->prev = NULL;
	if (!head)
	{
		head = nv;
		tail = nv;
	}
	else
	{
		nv->next = head;
		head->prev = nv;
		head = nv;
	}
}
double findMax(Node* head, Node* tail)
{
	double max;
	max = head->num + tail->num;
	while (head->next != tail)
	{
		head = head->next;
		tail = tail->prev;
		if (head->num + tail->num > max) max = head->num + tail->num;
	}
	return max;
}
void printListHead(Node* head)
{
	while (head)
	{
		cout << head->num << ' ';
		head = head->next;
	}
	cout << "\n";
}
