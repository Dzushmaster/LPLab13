#include "Error.h"
#include "In.h"
#include "FST.h"
#include <fstream>
#include "LT.h"
using namespace In;
//если нельз€ разобрать автоматом, то идентификатор
IN In::getin(wchar_t inFile[])
{
	std::ifstream FileIn(inFile);
	if (!FileIn.is_open())
		throw ERROR_THROW(110);
	unsigned char Uch;
	IN in;
	in.text = new unsigned char[IN_MAX_LEN_TEXT];
	int CurrentPosition = 0;
	int wordSize = 0;
	LT::LexTable* lt = new LT::LexTable();
	IT::IdTable* id = new IT::IdTable();
	for (;;)//проверка символов на разрешенность
	{
		Uch = FileIn.get();
		if (FileIn.eof())
			break;
		static bool isSpace = false;
		static bool isExpression = false;
		static bool isWord = false;
		switch (in.code[Uch])
		{
		case IN::F:
		{
			Error::ERROR x;
			x.inext.line = in.lines;
			x.inext.col = CurrentPosition;
			throw ERROR_THROW_IN(111, x.inext.line, x.inext.col);
			break;
		}
		case IN::I:
			in.ignor++;
			in.size--;
			isExpression = false;
			isWord = false;
			isSpace = false;
			break;
		case IN::T:
		{
			wordSize++;
			in.text[in.size] = Uch;//текущий символ
			isExpression = false;
			isSpace = false;
			isWord = true;
			in.size++;
			CurrentPosition++;
			break;
		}
		case IN::S:
		{
			isWord = false;
			if (isSpace)
			{
				in.ignor++;
				break;
			}
			else
			{
				isSpace = true;
				in.text[in.size++] = Uch;
				CurrentPosition++;
			}
			if (isExpression)
				in.size--;
			break;
		}
		case IN::E://¬ыражени€
		{
			isWord = false;
			isSpace ? (in.text[in.size - 1] = Uch, isSpace = false, in.ignor++) : (in.text[in.size] = Uch, CurrentPosition++, in.size++);
			isExpression = true;
			break;
		}
		case IN::Q:
		{
			isWord = false;
			bool isQuote = false;//наличие первой кавычки
			while (true)
			{
				in.text[in.size++] = Uch;
				Uch = FileIn.get();
				if (FileIn.eof())
					break;
				if (Uch == '\'')
				{
					in.text[in.size++] = Uch;
					isQuote = true;
					break;
				}
				else if (Uch == '\n' && !isQuote)
					throw ERROR_THROW_IN(105, in.lines, CurrentPosition);
			}
			break;
		}
		default:
			in.text[in.size] = in.code[Uch];
			in.lines++;
			CurrentPosition = 0;
			in.size++;
			isWord = false;
			break;
		}
		if (!isWord)
		{
			choiceOfMachines(wordSize,in, *lt, *id);//дл€ выбора автоматов
			wordSize = 0;
		}

	}
	in.text[in.size] = '\0';
	FileIn.close();
	return in;
}