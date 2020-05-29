#include "7.3_func.h"

int validInputAge(int num)
{
	int counter = 3;
	while (counter)
	{
		cin >> num;
		if (cin && num < 50 && num > 15) return num;
		counter--;
		cin.clear();
		rewind(stdin);
		cout << "incorrect input. try again\t" << endl;
	}
	return num;
}
int validInputCourse(int num)
{
	int counter = 3;
	while (counter)
	{
		cin >> num;
		if (cin && num > 0 && num < 6) return num;
		counter--;
		cin.clear();
		rewind(stdin);
		cout << "incorrect input. try again\t" << endl;
	}
	return num;
}
float validInputGpa(float num)

{
	int counter = 3;
	while (counter)
	{
		cin >> num;
		if (cin && num >= 0 && num <= 10) return num;
		counter--;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Incorrect input. try again\t" << endl;
	}
	return num;
}
void menu()
{
	cout << "MENU\n"
		<< "\t0 - Finish program\n"
		<< "\t1 - Add new element\n"
		<< "\t2 - Show list\n"
		<< "\t3 - Delete students with low GPA\n"
		<< "\t4 - Delete list\n";
}
void setData(Student& element)
{
	rewind(stdin);
	cout << "\nEnter student's name and surname\t";
	getline(cin, element.name);
	cout << "\nDate of birth\t";
	getline(cin, element.date_of_birth);
	cout << "\nCourse\t";
	element.course = validInputCourse(element.course = 0);
	cout << "\nGrage Point Average\t";
	element.gpa = validInputGpa(element.gpa = 0);
	system("cls");
}

void getAverage(Student* top, float& average)
{
	Student* p = top;
	unsigned counter = 0;
	while (p)
	{
		average += p->gpa;
		counter++;
		p = p->p;
	}
	average /= counter;
}

//функция занесения элемента c ключом key в список
// по возрастанию ключей
// top - указатель начала списка
void addNode(Student*& top, Student data)
{
	Student* p = NULL;
	Student* temp = new Student;
	temp->name = data.name;
	temp->date_of_birth = data.date_of_birth;
	temp->course = data.course;
	temp->gpa = data.gpa;
	temp->p = NULL;

	if (!top)
		top = temp;
	else
	{
		if (top->name >= data.name)
		{
			temp->p = top;
			top = temp;
		}
		else
		{
			findGreaterThan(top, data.name, p);
			// поиск по ключу места для нового элемента
			temp->p = p->p;
			// вставляем между элементами с адресами p и top
			p->p = temp;
		}
	}
}
// функция нахождения элемента c ключом >key
// top - адрес начала списка
// ppv - адрес элемента списка, указывающего на найденный
void findGreaterThan(Student* top, string key, Student*& ppv)
{
	Student* pv = top;
	ppv = top;
	//поиск элемента c ключом > key
	while (pv && pv->name <= key)
	{
		ppv = pv; // запоминаем адрес предыдущего элемента
		pv = pv->p;
	}
}
Student* deleteNode(Student*& node, float key)
{
		Student* pv, * ppv;
		findEqual(node, key, ppv);
		pv = ppv->p;
		if (pv)
		{
			if (node->gpa == key)
			{			
				node = node->p;
				return node;
			}
			else
				ppv->p = pv->p;
			delete pv;
		}
		return ppv;
}
void deleteList(Student*& top)
{
	Student* p;
	while (top)
	{
		p = top->p;
		delete top;
		top = p;
	}
}
void findEqual(Student* top, float key, Student*& ppv)
{
	Student* pv = top;
	ppv = top;
	while (pv && pv->gpa != key)
	{
		ppv = pv;
		pv = pv->p;
	}
}

void printList(Student* top)
{
	if (top == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	cout << "NAME\t\tDATE OF BIRTH\tCOURSE\tGPA\n";
	while (top)
	{
		cout << top->name << '\t' << top->date_of_birth << "\t\t"
			<< top->course << '\t' << top->gpa << endl;
		top = top->p;
	}
	cout << "\n";
}
