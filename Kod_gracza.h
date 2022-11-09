 #pragma once
#include "Kod_bazy.h"
class Kod_gracza : public Kod_bazy
{
 public:
    void Inicjuj(int runda);
    void Wyswietl(int runda, int kursor);
};     
