#pragma warning(disable : 4996).    //dyrektywa dla funkcji getch ()

#include "Kod_gracza.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

// Funkcja do wyœwietlania kodu tab_kolorow,
// z której korzysta obiekt kodu gracza.
//------------------------------------------------------
void Kod_gracza::Wyswietl(int runda, int kursor)
{
    int y;

    y = kursor_pozycja_y(); // zapamiêtujemy pozycjê wydruku
    textattr(0x87); gotoxy(1, y);
    Centrowanie("                    ");
    gotoxy(31, kursor_pozycja_y()); cout << " " << runda << ": ";
    Kod_bazy::Wyswietl(Grafika());  // do wyœwietlenia kodu wykorzystujemy
                           // odziedziczon¹ metodê
    cout << "        \n";
    textattr(0x80); Centrowanie("____________________");
    if (kursor >= 0)
    {
        textattr(0x84); Ramka(34 + 2 * kursor, y, 36 + 2 * kursor, y + 2);
    };
    gotoxy(1, y);  // odtwarzamy pozycjê wydruku
}

// Funkcja do odczytu kodu koloru gracza.
//------------------------------------------------------
void Kod_gracza::Inicjuj(int runda)
{
    int x, i;
    char c;

    for (i = 0; i <= 3; i++) tab_kolorow[i] = 0;
    x = 0;
    do
    {
        Wyswietl(runda, x);
        do
        {
            c = getch();
        } while (c == '\0');
        Wyswietl(runda, -1); // usuwanie kursor z ekranu
        switch (c)
        {
            case char(75) : x = (x + 3) % 4; break;         //strza³ka w lewo
                case char(77) : x = (x + 1) % 4; break;         //strza³ka w prawo
                    case char(72) : tab_kolorow[x] = (tab_kolorow[x] + 1) % 6; break; //strza³ka w górê
                        case char(80) : tab_kolorow[x] = (tab_kolorow[x] + 5) % 6; break; //strza³ka w dó³
        };
    } while (int(c) != 13); // klawisz Enter
}