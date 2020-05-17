#pragma once

#include <iostream>
using namespace std;

struct Symbol
{
	char c;
	Symbol* p;
};
void addSymbol(Symbol*& top, char c);
void printList(Symbol* s);
bool func(Symbol*& L, Symbol* L1, Symbol* L2);
void replace(Symbol*& first, Symbol*& last, Symbol* L2);
