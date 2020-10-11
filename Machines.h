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

#define FST_MAIN word, 5,\
FST::NODE(1,FST::RELATION('m',1)),\
FST::NODE(1,FST::RELATION('a',2)),\
FST::NODE(1,FST::RELATION('i',3)),\
FST::NODE(1,FST::RELATION('n',4)),\
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
FST::NODE(28, FST::RELATION('a',0),\
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
			  FST::NODE())

#define FST_STRLITERAL word,4,\
FST::NODE(1, FST::RELATION('\'',0)),\
FST::NODE(37, FST::RELATION('a',1),\
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
			  FST::RELATION('z',1),\
			  FST::RELATION('A',1),\
			  FST::RELATION('B',1),\
			  FST::RELATION('C',1),\
			  FST::RELATION('D',1),\
			  FST::RELATION('E',1),\
			  FST::RELATION('F',1),\
			  FST::RELATION('G',1),\
			  FST::RELATION('H',1),\
			  FST::RELATION('I',1),\
			  FST::RELATION('J',1),\
			  FST::RELATION('K',1),\
			  FST::RELATION('L',1),\
			  FST::RELATION('M',1),\
			  FST::RELATION('N',1),\
			  FST::RELATION('O',1),\
			  FST::RELATION('P',1),\
			  FST::RELATION('Q',1),\
			  FST::RELATION('R',1),\
			  FST::RELATION('S',1),\
			  FST::RELATION('T',1),\
			  FST::RELATION('U',1),\
			  FST::RELATION('V',1),\
			  FST::RELATION('W',1),\
			  FST::RELATION('X',1),\
			  FST::RELATION('Y',1),\
			  FST::RELATION('Z',1),\
			  FST::RELATION('1',1),\
			  FST::RELATION('2',1),\
			  FST::RELATION('3',1),\
			  FST::RELATION('4',1),\
			  FST::RELATION('5',1),\
			  FST::RELATION('6',1),\
			  FST::RELATION('7',1),\
			  FST::RELATION('8',1),\
			  FST::RELATION('9',1),\
			  FST::RELATION('0',1),\
			  FST::RELATION(' ',1),\
			  FST::RELATION('&',1),\
			  FST::RELATION('!',1),\
			  FST::RELATION('@',1),\
			  FST::RELATION('#',1),\
			  FST::RELATION('$',1),\
			  FST::RELATION('%',1),\
			  FST::RELATION('^',1),\
			  FST::RELATION('*',1),\
			  FST::RELATION('(',1),\
			  FST::RELATION(')',1),\
			  FST::RELATION(':',1),\
			  FST::RELATION(';',1),\
			  FST::RELATION('"',1),\
			  FST::RELATION('-',1),\
			  FST::RELATION('+',1),\
			  FST::RELATION('=',1),\
			  FST::RELATION('*',1),\
			  FST::RELATION('?',1),\
			  FST::RELATION('.',1),\
			  FST::RELATION(',',1),\
			  FST::RELATION('>',1),\
			  FST::RELATION('<',1)),\
FST::NODE(1,FST::RELATION('\'',2)),\
FST::NODE()

#define SEMICOLON word,1,\
FST::NODE(1,FST::RELATION(';',0),\
			FST::NODE())

#define COMMA word,1,\
FST::NODE(1,FST::RELATION(',',0),\
			FST::NODE())

#define LEFTBRACE word,1,\
FST::NODE(1,FST::RELATION('{',0),\
			FST::NODE())

#define BRACELEFT word,1,\
FST::NODE(1,FST::RELATION('}',0),\
			FST::NODE())

#define LEFTHESIS word,1,\
FST::NODE(1,FST::RELATION('(',0),\
			FST::NODE())

#define REIGHTHESIS word,1,\
FST::NODE(1,FST::RELATION(')',0),\
			FST::NODE())

#define PLUS word,1,\
FST::NODE(1,FST::RELATION('+',0),\
			FST::NODE())

#define MINUS word,1,\
FST::NODE(1,FST::RELATION('-',0),\
			FST::NODE())

#define STAR word,1,\
FST::NODE(1,FST::RELATION('*',0),\
			FST::NODE())

#define DIRSLASH word,1,\
FST::NODE(1,FST::RELATION('/',0),\
			FST::NODE())

#define EQUALS word, 1,\
FST::NODE(1, FST::RELATION('=',0),\
			 FST::NODE())

#define AMOUNTLEXEM 21
#define ALL_MACHINES \
FST::FST Integer(FST_INTEGER);\
FST::FST String(FST_STRING);\
FST::FST Function(FST_FUNCTION);\
FST::FST Declare(FST_DECLARE);\
FST::FST Return(FST_RETURN);\
FST::FST Print(FST_PRINT);\
FST::FST Identificator(FST_IDENTIFICATOR);\
FST::FST NumberLiteral(FST_NUMBLITERAL);\
FST::FST Main(FST_MAIN);\
FST::FST STRLiteral(FST_STRLITERAL);\
FST::FST Braceleft(BRACELEFT); \
FST::FST Leftbrace(LEFTBRACE);\
FST::FST Semicolon(SEMICOLON);\
FST::FST Comma(COMMA);\
FST::FST Lefthesis(LEFTHESIS);\
FST::FST Reighthesis(REIGHTHESIS);\
FST::FST Plus(PLUS);\
FST::FST Minus(MINUS);\
FST::FST Star(STAR);\
FST::FST Dirslash(DIRSLASH);\
FST::FST Equals(EQUALS);\
FST::FST CHOOSINGMACHINE[AMOUNTLEXEM] = {Integer, String, Function, Declare, Return, Print,Main,NumberLiteral,STRLiteral,Identificator, Braceleft,Leftbrace, Semicolon,Comma, Lefthesis, Reighthesis, Plus, Minus, Star, Dirslash,Equals};

bool changingMachine(char* word, In::IN in , LT::LexTable& lextable, IT::IdTable& idtable, FST::FST machine, int kindOfMachine);
int inputToIdTable(IT::IdTable& idtable,In::IN in, IT::IDDATATYPE dataType, char* word, bool* isTypeOfId, bool&);
int inputToIdTable(IT::IdTable& idtable,In::IN in ,IT::IDDATATYPE dataType, char* word, IT::IDTYPE);
void DefineScope(IT::Entry&, bool&, bool*);
int inputToLexTable(LT::LexTable& lextable, In::IN in, char lexem);
IT::IDTYPE typeofId(bool* isTypeOfId);