#include <stdio.h>
#include <stdlib.h>
#include"FirstCardBot.h"
#include"MAX.h"
#define TRUE 1
#define PLAYER 4
#define CARDS 11
void FirstCardBot(int *SecondP2num, char *SecondP2sym, char *BN, char symbolP2[], int numA2[], int numB2[], int numC2[], int numD2[])
{
    // Determining which card player 2 must play.
    for (int i = 0; i < CARDS; i++)
    {
        if (symbolP2[i] != *BN)
        {
            *SecondP2sym = symbolP2[i];
            symbolP2[i] = '\0';
            if (*SecondP2sym == 'A')
            {
                *SecondP2num = numA2[MAX(11, numA2)];
                numA2[MAX(11, numA2)] = 0;
                break;
            }
            if (*SecondP2sym == 'B')
            {
                *SecondP2num = numB2[MAX(11, numB2)];
                numB2[MAX(11, numB2)] = 0;
                break;
            }
            if (*SecondP2sym == 'C')
            {
                *SecondP2num = numC2[MAX(11, numC2)];
                numC2[MAX(11, numC2)] = 0;
                break;
            }
            if (*SecondP2sym == 'D')
            {
                *SecondP2num = numD2[MAX(11, numD2)];
                numD2[MAX(11, numD2)] = 0;
                break;
            }
        }
    }
    // If player 2 only has bakhshnameh.
    if (*SecondP2sym == '\0')
    {
        for (int i = 0; i < CARDS; i++)
        {
            if (symbolP2[i] == *BN)
            {
                *SecondP2sym = symbolP2[i];
                symbolP2[i] = '\0';
                if (*SecondP2sym == 'A')
                {
                    *SecondP2num = numA2[MAX(11, numA2)];
                    numA2[MAX(11, numA2)] = 0;
                    break;
                }
                if (*SecondP2sym == 'B')
                {
                    *SecondP2num = numB2[MAX(11, numB2)];
                    numB2[MAX(11, numB2)] = 0;
                    break;
                }
                if (*SecondP2sym == 'C')
                {
                    *SecondP2num = numC2[MAX(11, numC2)];
                    numC2[MAX(11, numC2)] = 0;
                    break;
                }
                if (*SecondP2sym == 'D')
                {
                    *SecondP2num = numD2[MAX(11, numD2)];
                    numD2[MAX(11, numD2)] = 0;
                    break;
                }
            }
        }
    }
}