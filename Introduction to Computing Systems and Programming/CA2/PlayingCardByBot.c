#include <stdio.h>
#include <stdlib.h>
#include "MAX.h"
#include "MIN.h"
#include"PlayingCardByBot.h"
#define TRUE 1
#define PLAYER 4
#define CARDS 11
void PlayingCardByBot(char *FirstP1sym, char *FirstP2sym, int *FirstP2num, char symbolP2[], int numA2[], int numB2[], int numC2[], int numD2[], char *BN)
{
    for (int j = 0; j < 11; j++)
    {
        if (*FirstP1sym == symbolP2[j])
        {
            *FirstP2sym = symbolP2[j];
            //Each symbol that player used become null.
            symbolP2[j] = '\0'; 
            if (*FirstP2sym == 'A')
            {
                *FirstP2num = numA2[MAX(11, numA2)];
                numA2[MAX(11, numA2)] = 0;
                break;
            }
            if (*FirstP2sym == 'B')
            {
                *FirstP2num = numB2[MAX(11, numB2)];
                numB2[MAX(11, numB2)] = 0;
                break;
            }
            if (*FirstP2sym == 'C')
            {
                *FirstP2num = numC2[MAX(11, numC2)];
                numC2[MAX(11, numC2)]=0;//
                break;
            }
            if (*FirstP2sym == 'D')
            {
                *FirstP2num = numD2[MAX(11, numD2)];
                numD2[MAX(11, numD2)] = 0;
                break;
            }
        }
    }
    // If P2 doesn't have the base card.
    if (*FirstP2sym == '\0')
    {
        for (int j = 0; j < 11; j++)
        {
            if (*BN == symbolP2[j])
            {
                *FirstP2sym = *BN;
                symbolP2[j] = '\0';
                if (*FirstP2sym == 'A')
                {
                    *FirstP2num = numA2[MAX(11, numA2)];
                    numA2[MAX(11, numA2)] = 0;
                    break;
                }
                if (*FirstP2sym == 'B')
                {
                    *FirstP2num = numB2[MAX(11, numB2)];
                    numB2[MAX(11, numB2)] = 0;
                    break;
                }
                if (*FirstP2sym == 'C')
                {
                    *FirstP2num = numC2[MAX(11, numC2)];
                    numC2[MAX(11, numC2)]=0;//
                    break;
                }
                if (*FirstP2sym == 'D')
                {
                    *FirstP2num = numD2[MAX(11, numD2)];
                    numD2[MAX(11, numD2)] = 0;
                    break;
                }
            }
        }
    }
    if (*FirstP2sym == '\0')
    {
        for (int j = 0; j < 11; j++)
        {
            //Check the card that player wants to play hasn't been used until now.
            if (symbolP2[j] != '\0') 
                *FirstP2sym = symbolP2[j];
            else
                continue;
            symbolP2[j] = '\0';
            if (*FirstP2sym == 'A')
            {
                *FirstP2num = numA2[MIN(11, numA2)];
                numA2[MIN(11, numA2)] = 0;
                break;
            }
            if (*FirstP2sym == 'B')
            {
                *FirstP2num = numB2[MIN(11, numB2)];
                numB2[MIN(11, numB2)] = 0;
                break;
            }
            if (*FirstP2sym == 'C')
            {
                *FirstP2num = numC2[MIN(11, numC2)];
                numC2[MIN(11, numC2)] = 0;
                break;
            }
            if (*FirstP2sym == 'D')
            {
                *FirstP2num = numD2[MIN(11, numD2)];
                numD2[MIN(11, numD2)] = 0;
                break;
            }
        }
    }
}