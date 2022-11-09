#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "napis.h"
#include <windows.h>
#include <iostream>
using namespace std;
static int __BACKGROUND;
static int __FOREGROUND;

class Grafika
{
 public:
    const int Czarny;
    const int Niebieski;
    const int Zielony;
    const int Morski;
    const int Czerwony;
    const int Fiolet;
    const int Brazowy;
    const int Jasnoszary;
    const int Ciemnoszary;
    const int Jasnoniebieski;
    const int Jasnozielony;
    const int Jasnomorski;
    const int Jasnoczerwony;
    const int Jasnofioletowy;
    const int Zolty;
    const int Bialy;

    //static int __BACKGROUND;
    //static int __FOREGROUND;
    
    Grafika();
    
    void textcolor(int color);
    void textbackground(int color);
    void textattr(int _attr);
    void gotoxy(int x, int y);
    int kursor_pozycja_x();
    int kursor_pozycja_y();
    void Ramka(int xp, int yp, int xk, int yk);
    void Centrowanie(napis t);
    void clrscr();
};

