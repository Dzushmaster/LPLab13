#include "FST.h"
#include <vector>
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
void inputToLexTable(LT::LexTable lextable, In::IN in, char lexem)
{
	lextable.table[lextable.size].lexema[0] = lexem;
	lextable.table[lextable.size].idxTI = lextable.size;
	lextable.table[lextable.size++].sn = in.lines;
}
void choiceOfMachines(int wordSize, In::IN in, LT::LexTable lextable, IT::IdTable idtable)
{
	char* word = new char[wordSize];
	short sizeofText = in.size - wordSize-1;
	for (int i = 0; i < wordSize; i++)
		word[i] = in.text[sizeofText + i];
	FST::FST fst(word, wordSize+1, FST_INTEGER);
	bool isLexeme = false;
	static bool isInteger = false;
	static bool isString = false;
	word[wordSize] = '\0';
	if (FST::execute(fst))
	{
		inputToLexTable(lextable, in, LEX_INTEGER);
		isInteger = true;
		isLexeme = true;
		return;
	}
	FST::FST fst(word, wordSize + 1, FST_STRING);
	if (FST::execute(fst))
	{
		inputToLexTable(lextable, in, LEX_STRING);
		isString = true;
		isLexeme = true;
		return;
	}
	FST::FST fst(word, wordSize + 1, FST_FUNCTION);
	if (FST::execute(fst))
	{
		inputToLexTable(lextable, in, LEX_FUNCTION);
		isLexeme = true;
		return;
	}
	FST::FST fst(word, wordSize + 1, FST_DECLARE);
	if (FST::execute(fst))
	{
		inputToLexTable(lextable, in, LEX_DECLARE);
		isLexeme = true;
		return;
	}
	FST::FST fst(word, wordSize + 1, FST_PRINT);
	if (FST::execute(fst))
	{
		inputToLexTable(lextable, in, LEX_PRINT);
		isLexeme = true;
		return;
	}
	FST::FST fst(word, wordSize + 1, FST_RETURN);
	if (FST::execute(fst))
	{
		inputToLexTable(lextable, in, LEX_RETURN);
		isLexeme = true;
		return;
	}
	//if (!isLexeme)//если не литерал, значит идентификатор
	//{
	//	if (isString)
	//	{
	//		idtable.table[lextable.size].iddatatype = IT::IDDATATYPE::INT;
	//		idtable.table[lextable.size].
	//	}
	//	if(isInteger)
	//		idtable.table[lextable.size].iddatatype = IT::IDDATATYPE::STR;
	//	//добавить еще элементов для function, и т.д.
	//}
}