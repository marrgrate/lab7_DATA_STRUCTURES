//Выполнить задания, используя двусвязные динамические структуры данных в
//виде связных компонент. Оценить асимптотическую сложность алгоритма.

//10. Даны натуральное число n, действительные числа a1, a2, ..., a2n. Получить
//max(a1 + a2n, a2 + a2n−1,..., an + an + 1)
#include "7.6_func.h"

int main()
{
	Node* head = NULL, * tail = NULL;
	unsigned n;
	cout << "Enter any natural number:\t";
	cin >> n;
	
	for(int i = 0; i < 2 * n; ++i)
	{
		double d = rand() % 100;
		double value = rand() % 100 + 0 + 0.01 * d;
		addNode(head, tail, value);
	}
	printListHead(head);
	cout << "MAX = " << findMax(head, tail);
	return 0;
}