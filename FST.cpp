#include "FST.h"
namespace FST
{
	RELATION::RELATION(char c, short nn)
	{
		symbol = c;
		nnode = nn;
	}
	NODE::NODE()
	{
		n_relation = 0;
		RELATION* realtions = NULL;
	}
	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];
		for (short i = 0; i < n; i++)
			relations[i] = p[i];
	}
	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;
		nstates = ns;
		nodes = new NODE[ns];
		NODE* p = &n;
		for (int k = 0; k < ns; k++)
			nodes[k] = p[k];
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;
	}
	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					};
				};
		};
		return rc;
	};
	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short) * fst.nstates);
		short lstring = strlen(fst.string);
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		};
		delete[] rstates;
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	}
}
LT::Entry inputToLexTable(LT::LexTable lextable, In::IN in, char lexem)//работает
{
	LT::Entry partOfTable;
	partOfTable.lexema = lexem;
	partOfTable.sn = in.lines;
	partOfTable.idxTI = lextable.size+1;
	LT::Add(lextable,partOfTable);
	return partOfTable;
}
//полностью переделать функцию снизу
IT::Entry inputToIdTable(IT::IdTable idtable, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId)//кажется, работает, но как записать туда значение, записанное в идентификаторе
{
	IT::Entry partOfTable;
	strncpy_s(partOfTable.id, word,5);
	partOfTable.iddatatype = dataType;
	partOfTable.idxfirstLE = ++idtable.size;
	partOfTable.idtype = typeofId(isTypeOfId);
	//форматированный вывод std::cout.width(5);
	//std::cout.setf(std::ios::left);
	std::cout<< partOfTable.id << ": " << partOfTable.iddatatype << ": " << idtable.size << ": " << partOfTable.idtype << '\n';
	return partOfTable;
}
IT::IDTYPE typeofId(bool* isTypeOfId)//как определить, что это литерал или параметр
{
	if (isTypeOfId[0])			//переменная
		return IT::IDTYPE::V;
	if (isTypeOfId[1])			//функция
		return IT::IDTYPE::F;	
	if (!isTypeOfId[0])			//параметр
		return IT::IDTYPE::P;
}//сделать автомат для проверки чисел в идентификатор
void choiceOfMachines(int wordSize, In::IN in, LT::LexTable lextable, IT::IdTable idtable)//переработать функцию
{//попробовать в массиве вызывать функцию, и туда отправлять список автоматов
	// возможно добавить еще один кейс для = для нахождения литерала
	char* word = new char[wordSize];
	short sizeofText = in.size - wordSize - 1;
	for (int i = 0; i < wordSize; i++)
		word[i] = in.text[sizeofText + i];
	bool isLexeme = false;
	static bool isInteger = false;
	static bool isString = false;
	bool isTypeOfId[AMOUNTTYPES];//переменная, функция, литерал, параметр
	word[wordSize] = '\0';
	FST::FST fst0(word, wordSize + 1, FST_INTEGER);
	if (FST::execute(fst0))
	{
		*lextable.table++ = inputToLexTable(lextable, in, LEX_INTEGER);
		isInteger = true;
		isLexeme = true;
		return;
	}
	FST::FST fst1(word, wordSize + 1, FST_STRING);
	if (FST::execute(fst1))
	{
		*lextable.table++ = inputToLexTable(lextable, in, LEX_STRING);
		isString = true;
		isLexeme = true;
		return;
	}
	FST::FST fst2(word, wordSize + 1, FST_FUNCTION);
	if (FST::execute(fst2))
	{
		*lextable.table++ = inputToLexTable(lextable, in, LEX_FUNCTION);
		isLexeme = true;
		isTypeOfId[1] = true;
		return;
	}
	FST::FST fst3(word, wordSize + 1, FST_DECLARE);
	if (FST::execute(fst3))
	{
		*lextable.table++ = inputToLexTable(lextable, in, LEX_DECLARE);
		isLexeme = true;
		isTypeOfId[0] = true;
		return;
	}
	FST::FST fst4(word, wordSize + 1, FST_PRINT);
	if (FST::execute(fst4))
	{
		*lextable.table++ = inputToLexTable(lextable, in, LEX_PRINT);
		isLexeme = true;
		return;
	}
	FST::FST fst5(word, wordSize + 1, FST_RETURN);
	if (FST::execute(fst5))
	{
		*lextable.table++ = inputToLexTable(lextable, in, LEX_RETURN);
		isLexeme = true;
		return;
	}
	if (!isLexeme)//если не лексема, значит идентификатор
	{
		
		/*FST::FST fst6((char*)word[0], 2, FST_IDENTIFICATOR);
		if(!FST::execute(fst6))
			throw ERROR_THROW_IN(123,in.lines,sizeofText);*/
		
		if (isInteger)
		{
			idtable.table[idtable.size].idtype = IT::IDTYPE::P;
			inputToIdTable(idtable, IT::IDDATATYPE::INT, word, isTypeOfId);
			return;
		}
		if (isString)
		{
			idtable.table[idtable.size].idtype = IT::IDTYPE::P;
			inputToIdTable(idtable, IT::IDDATATYPE::STR, word,isTypeOfId);
			return;
		}
		//добавить еще элементов для function, и т.д.
	}
}