//Выполнить задания, используя связанные динамические структуры данных в
//виде связных компонент. Оценить асимптотическую сложность алгоритма.

//10. Описать функцию, которая в списке символов L 
//заменяет первое вхождение списка L1(если такой есть) на список L2.

#include "7.4_func.h"

int main()
{
	Symbol* L = NULL;
	for (int i = 0; i < 15; i++)
		addSymbol(L, 'a' + i);
	Symbol* L1 = NULL, * L2 = NULL, * L3 = NULL ;
	for (int i = 0; i < 9; i++)
		addSymbol(L1, 'b' + i);
	for (int i = 0; i < 4; i++)
		addSymbol(L2, 'I');

	cout << "L:\t";
	printList(L);
	cout << "L1:\t";
	printList(L1);
	cout << "L2:\t";
	printList(L2);
	Symbol* p = new Symbol;
	p = L;
	bool result = func(p, L1, L2);

	if (!result)
		cout << "L doesn't contain L1" << endl;
	else
		printList(L);

	return 0;
}

