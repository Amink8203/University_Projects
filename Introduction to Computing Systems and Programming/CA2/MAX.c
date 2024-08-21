#include<stdio.h>
#include"MAX.h"
//Function for calculating index of maximum value in an array.
int MAX(int numOfElements, int arr[])
{
    int Max = arr[0], Max_i = 0;
    for (int i = 1; i < numOfElements; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
            Max_i = i;
        }
    }
    return Max_i;
}