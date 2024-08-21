#include <stdio.h>
#include <stdlib.h>
#include "board1.h"
#define PLAYER 4
#define CARDS 11
void board1(int P1[PLAYER][CARDS])
{
    char symbol[11];
    int number[11] = {0};
    // x is a helping variable for loop.
    int x = 0;
    // Definig first 5 cards of Player 1.
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (P1[i][j] == 1)
            {
                if (i == 0)
                {
                    symbol[x] = 'A';
                    number[x] = j + 1;
                    x++;
                }
                if (i == 1)
                {
                    symbol[x] = 'B';
                    number[x] = j + 1;
                    x++;
                }
                if (i == 2)
                {
                    symbol[x] = 'C';
                    number[x] = j + 1;
                    x++;
                }
                if (i == 3)
                {
                    symbol[x] = 'D';
                    number[x] = j + 1;
                    x++;
                }
            }
        }
    }
    printf("\t\t\t\t\t\t\t\t\t\tP3");
    printf("\n\t\t\t\t\t\t");
    for (int i = 0; i < 36; i++)
        printf("_ ");
    printf("\t\tTeam1:0"); // code for incresing team 1.
    printf("\n\t\t\t\t\t\t");
    printf("|\t\t\t\t");
    printf("  "); // code!
    printf("\t\t\t\t       |");
    for (int j = 0; j < 12; j++)
    {
        printf("\n\t\t\t\t\t\t");
        printf("|\t\t\t\t\t\t\t\t       |");
    }
    printf("\n\t\t\t\t\t      ");
    printf("P2");
    printf("|");
    printf("  "); // code!
    printf("\t\t\t\t\t\t\t\t   ");
    printf("  ");
    printf("  |");
    printf("P4");
    for (int j = 0; j < 11; j++)
    {
        printf("\n\t\t\t\t\t\t");
        printf("|\t\t\t\t\t\t\t\t       |");
    }
    printf("\n\t\t\t\t\t\t");
    printf("|\t\t\t\t");
    printf("  "); // code!
    printf("\t\t\t\t       |");

    printf("\n\t\t\t\t\t\t");
    for (int k = 0; k < 36; k++)
        printf("_ ");
    printf("\t\tTeam2:0"); // code for increasing team 2.
    printf("\n\t\t\t\t\t\t");
    printf("\t\t\t\t");
    printf("P1");
    printf("\n\t\t\t\t\t\t       ");
    for (int l = 0; l < 33; l++)
        printf("_ ");
    printf("\n\t\t\t\t\t\tsymbol");
    printf("|  ");

    printf("%c", symbol[0]);
    printf("  |  ");

    printf("%c", symbol[1]);
    printf("  |  ");

    printf("%c", symbol[2]);
    printf("  |  ");

    printf("%c", symbol[3]);
    printf("  |  ");

    printf("%c", symbol[4]);
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-");
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |");
    printf("\n\t\t\t\t\t\t       ");
    for (int l = 0; l < 33; l++)
        printf("_ ");
    printf("\n\t\t\t\t\t\tnumber");
    printf("|  ");

    printf("%d", number[0]);
    printf("  |  ");

    printf("%d", number[1]);
    printf("  |  ");

    printf("%d", number[2]);
    printf("  |  ");

    printf("%d", number[3]);
    printf("  |  ");
    printf("%d", number[4]);
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |  ");
    printf("-"); // code!
    printf("  |");
    printf("\n\t\t\t\t\t\t       ");
    for (int l = 0; l < 33; l++)
        printf("_ ");
    printf("\n\t\t\t\t\t\t         ");
    printf("0");
    printf("     "); // 5 spaces.
    printf("1");
    printf("     ");
    printf("2");
    printf("     ");
    printf("3");
    printf("     ");
    printf("4");
    printf("     ");
    printf("5");
    printf("     ");
    printf("6");
    printf("     ");
    printf("7");
    printf("     ");
    printf("8");
    printf("     ");
    printf("9");
    printf("     ");
    printf("10");
}