//Создать связанную структуру данных – список. Разработать функции для
//выполнения базовых операций над линейными связанными структурами, 
//содержащими записи со сведениями о студентах : ФИО, дата рождения, курс, успеваемость.
//При добавлении элемента данных в список обеспечить упорядоченность по алфавиту фамилий.
//Оценить асимптотическую сложность алгоритма.

//10. По исходному списку определить студентов, имеющих средний бал успеваемости
//выше общего среднего бала. Сформировать список из этих студентов,
//удалив их из исходного списка.
#include "7.3_func.h"



int main()
{
	Student* top = NULL;
	Student new_item;
	unsigned int n;

	while (true)
	{
		menu();
		cin >> n;
		switch (n)
		{
		case 0: return 0;
		case 1:
		{
			setData(new_item);
			addNode(top, new_item); 
			break;
		}
		case 2:
		{
			printList(top);
			break;
		}
		case 3:
		{
			if (!top) 
			{
				cout << "List is empty\n"; 
				break;
			}
			Student* p = top;
			Student* prev = NULL;
			float average = 0;
			getAverage(top, average);
			cout << endl << "average = " << average << endl;

			while (p)
			{
				if (p->gpa < average)
					deleteNode(top, prev);
				prev = p;
				p = p->next;
			}
		}
		default: break;
		}

		system("pause");
		system("cls");
	}	
	return 0;
}


