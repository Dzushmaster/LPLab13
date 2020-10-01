#include "Machines.h"
#include "IT.h"
#include "LT.h"

void inputToIdTable(IT::IdTable idtable, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId)//кажется, работает, но как записать туда значение, записанное в идентификаторе
{
	IT::Entry partOfTable;
	strncpy_s(partOfTable.id, word, 5);
	partOfTable.iddatatype = dataType;
	partOfTable.idxfirstLE = idtable.size + 1;
	partOfTable.idtype = typeofId(isTypeOfId);
	IT::Add(idtable, partOfTable);
	//форматированный вывод std::cout.width(5);
	//std::cout.setf(std::ios::left);
	std::cout << partOfTable.id << ": " << partOfTable.iddatatype << ": " << idtable.size << ": " << partOfTable.idtype << '\n';
}

void inputToLexTable(LT::LexTable lextable, int line, char lexem)//работает
{
	LT::Entry partOfTable;
	partOfTable.lexema = lexem;
	partOfTable.sn = line;
	partOfTable.idxTI = lextable.size + 1;
	LT::Add(lextable, partOfTable);
}

IT::IDTYPE typeofId(bool* isTypeOfId)//как определить, что это литерал или параметр
{
	if (isTypeOfId[0])			//переменная
		return IT::IDTYPE::V;
	if (isTypeOfId[1])			//функция
		return IT::IDTYPE::F;
	return IT::IDTYPE::P;
}


bool changingMachine(char* word, int line, LT::LexTable lextable, IT::IdTable idtable, FST::FST machine, int kindOfMachine)
{
	/*static bool isInteger = false;
	static bool isString = false;
	bool isFunction = false;
	bool isVariable = false;*/
	static bool b[4] = { false,false,false,false };
	//0 - Int
	//1 - Str
	//2 - Func
	//3 - Var
	if (!FST::execute(machine))
		return false;
	switch (kindOfMachine)
	{
	case 0:
		inputToLexTable(lextable, line, LEX_INTEGER);
		b[0]= true;
		return true;
	case 1:
		inputToLexTable(lextable, line, LEX_STRING);
		b[1] = true;
		return true;
	case 2:
		inputToLexTable(lextable, line, LEX_FUNCTION);
		b[2] = true;
		return true;
	case 3:
		inputToLexTable(lextable, line, LEX_DECLARE);
		b[3] = true;
		return true;
	case 4:
		inputToLexTable(lextable, line, LEX_RETURN);
		return true;
	case 5:
		inputToLexTable(lextable, line, LEX_PRINT);
		return true;
	case 6:
		if (b[0])
		{
			inputToIdTable(idtable, IT::IDDATATYPE::INT, word, b);
			b[0] = false;
			b[2] = false;
			b[3] = false;
			return true;
		}
		if (b[1])
		{
			inputToIdTable(idtable, IT::IDDATATYPE::STR, word, b);
			b[1] = false;
			b[2] = false;
			b[3] = false;
			return true;
		}
		break;
	case 7:
		break;
	default:
		break;
	}
}