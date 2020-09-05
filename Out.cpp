#include "Out.h"
#include "Error.h"
#include <time.h>
using namespace Out;
#define FST_STRUCT \
FST::NODE(1, FST::RELATION('a',1)),\
FST::NODE(1,FST::RELATION('f',2)),\
FST::NODE(4,FST::RELATION('g',2), FST::RELATION('b',3), FST::RELATION('c',3), FST::RELATION('d',3)), \
FST::NODE(1,FST::RELATION('f',4)),\
FST::NODE(5,FST::RELATION('e',6),FST::RELATION('g',5), FST::RELATION('b',3), FST::RELATION('c',3), FST::RELATION('d',3)), \
FST::NODE(2, FST::RELATION('e',6), FST::RELATION('g',5)),\
FST::NODE(1,FST::RELATION('f',7)),\
FST::NODE()

	OUT Out::getout(wchar_t outfile[])
	{
		OUT temp;
		temp.stream = new ofstream;
		temp.stream->open(outfile);
		if (!temp.stream->is_open())
		{
			temp.stream->close();
			throw ERROR_THROW(114);
		}
		wcscpy_s(temp.logfile, outfile);

		return temp;
	}
	void Out::WriteAnalyze(OUT out, In::IN in, Log::LOG log)//убрать лог, возможно, добавить отдельную функцию для анализа или просто улучш
	{
		int j=0;
		int chain = 0;
		*out.stream << "Начальные значения строк:" << IN_CODE_ENDL << in.text << IN_CODE_ENDL;

		time_t rawtime;
		struct tm timeinfo;								//структура хранящая текущее время
		char buffer[PARM_MAX_SIZE];
		time(&rawtime);									//текущая дата в секундах
		localtime_s(&timeinfo, &rawtime);				//текущее локальное время, представленное в структуре
		*out.stream << IN_CODE_ENDL << "----- Анализ ----- ";
		strftime(buffer, 300, " Дата: %d.%m.%Y %H:%M:%S", &timeinfo);
		*out.stream << buffer << " ----- " << IN_CODE_ENDL << IN_CODE_ENDL;
		while (!(in.text[j] == '\0'))
		{
			int i = 0;
			char* TextChain = new char[in.size];
			while (!(in.text[j] == '|'))
			{
				TextChain[i] = in.text[j];
				i++;
				j++;
			}
			TextChain[i] = '\0';
			chain++;
			j++;
			FST::FST fst((char*)TextChain, 8, FST_STRUCT);
			if (FST::execute(fst))
				*out.stream << "Цепочка " << TextChain <<" распознана" << IN_CODE_ENDL;
			else
			{
				*out.stream << "Цепочка № " << chain << ' ' <<TextChain << " не распознана, номер символа " << fst.position +1<<IN_CODE_ENDL;
				*log.stream << "Цепочка № " << chain << ' ' << TextChain << " не распознана, номер символа " << fst.position +1<<IN_CODE_ENDL;
			}
			delete[]TextChain;
		}
		
	}
	void Out::OutClose(OUT out)
	{
		out.stream->close();
		delete out.stream;
		out.stream = NULL;
	}
