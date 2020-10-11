#pragma once
#include "LT.h"
#include "IT.h"
#include "Error.h"
#include "In.h"
void PrintLTTable(LT::LexTable);
void PrintIDTable(IT::IdTable);
void PrintText(In::IN in);
const char* PrintIdType(IT::IDTYPE idtype);
const char* PrintIddatatype(IT::IDDATATYPE datatype);
const char* PrintValue(IT::IdTable value);
const char* PrintPrefix(IT::IdTable value);
std::ofstream CreateFileForLT();
std::ofstream CreateFileForID();
std::ofstream CreateFileForText();