#include <stdio.h>
#define TRUE 1;
int main()
{
    // Giving the amount of calories for each food.
    int food1 = 329, food2 = 127, food3 = 61, food4 = 83, food5 = 156;
    int food6 = 296, food7 = 496, food8 = 73, food9 = 34, food10 = 16;
    // Defining variables( x is a counter for loop).
    int numOfDays, amountOfCalories = 0, x = 1, numOfFood;
    printf("Plese enter the number of days:");
    scanf("%d", &numOfDays);
    printf("Enter the numbers of food that Soheil eat on each day:");
    // Calculating amount of calories according to number of-
    //- days and number of food from the user input.
    for (x; x <= numOfDays; x++)
    {

        printf("\n\n");
        scanf("%d", &numOfFood);
        switch (numOfFood)
        {
        case 1:
            amountOfCalories += food1;
            break;
        case 2:
            amountOfCalories += food2;
            break;
        case 3:
            amountOfCalories += food3;
            break;
        case 4:
            amountOfCalories += food4;
            break;
        case 5:
            amountOfCalories += food5;
            break;
        case 6:
            amountOfCalories += food6;
            break;
        case 7:
            amountOfCalories += food7;
            break;
        case 8:
            amountOfCalories += food8;
            break;
        case 9:
            amountOfCalories += food9;
            break;
        case 10:
            amountOfCalories += food10;
            break;
        default:
            printf("Please enter a number from 1 to 10");
        }
        // Re-enter the number of food if it's out of range
        if ((numOfFood > 10) || (numOfFood < 1))
            continue;
    }
    // Showing the result of the diet.
    if ((amountOfCalories) - (numOfDays * 100) > 0)
        printf("Chagh");
    if ((amountOfCalories) - (numOfDays * 100) == 0)
        printf("Bedoone Taghir");
    if ((amountOfCalories) - (numOfDays * 100) < 0)
        printf("Laghar");

    return 0;
}