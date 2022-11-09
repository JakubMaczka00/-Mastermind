#pragma once
#include "Grafika.h"
class Kod_bazy : public Grafika
{
 public:
    int tab_kolorow[4];
    void Inicjuj();
    void Wyswietl(Grafika druk);
    void Sprawdzaj(int t[]);
};

