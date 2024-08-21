#include<stdio.h>
#include"MIN.h"
//Function for calculating index of minimum value in an array.
int MIN(int numOfElements, int arr[])
{
    int Min = arr[0], Min_i = 0;
    for (int i = 1; i < numOfElements; i++)
    {
        if ((arr[i] < Min)&&(arr[i]!=0))
        Min = arr[i];
        Min_i = i;
    }
    return Min_i;
}