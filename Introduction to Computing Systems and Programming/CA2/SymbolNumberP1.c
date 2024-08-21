#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"SymbolNumberP1.h"
#define PLAYER 4
#define CARDS 11
//Making two array for symbol and number from 2D array for player1.
void SymbolNumberP1(int P1[PLAYER][CARDS],int numberP1[CARDS],char symbolP1[CARDS]){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (P1[i][j] == 1)
            {
                if (i == 0)
                {
                    numberP1[a] = j + 1;
                    symbolP1[a] = 'A';
                    a++;
                    b++;
                    continue;
                }
                if (i == 1)
                {
                    numberP1[a] = j + 1;
                    symbolP1[a] = 'B';
                    a++;
                    c++;
                    continue;
                }
                if (i == 2)
                {
                    numberP1[a] = j + 1;
                    symbolP1[a] = 'C';
                    a++;
                    d++;
                    continue;
                }
                if (i == 3)
                {
                    numberP1[a] = j + 1;
                    symbolP1[a] = 'D';
                    a++;
                    e++;
                }
            }
        }
    }
}