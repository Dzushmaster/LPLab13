#pragma once
#include "FST.h"

#define FST_INTEGER word,8,\
FST::NODE(1, FST::RELATION('i',1)),\
FST::NODE(1, FST::RELATION('n',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('e',4)),\
FST::NODE(1, FST::RELATION('g',5)),\
FST::NODE(1, FST::RELATION('e',6)),\
FST::NODE(1, FST::RELATION('r',7)),\
FST::NODE()

#define FST_STRING word, 7,\
FST::NODE(1, FST::RELATION('s',1)),\
FST::NODE(1, FST::RELATION('t',2)),\
FST::NODE(1, FST::RELATION('r',3)),\
FST::NODE(1, FST::RELATION('i',4)),\
FST::NODE(1, FST::RELATION('n',5)),\
FST::NODE(1, FST::RELATION('g',6)),\
FST::NODE()

#define FST_FUNCTION word, 9,\
FST::NODE(1, FST::RELATION('f',1)),\
FST::NODE(1, FST::RELATION('u',2)),\
FST::NODE(1, FST::RELATION('n',3)),\
FST::NODE(1, FST::RELATION('c',4)),\
FST::NODE(1, FST::RELATION('t', 5)),\
FST::NODE(1, FST::RELATION('i',6)),\
FST::NODE(1, FST::RELATION('o',7)),\
FST::NODE(1, FST::RELATION('n',8)),\
FST::NODE()

#define FST_DECLARE word, 8,\
FST::NODE(1, FST::RELATION('d',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('c',3)),\
FST::NODE(1, FST::RELATION('l',4)),\
FST::NODE(1, FST::RELATION('a',5)),\
FST::NODE(1, FST::RELATION('r',6)),\
FST::NODE(1, FST::RELATION('e',7)),\
FST::NODE()

#define FST_RETURN word, 7,\
FST::NODE(1, FST::RELATION('r',1)),\
FST::NODE(1, FST::RELATION('e',2)),\
FST::NODE(1, FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('u',4)),\
FST::NODE(1, FST::RELATION('r',5)),\
FST::NODE(1, FST::RELATION('n',6)),\
FST::NODE()

#define FST_PRINT word, 6,\
FST::NODE(1, FST::RELATION('p',1)),\
FST::NODE(1, FST::RELATION('r',2)),\
FST::NODE(1, FST::RELATION('i',3)),\
FST::NODE(1, FST::RELATION('n',4)),\
FST::NODE(1, FST::RELATION('t',5)),\
FST::NODE()



#define FST_NUMBLITERAL word,1,\
FST::NODE(11, FST::RELATION('1',0),\
			  FST::RELATION('2',0),\
			  FST::RELATION('3',0),\
			  FST::RELATION('4',0),\
			  FST::RELATION('5',0),\
			  FST::RELATION('6',0),\
			  FST::RELATION('7',0),\
			  FST::RELATION('8',0),\
			  FST::RELATION('9',0),\
			  FST::RELATION('0',0),\
			  FST::NODE())

#define FST_IDENTIFICATOR word, 1,\
FST::NODE(29, FST::RELATION('a',0),\
			  FST::RELATION('b',0),\
			  FST::RELATION('b',0),\
			  FST::RELATION('c',0),\
			  FST::RELATION('d',0),\
			  FST::RELATION('e',0),\
			  FST::RELATION('f',0),\
			  FST::RELATION('g',0),\
			  FST::RELATION('h',0),\
			  FST::RELATION('i',0),\
			  FST::RELATION('j',0),\
			  FST::RELATION('k',0),\
			  FST::RELATION('l',0),\
			  FST::RELATION('m',0),\
			  FST::RELATION('n',0),\
			  FST::RELATION('o',0),\
			  FST::RELATION('p',0),\
			  FST::RELATION('q',0),\
			  FST::RELATION('r',0),\
			  FST::RELATION('s',0),\
			  FST::RELATION('t',0),\
			  FST::RELATION('u',0),\
			  FST::RELATION('v',0),\
			  FST::RELATION('w',0),\
			  FST::RELATION('x',0),\
			  FST::RELATION('y',0),\
			  FST::RELATION('z',0),\
			  FST::RELATION('_',0),\
			  FST::NODE())
//добавлять main или нет
//#define FST_MAIN word,5,\
//FST::NODE(1, FST::RELATION('m',1)),\
//FST::NODE(1, FST::RELATION('a',2)),\
//FST::NODE(1, FST::RELATION('i',3)),\
//FST::NODE(1, FST::RELATION('n',4)),\
//FST::NODE()

#define AMOUNTLEXEM 8
#define ALL_MACHINES \
FST::FST Integer(FST_INTEGER);\
FST::FST String(FST_STRING);\
FST::FST Function(FST_FUNCTION);\
FST::FST Declare(FST_DECLARE);\
FST::FST Return(FST_RETURN);\
FST::FST Print(FST_PRINT);\
FST::FST Identificator(FST_IDENTIFICATOR);\
FST::FST NumberLiteral(FST_NUMBLITERAL);\
FST::FST CHOOSINGMACHINE[AMOUNTLEXEM] = {Integer, String, Function, Declare, Return, Print, Identificator,NumberLiteral};

bool changingMachine(char* word, int line, LT::LexTable lextable, IT::IdTable idtable, FST::FST machine, int kindOfMachine);
void inputToIdTable(IT::IdTable idtable, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId);
void inputToLexTable(LT::LexTable lextable, int line, char lexem);
IT::IDTYPE typeofId(bool* isTypeOfId);