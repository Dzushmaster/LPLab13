#include "PrintTables.h"
std::ofstream CreateFileForLT()
{
	std::ofstream stream;
	stream.open("Table_Of_Lexem.txt");
	if (!stream.is_open())
		throw ERROR_THROW(114);
	return stream;
}
std::ofstream CreateFileForID()
{
	std::ofstream stream;
	stream.open("Table_Of_Identificators.txt");
	if (!stream.is_open())
		throw ERROR_THROW(114);
	return stream;
}

std::ofstream CreateFileForText()
{
	std::ofstream Filestream;
	Filestream.open("Text_After_Lex.txt");
	if (!Filestream.is_open())
		throw ERROR_THROW(114);
	return Filestream;
}

void PrintText(In::IN in)
{
	std::ofstream stream = CreateFileForText();
	
}
void PrintLTTable(LT::LexTable lextable)
{
	std::ofstream stream = CreateFileForLT();
	stream << "Размер таблицы лексем: ";
	stream << lextable.size;
	stream << "\nНомер лексемы -> Лексема -> Номер строки в исходном тексте\n";
	for (int i = 0; i < lextable.size; i++)
	{
		stream.width(6);
		stream << lextable.table[i].idxTI;
		stream.width(15);
		stream << lextable.table[i].lexema;
		stream.width(12);
		stream << lextable.table[i].sn;
		stream << '\n';
	}
}
void PrintIDTable(IT::IdTable idtable)
{
	std::ofstream stream = CreateFileForID();
	stream << "Размер таблицы идентификаторов: ";
	stream << idtable.size;
	stream << "\n";
	for (int i = 0; i < idtable.size; i++)
	{

		stream << i + 1;
		//stream.width(15);
		/*stream << idtable.table[i].prefix;
		stream << "::";*/
		stream << idtable.table[i].id;
		//stream.width(10);
		stream << PrintIddatatype(idtable.table[i].iddatatype);
		//stream.width(12);
		stream << PrintIdType(idtable.table[i].idtype);
		//stream.width(5);
		stream << idtable.table[i].idxfirstLE;
		//stream.width(7);
		stream << PrintValue(idtable);
		stream << '\n';
	}
}
//const char* PrintPrefix(IT::IdTable idtable)
//{
//	if (idtable.table->prefix == NULL)
//		return "";
//	char* ch = idtable.table->prefix;
//	return ;
//}
const char* PrintIddatatype(IT::IDDATATYPE datatype)
{
	if (datatype == IT::IDDATATYPE::INT)
		return "integer";
	if (datatype == IT::IDDATATYPE::STR)
		return "string";
}
const char* PrintIdType(IT::IDTYPE idtype)
{
	switch (idtype)
	{
	case 1:
		return "variable";
	case 2:
		return "function";
	case 3:
		return "parameter";
	case 4:
		return "literal";
	case 5:
		return "third party function";
	}
}
const char* PrintValue(IT::IdTable value)
{
	if (value.table->value.vint == TI_INT_DEFAULT)
		return "0";
	if (value.table->value.vstr->str == TI_STR_DEFAULT)
		return "0";
}