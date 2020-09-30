#pragma once
#include <iostream>
#include "Error.h"
#include "In.h"
#include "LT.h"
#include "IT.h"

#define FST_INTEGER \
FST::NODE(1, FST::RELATION('i',1)),\
FST::NODE(1, FST::RELATION('n',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('e',4)),\
FST::NODE(1, FST::RELATION('g',5)),\
FST::NODE(1, FST::RELATION('e',6)),\
FST::NODE(1, FST::RELATION('r',7)),\
FST::NODE()

#define FST_STRING \
FST::NODE(1, FST::RELATION('s',1)),\
FST::NODE(1, FST::RELATION('t',2)),\
FST::NODE(1, FST::RELATION('r',3)),\
FST::NODE(1, FST::RELATION('i',4)),\
FST::NODE(1, FST::RELATION('n',5)),\
FST::NODE(1, FST::RELATION('g',6)),\
FST::NODE()

#define FST_FUNCTION \
FST::NODE(1, FST::RELATION('f',1)),\
FST::NODE(1, FST::RELATION('u',2)),\
FST::NODE(1, FST::RELATION('n',3)),\
FST::NODE(1, FST::RELATION('c',4)),\
FST::NODE(1, FST::RELATION('t', 5)),\
FST::NODE(1, FST::RELATION('i',6)),\
FST::NODE(1, FST::RELATION('o',7)),\
FST::NODE(1, FST::RELATION('n',8)),\
FST::NODE()

#define FST_DECLARE \
FST::NODE(1, FST::RELATION('d',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('c',3)),\
FST::NODE(1, FST::RELATION('l',4)),\
FST::NODE(1, FST::RELATION('a',5)),\
FST::NODE(1, FST::RELATION('r',6)),\
FST::NODE(1, FST::RELATION('e',7)),\
FST::NODE()

#define FST_RETURN \
FST::NODE(1, FST::RELATION('r',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('u',4)),\
FST::NODE(1, FST::RELATION('r',5)),\
FST::NODE(1, FST::RELATION('n',6)),\
FST::NODE()

#define FST_PRINT \
FST::NODE(1, FST::RELATION('p',1)),\
FST::NODE(1, FST::RELATION('r',2)),\
FST::NODE(1, FST::RELATION('i',3)),\
FST::NODE(1, FST::RELATION('n',4)),\
FST::NODE(1, FST::RELATION('t',5)),\
FST::NODE()




#define FST_IDENTIFICATOR \
FST::NODE(26, FST::RELATION('a',1),\
			  FST::RELATION('b',1),\
			  FST::RELATION('b',1),\
			  FST::RELATION('c',1),\
			  FST::RELATION('d',1),\
			  FST::RELATION('e',1),\
			  FST::RELATION('f',1),\
			  FST::RELATION('g',1),\
			  FST::RELATION('h',1),\
			  FST::RELATION('i',1),\
			  FST::RELATION('j',1),\
			  FST::RELATION('k',1),\
			  FST::RELATION('l',1),\
			  FST::RELATION('m',1),\
			  FST::RELATION('n',1),\
			  FST::RELATION('o',1),\
			  FST::RELATION('p',1),\
			  FST::RELATION('q',1),\
			  FST::RELATION('r',1),\
			  FST::RELATION('s',1),\
			  FST::RELATION('t',1),\
			  FST::RELATION('u',1),\
			  FST::RELATION('v',1),\
			  FST::RELATION('w',1),\
			  FST::RELATION('x',1),\
			  FST::RELATION('y',1),\
			  FST::RELATION('z',1)),\
FST::NODE()

namespace FST
{
	struct RELATION		//ребро:символ -> вершина графа переходов КА
	{
		char symbol;	//символ перехода
		short nnode;	//номер смежной вершины
		RELATION(char c=0x00, short ns=NULL);
	};
	struct NODE	//вершина графа переходов
	{
		short n_relation;//количество инцидентных ребер
		RELATION* relations;//инцидентные ребра
		NODE();
		NODE(short n, RELATION rel, ...);//количество ребер, список ребер
	};
	struct FST
	{
		char* string;	//цепочка
		short position;
		short nstates;	//количество состояний
		NODE* nodes;	//граф переходов
		short* rstates;//возможные состояния
		FST(char* s, short ns, NODE n, ...);
	};
	bool execute(FST& fst);
}
void choiceOfMachines(int wordSize, In::IN in, LT::LexTable lextable, IT::IdTable idtable);
void inputToLexTable(LT::LexTable lextable, In::IN in,char lexem);
void inputToIdTable(IT::IdTable idtable, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId);
IT::IDTYPE typeofId(bool* isTypeOfId);

