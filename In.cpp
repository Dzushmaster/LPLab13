#include "In.h"
#include "Error.h"
#include <fstream>
using namespace In;
IN In::getin(wchar_t inFile[])
{
	std::ifstream ifs;
	ifs.open(inFile);
	if (!ifs.is_open())
		throw ERROR_THROW(110);
	IN inF;
	inF.text = new unsigned char[IN_MAX_LEN_TEXT];
	char ch;
	unsigned char symb = ' ';
	int position = 0;
	while (true)
	{
		symb = ifs.get();
		if (ifs.eof())
		{
			inF.lines++;
			break;
		}
		/*if (inF.code[symb] == IN::F)
			throw ERROR_THROW_IN(111, inF.lines, position);*/
		if (inF.code[symb] == IN::T)
		{
			inF.text[inF.size] = symb;
			if (symb == IN_CODE_ENDL)
				inF.lines++;
			inF.size++;
		}
		else if (inF.code[symb] == IN::I)
			inF.ignor++;
		else if(inF.code[symb]=='!')
		{
			inF.text[inF.size] = inF.code[symb];
			inF.size++;
		}
		position++;
	}
	inF.lines++;
	inF.text[inF.size] = '\0';
	ifs.close();
	return inF;
}