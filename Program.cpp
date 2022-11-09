
#include "Master.h"
#include <windows.h>
#include <iostream>
#include <time.h>
using namespace std;

// Funkcja do ukrywania kursora okienka konsoli
//------------------------------------------------------
void CursorOff()
{
    CONSOLE_CURSOR_INFO Info;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    Info.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
};

// Funkcja do przywracania kursora okienka konsoli
//------------------------------------------------------
void CursorOn()
{
    CONSOLE_CURSOR_INFO Info;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    Info.bVisible = -1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
};


int  main()
 {
    Master gra;
    Grafika druk;
    CursorOff();
    do
    {
        gra.StronaTytulowa(druk);
        gra.Rozgrywka(druk);
    } while (gra.Kontynuacja(druk));
    druk.textattr(0x07); 
    CursorOn(); 
    druk.clrscr();
}

