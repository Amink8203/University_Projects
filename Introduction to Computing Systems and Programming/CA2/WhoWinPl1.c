#include <stdio.h>
#include <stdlib.h>
#include"WhoWinPl1.h"
#include"MAX.h"
#define TRUE 1
#define PLAYER 4
#define CARDS 11
//Win condition when player1 starts the round.
void WhoWinPl1(int *team1, int *team2, int *Pl1, int *Pl2,
 int *Pl3, int *Pl4, int *T1, int *T2, int *FirstP1num, int *FirstP2num, 
 int *FirstP3num, int *FirstP4num,  char *FirstP1sym, char *FirstP2sym, char *FirstP3sym,
  char *FirstP4sym, char *BN, char SecondCsym[3], int SecondCnum[3], int ThirdCnum[4]){
    if (*FirstP1sym == *FirstP2sym && *FirstP2sym == *FirstP3sym && *FirstP3sym == *FirstP4sym)
    {
        if (*FirstP1num > *FirstP2num && *FirstP1num > *FirstP3num && *FirstP1num > *FirstP4num)
        {
            ++*team1;
            ++*T1;
            ++*Pl1;
        }
        if (*FirstP3num > *FirstP1num && *FirstP3num > *FirstP2num && *FirstP3num > *FirstP4num)
        {
            ++*team1;
            ++*T1;
            ++*Pl3;
        }
        if (*FirstP2num > *FirstP1num && *FirstP2num > *FirstP3num && *FirstP2num > *FirstP4num)
        {
            ++*team2;
            ++*T2;
            ++*Pl2;
        }
        if (*FirstP4num > *FirstP1num && *FirstP4num > *FirstP2num && *FirstP4num > *FirstP3num)
        {
            ++*team2;
            ++*T2;
            ++*Pl4;
        }
    }
    else if ((*FirstP2sym == *BN || *FirstP3sym == *BN || *FirstP4sym == *BN) && *FirstP1sym != *BN)
    {
        for (int i = 0; i < 3; i++)
        {
            if (SecondCsym[i] == *BN)
            {
                if (i == 0)
                    SecondCnum[0] = *FirstP2num;
                if (i == 1)
                    SecondCnum[1] = *FirstP3num;
                if (i == 2)
                    SecondCnum[2] = *FirstP4num;
            }
        }
        // Finding the index for maximum number of Bakhshnameh.
        int x = 0;
        x = MAX(3, SecondCnum);
        if (x == 1)
        {
            ++*team1;
            ++*T1;
            ++*Pl3;
        }
        else if (x == 0)
        {
            ++*team2;
            ++*T2;
            ++*Pl2;
        }
        else
        {
            ++*team2;
            ++*T2;
           ++*Pl4;
        }
    }
    else
    {
        if (*FirstP2sym == *FirstP1sym)
            ThirdCnum[1] = *FirstP2num;
        if (*FirstP3sym == *FirstP1sym)
            ThirdCnum[2] = *FirstP3num;
        if (*FirstP4sym == *FirstP1sym)
            ThirdCnum[3] = *FirstP4num;
        // Finding the index for maximum number of card.
        int x = 0;
        x = MAX(4, ThirdCnum);
        if (x == 0)
        {
            ++*team1;
            ++*T1;
            ++*Pl1;
        }
        else if (x == 2)
        {
            ++*team1;
            ++*T1;
            ++*Pl3;
        }
        else if (x == 1)
        {
            ++*team2;
            ++*T2;
            ++*Pl2;
        }
        else
        {
            ++*team2;
            ++*T2;
            ++*Pl4;
        }
    }
  }