#include <stdio.h>
#define TRUE 1
#define LastFloor 8
#define FirstFloor 1
#define FirstRoom 1
#define LastRoom 16

int main()
{
    //Defining variables.
    int floor, room, area, numOfOffice, numOfJumps = 0;
    // N is the height from  ground after each jump.
    float height, N = 0.0, x; 
    printf("Please enter a 3-digit number as the number of master's office.\n");
    printf("First digit from left is the number of floor(from 1 to 8).\n");
    printf("The next 2 digits is the number of room(from 1 to 16).\n");
    printf("The number:");
    // Getting a correct number for room.
    while (TRUE)
    {
        scanf("%d", &numOfOffice);
        //First digit from left is the number of floor.
        floor = (numOfOffice) / 100;
        //The next two digits is the number of room.
        room = (numOfOffice) % 100;
        if ((room < FirstRoom || room > LastRoom) && (floor < FirstFloor || floor >LastFloor ))
        {
            printf("Please pay attention to the both room and floor ranges at the first of the program and enter a correct number:");
            continue;
        }
        if ((room < FirstRoom) || (room > LastRoom))
        {
            printf("Notice that the number of room must be from 1 to 16,Let's try another number: ");
            continue;
        }
        if ((floor < FirstFloor) || (floor > LastFloor))
        {
            printf("Notice that the number of floor must be from 1 to 8,Let's try another number: ");
            continue;
        }

        else
            break;
    }
    // Calculating number of area according to the room number.
    if (room >= 1 && room <= 4) 
    {
        area = 1;
    }
    else if (room >= 5 && room <= 8)
    {
        area = 2;
    }
    else if (room >= 9 && room <= 12)
    {
        area = 3;
    }
    else if (room >= 13 && room <= 16)
    {
        area = 4;
    }
    printf("Please enter the height of the first jump(less than 1 meter):");
    scanf("%f", &height);
    // Not giving permission to enter height out of the range.
    while (TRUE)
    {
        if ((height <= 0) || (height >= 1))
        { 
            printf("It must be between 0 and 1,Please enter another number accordingly:");
            scanf("%f", &height);
        }

        else
            break;
    }
    N = N + height;
    // Defining x to not re-init "height" in the for loop.
    x = height / 2; 
    // Calculating number of jumps.
    for (x; N < (2 * floor) + 1; x)
    { 
        N = N + (height / 2);
        numOfJumps++;
    }
    printf("area:%d\nnumber of jumps:%d", area, numOfJumps);
    return 0;
}