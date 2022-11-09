#pragma once
#include "Kod_gracza.h"
class Master
{
    Kod_bazy baza;
    Kod_gracza gracz;
    int runda;
    void Ocen_gracza(Grafika druk);
    int gracz_rowne_baza();
    int KoniecGry(Grafika druk);
public:
    Master();
    void StronaTytulowa(Grafika& druk);
    void Rozgrywka(Grafika druk);
    int Kontynuacja(Grafika druk);
};