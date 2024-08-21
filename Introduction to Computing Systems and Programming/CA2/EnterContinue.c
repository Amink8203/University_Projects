#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"EnterContinue.h"
#define TRUE 1
void EnterContinue()
{
    fflush(stdin);
    while (TRUE)
    {
        printf("\nPlease press enter to continue the game.");
        char e = '\0';
        e = getchar();
        if (e == '\n')
            break;
        else
        {
            fflush(stdin);
            continue;
        }
    }
}