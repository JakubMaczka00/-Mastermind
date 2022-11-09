#pragma once
#include <iostream>
using namespace std;

class napis
{
	char* tekst;
public:
	napis(const char* t);
	char* konwersja_pl(char* s);
	void ustaw_napis(char* t);
	char* zwroc_napis();
	int dlugosc_napisu();
	friend  ostream& operator << (ostream& ekran, napis t);
};