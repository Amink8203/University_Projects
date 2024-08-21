#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include"UserInput.h"
#define TRUE 1
#define PLAYER 4
#define CARDS 11
//Recieves the input from 0 to 10 from user and find it's symbol and number related to the index.
void UserInput(int* num,int*f,int* SecondP1num,char* SecondP2sym,char* SecondP1sym,int numberP1[CARDS],char symbolP1[CARDS],int nums[CARDS]){
   printf("Please choose a card that hasn't been used:");
            //Flag for preventing the user from entering inputs that are against the rules.
            int g=0;
            while (TRUE)
            {
                fflush(stdin);
                g=0;
                scanf("%d", &(*num));
                for(int i=0;i<CARDS;i++){
                    if(symbolP1[i]==*SecondP2sym){
                        if(symbolP1[*num]!=*SecondP2sym){
                            //Flag up!
                            g=1;
                            break;
                        }
                    }
                }
                if ((*num < 0 || *num > 10) || symbolP1[*num] == '\0')
                g=2;
                if(g==2){
                    printf("You must enter a number from 0 to 10 that hasn't been chosen yet,let's try again:");
                    continue;
                }
                else if(g==1){
                printf("You have the base card!Please choose from them:");
                continue;
                }
                else
                break;
            }
            // For showing '-' and '0' in the board.
            nums[*f] = *num;
            ++*f;
            for (int i = 0; i < 11; i++)
            {
                if (*num == i)
                {
                    *SecondP1sym = symbolP1[i];
                    symbolP1[i] = '\0';
                    *SecondP1num = numberP1[i];
                    numberP1[i] = 0;
                    break;
                }
            }
}