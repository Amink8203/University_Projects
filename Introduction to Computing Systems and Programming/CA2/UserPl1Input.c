#include <stdio.h>
#include <stdlib.h>
#include"UserPl1Input.h"
#define TRUE 1
#define CARDS 11
void UserPl1Input(int* num,int* f,int nums[CARDS],int numberP1[CARDS],int* FirstP1num,char* FirstP1sym,char symbolP1[CARDS]){
    while (TRUE)
    {
        scanf("%d", &(*num));
        if (*num < 0 || *num > 10)
        {
            printf("You must enter a number from 0 to 10,let's try again:");
            continue;
        }
        else
            break;
    }
    // For showing '-' and '0' in the board.
    nums[*f] = *num;
    ++*f;
    // Defining each number a card for player1.
    for (int i = 0; i < CARDS; i++)
    {
        if (*num == i)
        {
            *FirstP1sym = symbolP1[i];
            symbolP1[i] = '\0';
            *FirstP1num = numberP1[i];
            numberP1[i] = 0;
            break;
        }
    }
}