#include<stdio.h>
#include<stdlib.h>
#include"Firstround.h"
#define PLAYER 4
#define CARDS 11
void Firstround(int P1[PLAYER][CARDS], int num, int FirstP2num, int FirstP3num, int FirstP4num, char FirstP2sym, char FirstP3sym, char FirstP4sym, int team1, int team2, int nums[11])
{
    char symbol[11];
    int number[11] = {0};
    // Variable for bakhshnameh.
    char BN;
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
    printf("\t\tTeam1:"); // code for incresing team 1.
    printf("%d", team1);
    printf("\n\t\t\t\t\t\t");
    printf("|\t\t\t\t");
    // P3 code!
    printf("%c", FirstP3sym);
    printf("%d", FirstP3num);
    printf("\t\t\t\t       |");
    for (int j = 0; j < 12; j++)
    {
        printf("\n\t\t\t\t\t\t");
        printf("|\t\t\t\t\t\t\t\t       |");
    }
    printf("\n\t\t\t\t\t      ");
    printf("P2");
    printf("|");
    // P2 code!
    printf("%c", FirstP2sym);
    printf("%d", FirstP2num);
    printf("\t\t\t\t\t\t\t\t   ");
    // P4 code!
    printf("%c", FirstP4sym);
    printf("%d", FirstP4num);
    printf("  |");
    printf("P4");
    for (int j = 0; j < 11; j++)
    {
        printf("\n\t\t\t\t\t\t");
        printf("|\t\t\t\t\t\t\t\t       |");
    }
    printf("\n\t\t\t\t\t\t");
    printf("|\t\t\t\t");
    printf("%c", symbol[num]);
    printf("%d", number[num]);
    printf("\t\t\t\t       |");

    printf("\n\t\t\t\t\t\t");
    for (int k = 0; k < 36; k++)
        printf("_ ");
    printf("\t\tTeam2:"); // code for increasing team 2.
    printf("%d", team2);
    printf("\n\t\t\t\t\t\t");
    printf("\t\t\t\t");
    printf("P1");
    printf("\n\t\t\t\t\t\t       ");
    // A loop for making used cards '-' and '0'
    for (int i = 0; i < CARDS; i++)
    {
        if (nums[i] != 11)
        {
            symbol[nums[i]] = '-';
            number[nums[i]] = 0;
        }
    }
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
    printf("%c", symbol[5]);
    printf("  |  ");
    printf("%c", symbol[6]);
    printf("  |  ");
    printf("%c", symbol[7]);
    printf("  |  ");
    printf("%c", symbol[8]);
    printf("  |  ");
    printf("%c", symbol[9]);
    printf("  |  ");
    printf("%c", symbol[10]);
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
    printf("%d", number[5]);
    printf("  |  ");
    printf("%d", number[6]);
    printf("  |  ");
    printf("%d", number[7]);
    printf("  |  ");
    printf("%d", number[8]);
    printf("  |  ");
    printf("%d", number[9]);
    printf("  |  ");
    printf("%d", number[10]);
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
    printf("\n");
}