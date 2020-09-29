#include <iostream>
#include <locale>
#include <cwchar>

#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include "FST.h"
#include "Out.h"
#include "LT.h"
using namespace std;


int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		//создаю таблицу лексем и таблицу идентификаторов
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, L"Тест:", L"без ошибок", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		LT::LexTable lextable = LT::Create(1);
		IT::IdTable idtable = IT::Create(1);
		In::IN in = In::getin(parm.in, lextable,idtable);
		LT::WriteInFile LTFile= LT::OpenStream();
		LT::WriteLexemTable(LTFile, lextable);
		Log::WriteIn(log, in);
		Out::OUT out = Out::getout(parm.out);
		Out::WriteAnalyze(out, in, log);
		Log::Close(log);
		Out::OutClose(out);
		delete[] in.text;			//Удаляем использованную память
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}

	return 0;
}