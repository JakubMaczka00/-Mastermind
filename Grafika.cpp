#include "Grafika.h"
#include <iostream>
#include <conio.h>

Grafika::Grafika():Czarny(0),Niebieski(1),Zielony(2),Morski(3),Czerwony(4),
                   Fiolet(5),Brazowy(6),Jasnoszary(7),Ciemnoszary(8),
                   Jasnoniebieski(9),Jasnozielony(10),Jasnomorski(11),
                   Jasnoczerwony(12),Jasnofioletowy(13),Zolty(14),Bialy(15)
{
  __BACKGROUND = Czarny;
  __FOREGROUND = Jasnoszary;
}

// Funkcja do ustawiania koloru tekstu
//----------------------------------------------------
void Grafika::textcolor(int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        color + (__BACKGROUND << 4));
}

// Funkcja do ustawiania koloru t³a wydruku
//----------------------------------------------------
void Grafika:: textbackground(int color)
{
    __BACKGROUND = color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        __FOREGROUND + (color << 4));
}
// Funkcja do ustawiania atrybutów koloru tekstu i t³a
//----------------------------------------------------
void Grafika:: textattr(int _attr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _attr);
}

// Funkcja do ustawiania pozycji wydruku w oknie konsoli
//----------------------------------------------------
void Grafika::gotoxy(int x, int y)
{
    COORD poz;
    poz.X = x-1;
    poz.Y = y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), poz);
}
// Funkcja do zwracania aktualnej pozycji x kursora
//----------------------------------------------------
int Grafika:: kursor_pozycja_x()
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.dwCursorPosition.X + 1;
}

// Funkcja do zwracania aktualnej pozycji y kursora
//----------------------------------------------------
int Grafika:: kursor_pozycja_y()
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.dwCursorPosition.Y + 1;
}
void Grafika::clrscr()
{
    DWORD written;
    static COORD Home = { 0, 0 };

    FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        __FOREGROUND + (__BACKGROUND << 4), 10000, Home, &written);
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
        10000, Home, &written);
    gotoxy(1, 1);
}
//----------------------------------------------------
// Funkcja do rysowania pojedynczej ramki ze znaków
//----------------------------------------------------------------------------
void Grafika::Ramka(int xp, int yp, int xk, int yk)
{
    int i;

    gotoxy(xp, yp); cout << char(218);
    gotoxy(xp, yk); cout << char(192);
    gotoxy(xk, yp); cout << char(191);
    gotoxy(xk, yk); cout << char(217);
    for (i = xp + 1; i <= xk - 1; i++)
    {
        gotoxy(i, yp); cout << char(196);
        gotoxy(i, yk); cout << char(196);
    };
    for (i = yp + 1; i <= yk - 1; i++)
    {
        gotoxy(xp, i); cout << char(179);
        gotoxy(xk, i); cout << char(179);
    };
}
// Funkcja do centrowania w bie¿¹cym wierszu tekstu podanego jako parametr
//-------------------------------------------------------------------------
void Grafika::Centrowanie(napis t)
{
    gotoxy(1 + (80 - t.dlugosc_napisu()) / 2, kursor_pozycja_y());
    cout << t << endl;
}
