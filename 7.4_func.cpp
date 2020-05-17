#include"7.4_func.h"

void addSymbol(Symbol*& top, char c)
{
	Symbol* nv = new Symbol;
	nv->c = c;
	nv->p = NULL;

	if (!top)
		top = nv;
	else
	{
		nv->p = top;
		top = nv;
	}
}

void printList(Symbol* s)
{
	if (!s) cout << "List is empty\n";
	while (s)
	{
		cout << s->c << ' ';
		s = s->p;
	}
	cout << endl;
}

bool func(Symbol*& L, Symbol* L1, Symbol* L2)
{
	Symbol* copy = new Symbol;
	copy = L;
	Symbol* p_first = new Symbol;
	Symbol* p_last = new Symbol;
	p_first = NULL;
	while (L1 && copy)
	{
		while(copy->c == L1->c)
		{
			copy = copy->p;
			L1 = L1->p;
			p_last = copy;
			if (!L1) 
			{
				replace(p_first, p_last, L2);
				while (L->p != p_first)
					L = L->p;
				L->p = p_first;
				return true;
			}
		}
		p_first = copy;
		copy = copy->p;
	}	
	return false;
}

void replace(Symbol*& first, Symbol*& last, Symbol* L2)
{
	first->p = L2;
	while (L2)
	{
		L2 = L2->p;
		if (!L2->p)
		{
			L2->p = last;
			break;
		}
	}
}
