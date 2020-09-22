#pragma once
#include <iostream>
#define FST_INTEGER FST::NODE(1,FST::RELATION('i',1)),FST::NODE(1,FST::RELATION('n',2)),FST::NODE(1,FST::RELATION('t',3)),\
FST::NODE(1, FST::RELATION('e',4)), FST::NODE(1, FST::RELATION('g',5)), FST::NODE(1, FST::RELATION('e',6)), FST::NODE(1, FST::RELATION('r',7)), FST::NODE()
#define FST_STRING FST::NODE(1, FST::RELATION('s',1)), FST::NODE(1, FST::RELATION('t',2)), FST::NODE(1, FST::RELATION('r',3)),\
FST::NODE(1, FST::RELATION('i',4)), FST::NODE(1, FST::RELATION('n',5)), FST::NODE(1, FST::RELATION('g',6)), FST::NODE()
#define FST_FUNCTION FST::NODE(1, FST::RELATION('f',1)), FST::NODE(1, FST::RELATION('u',2)), FST::NODE(1, FST::RELATION('n',3)), FST::NODE(1, FST::RELATION('c',4)),\
FST::NODE(1, FST::RELATION('t', 5)), FST::NODE(1, FST::RELATION('i',6)), FST::NODE(1, FST::RELATION('o',7)), FST::NODE(1, FST::RELATION('n',8)), FST::NODE()
#define FST_DECLARE FST::NODE(1, FST::RELATION('d',1)), FST::NODE(1, FST::RELATION('e',2)), FST::NODE(1, FST::RELATION('c',3)),\
FST::NODE(1, FST::RELATION('l',4)), FST::NODE(1, FST::RELATION('a',5)), FST::NODE(1, FST::RELATION('r',6)), FST::NODE(1, FST::RELATION('e',7)), FST::NODE()
#define FST_RETURN FST::NODE(1, FST::RELATION('r',1)), FST::NODE(1, FST::RELATION('e',2)), FST::NODE(1, FST::RELATION('t',3)), FST::NODE(1, FST::RELATION('u',4)), FST::NODE(1, FST::RELATION('r',5)), FST::NODE(1, FST::RELATION('n',6)), FST::NODE()
#define FST_PRINT FST::NODE(1, FST::RELATION('p',1)), FST::NODE(1, FST::RELATION('r',2)), FST::NODE(1, FST::RELATION('i',3)), FST::NODE(1, FST::RELATION('n',4)), FST::NODE(1, FST::RELATION('t',5)), FST::NODE()
#define FST_MAIN FST::NODE(1,FST::RELATION('m',1)), FST::NODE(1,FST::RELATION('a',2)), FST::NODE(1,FST::RELATION('i',3)), FST::NODE(1,FST::RELATION('n',4))
#define FST_STRUCT \
FST::NODE(1, FST::RELATION('a',1)),\
FST::NODE(1,FST::RELATION('f',2)),\
FST::NODE(4,FST::RELATION('g',2), FST::RELATION('b',3), FST::RELATION('c',3), FST::RELATION('d',3)), \
FST::NODE(1,FST::RELATION('f',4)),\
FST::NODE(5,FST::RELATION('e',6),FST::RELATION('g',5), FST::RELATION('b',3), FST::RELATION('c',3), FST::RELATION('d',3)), \
FST::NODE(2, FST::RELATION('e',6), FST::RELATION('g',5)),\
FST::NODE(1,FST::RELATION('f',7)),\
FST::NODE()
namespace FST
{


	struct RELATION		//�����:������ -> ������� ����� ��������� ��
	{
		char symbol;	//������ ��������
		short nnode;	//����� ������� �������
		RELATION(char c=0x00, short ns=NULL);
	};
	struct NODE	//������� ����� ���������
	{
		short n_relation;//���������� ����������� �����
		RELATION* relations;//����������� �����
		NODE();
		NODE(short n, RELATION rel, ...);//���������� �����, ������ �����
	};
	struct FST
	{
		char* string;	//�������
		short position;
		short nstates;	//���������� ���������
		NODE* nodes;	//���� ���������
		short* rstates;//��������� ���������
		FST(char* s, short ns, NODE n, ...);
	};
	bool execute(FST& fst);
}