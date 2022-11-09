#include "Kod_bazy.h"
#include <iostream>
#include <conio.h>


using namespace std;

// Metoda do losowania kod kolorów dla komputera
//------------------------------------------------------
void Kod_bazy::Inicjuj()
{
    for (int i = 0; i <= 3; i++) tab_kolorow[i] = rand() % 6;
}

// Metoda wyœwietla na bie¿¹cej pozycji kolejne
// kolory zawarte w kodzie.
//------------------------------------------------------
void Kod_bazy::Wyswietl(Grafika druk)
{
    const int kolory[6] =
    { druk.Czarny,druk.Jasnoniebieski,druk.Jasnozielony,druk.Jasnoczerwony,
        druk.Jasnofioletowy,druk.Zolty };

    for (int i = 0; i <= 3; i++)
    {
        druk.textattr(0x80 + kolory[tab_kolorow[i]]);
        cout << char(219) << ' ';
    };
}

// Funkcja porównuj¹ca podany jej w formie tablicy kod
// z kodem w polu tab_kolorow. 
//------------------------------------------------------
void Kod_bazy::Sprawdzaj(int t[])
{
    int tab_bazy[4], tab_gracza[4], czarne, biale, i, j;

    for (i = 0; i <= 3; i++)
    {
        tab_bazy[i] = tab_kolorow[i]; tab_gracza[i] = t[i];
    };
    czarne = 0;
    for (i = 0; i <= 3; i++)
        if (tab_gracza[i] == tab_bazy[i])
        {
            czarne++; tab_bazy[i] = -1; tab_gracza[i] = -2;
        };
    biale = 0;
    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++)
            if (tab_gracza[i] == tab_bazy[j])
            {
                biale++; tab_bazy[j] = -1; tab_gracza[i] = -2; break;
            };
    textattr(0x80); for (i = 1; i <= czarne; i++) cout << "* ";
    textattr(0x8f); for (i = 1; i <= biale; i++)  cout << "* ";
}
