#pragma warning(disable : 4996) .

#include "Master.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;


Master::Master()
{
 runda=0;
}
void Master::Ocen_gracza(Grafika druk)
{
    druk.gotoxy(43, druk.kursor_pozycja_y() + 1); // ustawiamy pozycj� oceny
    baza.Sprawdzaj(gracz.tab_kolorow);          // oceniamy kod gracza
    cout << endl << endl;     // przechodzimy do nast�pnego segmentu
}

// Metoda por�wnuje obiekty
//------------------------------------------------------
int Master::gracz_rowne_baza()
{
    int test, i;

    test = 1;
    for (i = 0; i <= 3; i++) 
             test = (test && (baza.tab_kolorow[i] == gracz.tab_kolorow[i]));
    return test;
}

// Metoda testuje warunek zako�czenia gry.
//------------------------------------------------------
int Master::KoniecGry(Grafika druk)
{
    runda++;      // zwi�kszamy numer rundy
    if (gracz_rowne_baza())
    {
        druk.textattr(0x0e);
        druk.Centrowanie(napis("GRATULACJE - odgad�e� kod komputera!"));
        druk.gotoxy(35, 3); 
        baza.Wyswietl(druk);  // wy�wietlamy kod komputera
        return 1;
    }
    else if (runda > 6)
    {
        druk.textattr(0x0c);
        druk.Centrowanie(napis("GRA SKO�CZONA - nie odgad�e� kodu komputera!"));
        druk.gotoxy(35, 3); 
        baza.Wyswietl(druk);
        return 1;
    };
    return 0;
}

// Metoda wy�wietla stron� tytu�ow� i czeka na
// dowolny klawisz, po czym czy�ci ekran.
//------------------------------------------------------
void Master::StronaTytulowa(Grafika& druk )
{
    druk.textbackground(0);  druk.clrscr();
    druk.gotoxy(1, 3);       druk.textattr(0x3b);
    
    druk.Centrowanie(napis("                                  "));
    druk.Centrowanie(napis("      --  GRA LOGICZNA --         "));
    druk.Centrowanie(napis("    ------ MASTER MIND ----       "));
    druk.Centrowanie(napis("                                  "));
    druk.textattr(0x1f);
    druk.Centrowanie(napis("                                  "));
    druk.Centrowanie(napis("         JAKUB M�CZKA             "));
    druk.Centrowanie(napis("                                  "));
    druk.textattr(0x2e);
    druk.Centrowanie(napis("                                  "));
    druk.Centrowanie(napis("     POLITECHNIKA RZESZOWSKA      "));
    druk.Centrowanie(napis("          2FDI GRUPA L04          "));
    druk.Centrowanie(napis("                                  "));
    druk.Centrowanie(napis("                                  "));
    druk.textattr(0xf0);
    druk.Centrowanie(napis("                                  "));
    druk.Centrowanie(napis("   Odgadnij w sze�ciu kolejkach   "));
    druk.Centrowanie(napis("   kod koloru  wylosowany przez   "));
    druk.Centrowanie(napis("    komputer z 6 r�nych barw.    "));
    druk.Centrowanie(napis("                                  "));
    druk.textattr(0xf4);
    druk.Centrowanie(napis("        Gdy b�dziesz gotowy,      "));
    druk.Centrowanie(napis("     naci�nij dowolny klawisz     "));
    druk.Centrowanie(napis("                                  "));
    druk.textattr(0x0e); 
    druk.Ramka(23, 2, 58, 23);
    while (getch() == '\0'); // Oczekiwanie na dowolny klawisz
    druk.textattr(0x07); druk.clrscr();
}

// Metoda odpowiedzialna za prowadzenie gry.
//------------------------------------------------------
void Master::Rozgrywka(Grafika druk)
{
    baza.Inicjuj(); runda = 1;
    druk.textattr(0x4e);
    druk.Centrowanie("    MASTER  MIND    ");
    druk.textattr(0x87);
    druk.Centrowanie("                    ");
    druk.Centrowanie("    ? ? ? ?         ");
    druk.Centrowanie("                    ");
    do
    {
        gracz.Inicjuj(runda);
        Ocen_gracza(druk);
    } while (!KoniecGry(druk));
}

// Metoda upewnia si�, �e gracz ma ochot� na jeszcze
// jedn� gr�.
//------------------------------------------------------
int Master::Kontynuacja(Grafika druk)
{
    druk.gotoxy(1, 24); druk.textcolor(druk.Bialy);
    druk.Centrowanie("Grasz jeszcze raz ? [T] = Tak, [inny klawisz] = Nie");
    return(toupper(getch()) == 'T');
}
