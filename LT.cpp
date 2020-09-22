#include "LT.h"
#include "Error.h"
#include <iostream>
using namespace LT;
LexTable LT::Create(int size)//лексемы t, i, f и т.д.
{
	if (size > LT_MAXSIZE)
		throw ERROR_THROW(106);
	LexTable lextable;
	lextable.table = new Entry[size];
	lextable.maxsize = size;
	lextable.size = 0;
	return lextable;
}
void LT::Add(LexTable& lextable, Entry entry)
{
	if (strlen(entry.lexema) > LEXEMA_FIXSIZE)
		throw ERROR_THROW(115);
	lextable.table[lextable.size++] = entry;
}
Entry LT::GetEntry(LexTable& lextable, int n)
{
	if (n > lextable.size)
		throw ERROR_THROW(116);
	return lextable.table[n];
}
void LT::Delete(LexTable& lextable)
{
	delete[] lextable.table;
}