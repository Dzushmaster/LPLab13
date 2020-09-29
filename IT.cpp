#include "IT.h"
#include "Error.h"
using namespace IT;
IdTable IT::Create(int size)
{
	if (size > TI_MAXSIZE)
		throw ERROR_THROW(121);
	IdTable idtable;
	idtable.maxsize = TI_MAXSIZE;
	idtable.size = size;
	idtable.table = new Entry[TI_MAXSIZE];
	return idtable;
}
void IT::Add(IdTable& idtable, Entry entry)
{
	idtable.table[idtable.size++] = entry;
	if (idtable.size > TI_MAXSIZE)
		throw ERROR_THROW(121);
}
Entry IT::GetEntry(IdTable& idtable, int n)
{
	if (n > idtable.size)
		throw ERROR_THROW(116);
	return idtable.table[n];
}
//int IT::IsId(IdTable& idtable, char id[ID_MAXSIZE])
//{
//	idtable.table;
//}
void IT::Delete(IdTable& idtable)
{
	delete[] idtable.table;
}
