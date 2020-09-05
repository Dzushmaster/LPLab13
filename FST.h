#pragma once
#include <iostream>
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