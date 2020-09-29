#include "LT.h"
#include "Error.h"

using namespace LT;
LexTable LT::Create(int size)//лексемы t, i, f и т.д.
{
	LexTable lextable;
	lextable.table = new Entry[size];
	lextable.maxsize = size;
	lextable.size = 0;
	return lextable;
}
void LT::Add(LexTable& lextable, Entry entry)
{
	lextable.table[lextable.size] = entry;
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
LT::WriteInFile LT::OpenStream()
{
	WriteInFile stream;
	stream.stream = new std::ofstream;
	stream.stream->open(stream.nameOfFile);
	if (!stream.stream->is_open())
		throw ERROR_THROW(113);
	return stream;
}
//переделать
//void LT::WriteLexemTable(WriteInFile writeFile, LexTable lextable)
//{
//	*writeFile.stream << "№ идентификатора\tИдентификатор\tТип данных\tТип идентификатора\tИндекс в ТЛ\tЗначение\n";
//	for (int i = 0; i <= lextable.size; i++)
//	{
//		*writeFile.stream << i <<' '<<lextable.table[i].lexema<<' '<< lextable.table[i].sn <<' '<<lextable.table[i].idxTI;
//		*writeFile.stream << '\n';
//	}
//}