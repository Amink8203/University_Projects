#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "board1.h"
#include "board2.h"
#include "board3.h"
#include"board4.h"
#include"DeclareWinner.h"
#include"EnterContinue.h"
#include"MAX.h"
#include"MIN.h"
#include"FirstCardBot.h"
#include"Firstround.h"
#include"P2P3P4Ending.h"
#include"P2Starting.h"
#include"P3Starting.h"
#include"P4Starting.h"
#include"PlayingCardByBot.h"
#include"UserInput.h"
#include"UserPl1Input.h"
#include"WhoWinPl1.h"
#include"WhoWinPl2.h"
#include"WhoWinPl3.h"
#include"WhoWinPl4.h"
#include"SymbolNumberP1.h"
#include"SymbolNumberBot.h"
#define TRUE 1
#define PLAYER 4
#define CARDS 11
#define numOfCards 44
void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}
int main(void)
{
    // Helping variables for giving cards to players.
    int x, y;
    // Variable for bakhshnameh.
    char BN;
    // Arrays for cards of each player.
    int P1[PLAYER][CARDS] = {0};
    int P2[PLAYER][CARDS] = {0};
    int P3[PLAYER][CARDS] = {0};
    int P4[PLAYER][CARDS] = {0};
    // Arrays for defining type and number of cards for each player.
    char symbolP1[CARDS];
    int numberP1[CARDS];
    char symbolP2[CARDS];
    int numberP2[CARDS];
    char symbolP3[CARDS];
    int numberP3[CARDS];
    char symbolP4[CARDS];
    int numberP4[CARDS];
    int card[numOfCards];
    int team1 = 0, team2 = 0;
    shuffle_card(card);
    for (int i = 0; i < 5; i++)
    {
        x = card[i] / CARDS;
        y = card[i] % CARDS;
        P1[x][y] = 1;
    }
    //Printing the first 5 cards of P1 to choose BN.
    board1(P1);
    printf("\nPlease choose a symbol (A,B,C,D) for bakhshnameh:");
    while (TRUE)
    {
        fflush(stdin);
        scanf("%c", &BN);
        //It's ok whether user's input is capital or small.
        switch(BN){
            case'a':BN='A';
            case'b':BN='B';
            case'c':BN='C';
            case'd':BN='D';
        }
        if (BN != 'A' && BN != 'B' && BN != 'C' && BN != 'D')
        {
            printf("You should choose a symbol from A,B,C,D.Let's try again:");
            continue;
        }
        else
            break;
    }
    // Giving cards to each 2D array for each player.
    for (int i = 5; i < 10; i++)
    {
        x = card[i] / CARDS;
        y = card[i] % CARDS;
        P2[x][y] = 1;
    }
    for (int i = 10; i < 15; i++)
    {
        x = card[i] / CARDS;
        y = card[i] % CARDS;
        P3[x][y] = 1;
    }
    for (int i = 15; i < 20; i++)
    {
        x = card[i] / CARDS;
        y = card[i] % CARDS;
        P4[x][y] = 1;
    }
    // 4cards.
    for (int j = 20; j < 24; j++)
    {
        x = card[j] / CARDS;
        y = card[j] % CARDS;
        P1[x][y] = 1;
    }
    for (int j = 24; j < 28; j++)
    {
        x = card[j] / CARDS;
        y = card[j] % CARDS;
        P2[x][y] = 1;
    }
    for (int j = 28; j < 32; j++)
    {
        x = card[j] / CARDS;
        y = card[j] % CARDS;
        P3[x][y] = 1;
    }
    for (int j = 32; j < 36; j++)
    {
        x = card[j] / CARDS;
        y = card[j] % CARDS;
        P4[x][y] = 1;
    }
    // 2cards.
    for (int k = 36; k < 38; k++)
    {
        x = card[k] / CARDS;
        y = card[k] % CARDS;
        P1[x][y] = 1;
    }
    for (int k = 38; k < 40; k++)
    {
        x = card[k] / CARDS;
        y = card[k] % CARDS;
        P2[x][y] = 1;
    }
    for (int k = 40; k < 42; k++)
    {
        x = card[k] / CARDS;
        y = card[k] % CARDS;
        P3[x][y] = 1;
    }
    for (int k = 42; k < 44; k++)
    {
        x = card[k] / CARDS;
        y = card[k] % CARDS;
        P4[x][y] = 1;
    }
    // Counters for passing cards.
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    // Arrays for numbers of each symbol for cards that each player have.
    int numA2[CARDS] = {0}, numB2[CARDS] = {0}, numC2[CARDS] = {0}, numD2[CARDS] = {0};
    int numA3[CARDS] = {0}, numB3[CARDS] = {0}, numC3[CARDS] = {0}, numD3[CARDS] = {0};
    int numA4[CARDS] = {0}, numB4[CARDS] = {0}, numC4[CARDS] = {0}, numD4[CARDS] = {0};
    // Defining symbols and numbers of cards for each player.
    SymbolNumberP1(P1,numberP1,symbolP1);
    SymbolNumberBot(P2,numberP2,symbolP2,numA2,numB2,numC2,numD2);
    SymbolNumberBot(P3,numberP3,symbolP3,numA3,numB3,numC3,numD3);
    SymbolNumberBot(P4,numberP4,symbolP4,numA4,numB4,numC4,numD4);
    system("cls");
    //Showing which card you choose.
    board2(P1);
    // Start of the first round of the game.
    printf("\nPlease choose a card from the map(from 0 to 10):");
    // Choosing which card to play.
    int num;
    // Define this array for '-' and '0' in board when a card is used.
    int nums[CARDS] = {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11};
    int f = 0;
    char FirstP1sym;
    int FirstP1num;
    UserPl1Input(&num,&f,nums,numberP1,&FirstP1num,&FirstP1sym,symbolP1);
    system("cls");
    board3(P1, FirstP1num, FirstP1sym, num, nums, team1, team2);
    // For pressing enter to continue the game and the boards.
    EnterContinue();
    printf("\n\n");
    char FirstP2sym = '\0', FirstP3sym = '\0', FirstP4sym = '\0';
    int FirstP2num, FirstP3num, FirstP4num;
    // The first card that Player 2 plays.
    PlayingCardByBot(&FirstP1sym, &FirstP2sym, &FirstP2num, symbolP2, numA2, numB2, numC2, numD2, &BN);
    // The first card that Player 3 plays.
    PlayingCardByBot(&FirstP1sym, &FirstP3sym, &FirstP3num, symbolP3, numA3, numB3, numC3, numD3, &BN);
    // The first card that Player 4 plays.
    PlayingCardByBot(&FirstP1sym, &FirstP4sym, &FirstP4num, symbolP4, numA4, numB4, numC4, numD4, &BN);
    // Flag for winning player and determinig who begins next round.
    int Pl1 = 0, Pl2 = 0, Pl3 = 0, Pl4 = 0;
    // Defining these two variables for second condition(For comparing and finding out whether there is BN between P2,P3,P3 in the first round or not).
    char SecondCsym[3] = {FirstP2sym, FirstP3sym, FirstP4sym};
    int SecondCnum[3] = {0};
    // Third condition for the numbers.
    int ThirdCnum[4] = {FirstP1num};
    //ّFlag for determining which team got point.
    int T1 = 0, T2 = 0;
    WhoWinPl1(&team1, &team2, &Pl1, &Pl2,
    &Pl3, &Pl4, &T1, &T2, &FirstP1num, &FirstP2num, 
    &FirstP3num, &FirstP4num,  &FirstP1sym, &FirstP2sym, &FirstP3sym,
    &FirstP4sym, &BN, SecondCsym, SecondCnum, ThirdCnum);
    system("cls");
    Firstround(P1, num, FirstP2num, FirstP3num, FirstP4num, FirstP2sym, FirstP3sym, FirstP4sym, team1, team2, nums); // numA1,numB1,numC1,numD1 ro hazf kardam chon khode P1 entekhab mikone.
    DeclareWinner(&T1, &T2);
    EnterContinue();

    while ((team1 < 6) && (team2 < 6))
    {
        T1 = 0;
        T2 = 0;
        if (Pl1 == 1)
        {
            // Returning the flag to its initial value.
            Pl1 = 0;
            system("cls");
            board4(P1, nums, team1, team2);
            printf("\nYou won the previous round,Please choose a card from the remaining cards on the map:");
            // Choosing which card to play.
            int num;
            char FirstP1sym;
            int FirstP1num;
            UserPl1Input(&num,&f,nums,numberP1,&FirstP1num,&FirstP1sym,symbolP1);
            system("cls");
            board3(P1, FirstP1num, FirstP1sym, num, nums, team1, team2);
            EnterContinue();
            printf("\n\n");
            char FirstP2sym = '\0', FirstP3sym = '\0', FirstP4sym = '\0';
            int FirstP2num, FirstP3num, FirstP4num;
            // The first card that Player 2 plays.
            PlayingCardByBot(&FirstP1sym, &FirstP2sym, &FirstP2num, symbolP2, numA2, numB2, numC2, numD2, &BN);
            // The first card that Player 3 plays.
            PlayingCardByBot(&FirstP1sym, &FirstP3sym, &FirstP3num, symbolP3, numA3, numB3, numC3, numD3, &BN);
            // The first card that Player 4 plays.
            PlayingCardByBot(&FirstP1sym, &FirstP4sym, &FirstP4num, symbolP4, numA4, numB4, numC4, numD4, &BN);
            // Defining these two variables for second condition(For comparing and finding out whether there is BN between P2,P3,P3 in the first round or not).
            char SecondCsym[3] = {FirstP2sym, FirstP3sym, FirstP4sym};
            int SecondCnum[3] = {0};
            // Third condition for the numbers.
            int ThirdCnum[4] = {FirstP1num};
            //ّFlag for determining which team got point.
            int T1 = 0, T2 = 0;
            WhoWinPl1(&team1, &team2, &Pl1, &Pl2,
            &Pl3, &Pl4, &T1, &T2, &FirstP1num, &FirstP2num, 
            &FirstP3num, &FirstP4num,  &FirstP1sym, &FirstP2sym, &FirstP3sym,
            &FirstP4sym, &BN, SecondCsym, SecondCnum, ThirdCnum);
            system("cls");
            Firstround(P1, num, FirstP2num, FirstP3num, FirstP4num, FirstP2sym, FirstP3sym, FirstP4sym, team1, team2, nums);
            DeclareWinner(&T1, &T2);
            EnterContinue();
            // For going back to the condition of while loop and check which player should start next round(or the game is over)
            continue;
        }
        // Player 2 starts the game.
        if (Pl2 == 1)
        {
            // Returning the flag to its initial value.
            Pl2 = 0;
            char SecondP1sym, SecondP2sym = '\0', SecondP3sym = '\0', SecondP4sym = '\0';
            int SecondP1num, SecondP2num, SecondP3num, SecondP4num;
            // Determining which card player 2 must play.
            FirstCardBot(&SecondP2num, &SecondP2sym, &BN, symbolP2, numA2, numB2, numC2, numD2);
            // It's player3 turn.
            PlayingCardByBot(&SecondP2sym, &SecondP3sym, &SecondP3num, symbolP3, numA3, numB3, numC3, numD3, &BN);
            // It's player4 turn.
            PlayingCardByBot(&SecondP2sym, &SecondP4sym, &SecondP4num, symbolP4, numA4, numB4, numC4, numD4, &BN);
            // Board for your turn.
            system("cls");
            P2Starting(P1, SecondP2num, SecondP3num, SecondP4num, SecondP2sym, SecondP3sym, SecondP4sym, team1, team2, nums);
            int num;
            UserInput(&num,&f,&SecondP1num,&SecondP2sym,&SecondP1sym,numberP1,symbolP1,nums);
            system("cls");
            board3(P1, SecondP1num, SecondP1sym, num, nums, team1, team2);
            EnterContinue();
            char SecondCsym[3] = {SecondP1sym, SecondP3sym, SecondP4sym};
            int SecondCnum[3] = {0};
            int ThirdCnum[4] = {SecondP2num};
            WhoWinPl2(&team1, &team2, &Pl1, &Pl2, &Pl3, &Pl4, &T1, &T2, &SecondP1num, &SecondP2num, &SecondP3num, &SecondP4num,
            &SecondP1sym, &SecondP2sym, &SecondP3sym, &SecondP4sym, &BN, SecondCsym, SecondCnum, ThirdCnum);
            system("cls");
            P2P3P4Ending(P1, SecondP1num, SecondP2num, SecondP3num, SecondP4num, SecondP1sym, SecondP2sym, SecondP3sym, SecondP4sym, team1, team2, nums);
            DeclareWinner(&T1, &T2);
            EnterContinue();
            // For going back to the condition of while loop and check which player should start next round(or the game is over)
            continue;
        }
        if (Pl3 == 1)
        {
            // Returning the flag to its initial value.
            Pl3 = 0;
            char ThirdP1sym, ThirdP2sym = '\0', ThirdP3sym = '\0', ThirdP4sym = '\0';
            int ThirdP1num, ThirdP2num, ThirdP3num, ThirdP4num;
            // Determining which card player 3 play at first.
            FirstCardBot(&ThirdP3num, &ThirdP3sym, &BN, symbolP3, numA3, numB3, numC3, numD3);
            // It,s player 4 turn.
            PlayingCardByBot(&ThirdP3sym, &ThirdP4sym, &ThirdP4num, symbolP4, numA4, numB4, numC4, numD4, &BN);
            // It's your turn.
            system("cls");
            P3Starting(P1, ThirdP3num, ThirdP4num, ThirdP3sym, ThirdP4sym, team1, team2, nums);
            int num;
            UserInput(&num,&f,&ThirdP1num,&ThirdP3sym,&ThirdP1sym,numberP1,symbolP1,nums);
            system("cls");
            board3(P1, ThirdP1num, ThirdP1sym, num, nums, team1, team2);
            EnterContinue();
            // It's Player 2 turn.
            PlayingCardByBot(&ThirdP3sym, &ThirdP2sym, &ThirdP2num, symbolP2, numA2, numB2, numC2, numD2, &BN);
            // Determining the winner.
            char SecondCsym[3] = {ThirdP1sym, ThirdP2sym, ThirdP4sym};
            int SecondCnum[3] = {0};
            int ThirdCnum[4] = {ThirdP3num};
            WhoWinPl3(&team1, &team2, &Pl1, &Pl2, &Pl3, &Pl4, &T1, &T2, &ThirdP1num, &ThirdP2num, &ThirdP3num, &ThirdP4num,
            &ThirdP1sym, &ThirdP2sym, &ThirdP3sym, &ThirdP4sym, &BN, SecondCsym, SecondCnum, ThirdCnum);
            system("cls");
            P2P3P4Ending(P1, ThirdP1num, ThirdP2num, ThirdP3num, ThirdP4num, ThirdP1sym, ThirdP2sym, ThirdP3sym, ThirdP4sym, team1, team2, nums);
            DeclareWinner(&T1, &T2);
            EnterContinue();
            // For going back to the condition of while loop and check which player should start next round(or the game is over)
            continue;
        }
        if (Pl4 == 1)
        {
            // Returning the flag to its initial value.
            Pl4 = 0;
            char ForthP1sym, ForthP2sym = '\0', ForthP3sym = '\0', ForthP4sym = '\0';
            int ForthP1num, ForthP2num, ForthP3num, ForthP4num;
            // Determining which card player 4 play at first.
            FirstCardBot(&ForthP4num, &ForthP4sym, &BN, symbolP4, numA4, numB4, numC4, numD4);
            // It's your turn.
            system("cls");
            P4Starting(P1, ForthP4num, ForthP4sym, team1, team2, nums);
            int num;
            UserInput(&num,&f,&ForthP1num,&ForthP4sym,&ForthP1sym,numberP1,symbolP1,nums);
            system("cls");
            board3(P1, ForthP1num, ForthP1sym, num, nums, team1, team2);
            EnterContinue();
            // It's player 2 turn.
            PlayingCardByBot(&ForthP4sym, &ForthP2sym, &ForthP2num, symbolP2, numA2, numB2, numC2, numD2, &BN);
            // It's player 3 turn.
            PlayingCardByBot(&ForthP4sym, &ForthP3sym, &ForthP3num, symbolP3, numA3, numB3, numC3, numD3, &BN);
            // Determining the winner.
            char SecondCsym[3] = {ForthP1sym, ForthP2sym, ForthP3sym};
            int SecondCnum[3] = {0};
            int ThirdCnum[4] = {ForthP4num};
            WhoWinPl4(&team1, &team2, &Pl1, &Pl2, &Pl3, &Pl4, &T1, &T2, &ForthP1num, &ForthP2num, &ForthP3num,
            &ForthP4num,&ForthP1sym, &ForthP2sym, &ForthP3sym, &ForthP4sym, &BN, SecondCsym, SecondCnum, ThirdCnum);
            system("cls");
            P2P3P4Ending(P1, ForthP1num, ForthP2num, ForthP3num, ForthP4num, ForthP1sym,
            ForthP2sym, ForthP3sym, ForthP4sym, team1, team2, nums);
            DeclareWinner(&T1, &T2);
            EnterContinue();
            // For going back to the condition of while loop and check which player should start next round(or the game is over)
            continue;
        }
    }
    system("cls");
    if (team1 == 6)
        printf("\nTeam1 won,congrats!");
    if (team2 == 6)
        printf("\nTeam2 won,congrats!");
    fflush(stdin);
    getchar();
}
