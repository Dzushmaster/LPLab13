#include "Machines.h"
#include "IT.h"
#include "LT.h"

int inputToIdTable(IT::IdTable idtable, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId)//кажетс€, работает, но как записать туда значение, записанное в идентификаторе
{
	IT::Entry partOfTable;
	strncpy_s(partOfTable.id, word, 5);
	partOfTable.iddatatype = dataType;
	partOfTable.idxfirstLE = idtable.size + 1;
	partOfTable.idtype = typeofId(isTypeOfId);
	IT::Add(idtable, partOfTable);
	//форматированный вывод std::cout.width(5);
	std::cout << partOfTable.id << ':' << partOfTable.iddatatype << ':' << partOfTable.idtype << ':' << partOfTable.idxfirstLE <<'\n';
	//std::cout.setf(std::ios::left);

	return idtable.size;
}

std::ofstream CreateFileForID()
{
	std::ofstream stream;
	stream.open("Table_Of_Identificators.txt");
	if (!stream.is_open())
		throw ERROR_THROW(114);
	return stream;
}


std::ofstream CreateFileForLT()
{
	std::ofstream stream;
	stream.open("Table_Of_Lexem.txt");
	if (!stream.is_open())
		throw ERROR_THROW(114);
	return stream;
}


int inputToLexTable(LT::LexTable lextable, int line, char lexem)//работает
{
	LT::Entry partOfTable;
	partOfTable.lexema = lexem;
	partOfTable.sn = line;
	partOfTable.idxTI = lextable.size + 1;
	LT::Add(lextable, partOfTable);
	return lextable.size;
}

IT::IDTYPE typeofId(bool* isTypeOfId)
{
	if (isTypeOfId[3])			//переменна€
		return IT::IDTYPE::V;
	if (isTypeOfId[2])			//функци€
		return IT::IDTYPE::F;
	if (isTypeOfId[3] && isTypeOfId[2] )
		return IT::IDTYPE::O;	//сторонн€€ функци€
	return IT::IDTYPE::P;		//параметр
}


bool changingMachine(char* word, int line, LT::LexTable lextable, IT::IdTable idtable, FST::FST machine, int kindOfMachine)
{
	static bool IntStrFunVar[4] = { false,false,false,false };
	//0 - Int
	//1 - Str
	//2 - Func
	//3 - Var
	static int lexSize = 0;
	static int idSize = 0;
	lextable.size = lexSize;
	idtable.size = idSize;
	if (!FST::execute(machine))
		return false;
	switch (kindOfMachine)
	{
	case 0:
		lexSize = inputToLexTable(lextable, line, LEX_INTEGER);
		IntStrFunVar[0]= true;
		return true;
	case 1:
		lexSize = inputToLexTable(lextable, line, LEX_STRING);
		IntStrFunVar[1] = true;
		return true;
	case 2:
		lexSize = inputToLexTable(lextable, line, LEX_FUNCTION);
		IntStrFunVar[2] = true;
		return true;
	case 3:
		lexSize = inputToLexTable(lextable, line, LEX_DECLARE);
		IntStrFunVar[3] = true;
		return true;
	case 4:
		lexSize = inputToLexTable(lextable, line, LEX_RETURN);
		return true;
	case 5:
		lexSize = inputToLexTable(lextable, line, LEX_PRINT);
		return true;
	case 6:
		if (IntStrFunVar[0])
		{
			idSize = inputToIdTable(idtable, IT::IDDATATYPE::INT, word, IntStrFunVar);
			IntStrFunVar[0] = false;
			IntStrFunVar[2] = false;
			IntStrFunVar[3] = false;
			return true;
		}
		if (IntStrFunVar[1])
		{
			idSize = inputToIdTable(idtable, IT::IDDATATYPE::STR, word, IntStrFunVar);
			IntStrFunVar[1] = false;
			IntStrFunVar[2] = false;
			IntStrFunVar[3] = false;
			return true;
		}
		break;
	case 7:
		idSize = inputToIdTable(idtable, IT::IDDATATYPE::)
		break;
	case 8:
		lexSize = inputToLexTable(lextable, line, LEX_MAIN);
		return true;
	default:
		break;
	}
}