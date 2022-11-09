#define _CRT_SECURE_NO_WARNINGS

#include "napis.h"
#include <string.h>

napis::napis(const char* t) {
	tekst = new char[strlen(t) + 1];
	strcpy(tekst, t);
}

void napis::ustaw_napis(char* t) {
	delete[] tekst;
	tekst = new char[strlen(t) + 1];
	strcpy(tekst, t);
}

int napis::dlugosc_napisu() {
	int zwrot = strlen(tekst);
	return zwrot;
}

char* napis::zwroc_napis() {
	return tekst;
}
char* napis::konwersja_pl(char* s)
{
    int i;
    char c;
    char* temp = new char[strlen(s) + 1];
    strcpy(temp, s);
    int koniec = strlen(s);
    for (i = 0; i < koniec; i++)
    {
        switch (s[i])
        {
        case '¹': c = char(165); break;
        case 'æ': c = char(134); break;
        case 'ê': c = char(169); break;
        case '³': c = char(136); break;
        case 'ñ': c = char(228); break;
        case 'ó': c = char(162); break;
        case 'œ': c = char(152); break;
        case '¿': c = char(190); break;
        case 'Ÿ': c = char(171); break;
        case '¥': c = char(164); break;
        case 'Æ': c = char(143); break;
        case 'Ê': c = char(168); break;
        case '£': c = char(157); break;
        case 'Ñ': c = char(227); break;
        case 'Ó': c = char(224); break;
        case 'Œ': c = char(151); break;
        case '¯': c = char(189); break;
        case '': c = char(141); break;
        default:   c = s[i];
        };
        temp[i] = c;
    };
    return temp;
}
ostream& operator << (ostream& ekran, napis t) {
	
    cout << t.konwersja_pl(t.zwroc_napis());
	return ekran;
}

