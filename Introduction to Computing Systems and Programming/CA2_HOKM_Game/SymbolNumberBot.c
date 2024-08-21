#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"SymbolNumberBot.h"
#define PLAYER 4
#define CARDS 11
//Making two arrays for symbol and number from 2D array for each bot.
void SymbolNumberBot(int P2[PLAYER][CARDS],int numberP2[CARDS],char symbolP2[CARDS],int numA2[CARDS],int numB2[CARDS],int numC2[CARDS],int numD2[CARDS]){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (P2[i][j] == 1)
            {
                if (i == 0)
                {
                    numberP2[b] = j + 1;
                    symbolP2[b] = 'A';
                    b++;
                    numA2[a] = j + 1;
                    a++;
                    continue;
                }
                if (i == 1)
                {
                    numberP2[b] = j + 1;
                    symbolP2[b] = 'B';
                    b++;
                    numB2[c] = j + 1;
                    c++;
                    continue;
                }
                if (i == 2)
                {
                    numberP2[b] = j + 1;
                    symbolP2[b] = 'C';
                    b++;
                    numC2[d] = j + 1;
                    d++;
                    continue;
                }
                if (i == 3)
                {
                    numberP2[b] = j + 1;
                    symbolP2[b] = 'D';
                    b++;
                    numD2[e] = j + 1;
                    e++;
                }
            }
        }
    }
}