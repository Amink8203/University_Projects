#include <stdio.h>
#include <stdlib.h>
#include"DeclareWinner.h"
void DeclareWinner(int *T1, int *T2)
{
    if (*T1 == 1)
        printf("\nTeam1 got 1 point.\n");
    if (*T2 == 1)
        printf("\nTeam2 got 1 point.\n");
    T1 = 0;
    T2 = 0;
}