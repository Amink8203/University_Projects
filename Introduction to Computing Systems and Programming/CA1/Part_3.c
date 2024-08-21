#include <stdio.h>

int main()
{
    // Defining variables(x is a helping variable for loop).
    int a, b, c;
    double khata, x;
    // Defining i for counting the number of roots.
    int i = 0;
    printf("Please enter a and b and c and amount of fault:\n");
    printf("a:", a);
    scanf("%d", &a);
    printf("b:", b);
    scanf("%d", &b);
    printf("c:", c);
    scanf("%d", &c);
    printf("Fault:");
    scanf("%lf", &khata);
    // Checking whether a is the highest amount of a,b,c.
    if (a >= b && a >= c)
    {
        // Loop for checking every number between -a^2 and a^2 and finding roots.
        for (x = -(a * a); x <= (a * a) && x >= -(a * a); x += (khata * khata * khata))
        {
            if ((((x * x * x) + (a * x * x) + (b * x) + c) <= khata) && (((x * x * x) + (a * x * x) + (b * x) + c) >= -khata))
            {
                printf("%lf\n", x);
                // i for counting roots.
                i++;
                // Prevent from making extra roots.
                x += khata;
            }
        }
        // Counting number of roots and typing "Bedoone rishe" for no root.
        if (i == 0)
        {
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
        }
        if (i == 1)
        {
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
        }
        if (i == 2)
            printf("BEDOONE RISHE\n");
    }
    // Checking whether b is the highest amount of a,b,c.
    if (b >= a && b >= c)
    {
        // Loop for checking every number between -b^2 and b^2 and finding roots.
        for (x = -(b * b); x <= (b * b) && x >= -(b * b); x += (khata * khata * khata))
        {
            if ((((x * x * x) + (a * x * x) + (b * x) + c) <= khata) && (((x * x * x) + (a * x * x) + (b * x) + c) >= -khata))
            {
                printf("%lf\n", x);
                // i for counting roots.
                i++;
                // Prevent from making extra roots.
                x += khata;
            }
        }
        // Counting number of roots and typing "Bedoone rishe" for no root.
        if (i == 0)
        {
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
        }
        if (i == 1)
        {
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
        }
        if (i == 2)
            printf("BEDOONE RISHE\n");
    }
    // Checking whether c is the highest amount of a,b,c.
    if (c >= a && c >= b)
    {
        // Loop for checking every number between -c^2 and c^2 and finding roots.
        for (x = -(c * c); x <= (c * c) && x >= -(c * c); x += (khata * khata * khata))
        {
            if ((((x * x * x) + (a * x * x) + (b * x) + c) <= khata) && (((x * x * x) + (a * x * x) + (b * x) + c) >= -khata))
            {
                printf("%lf\n", x);
                // i for counting roots.
                i++;
                // Prevent from making extra roots.
                x += khata;
            }
        }
        // Counting number of roots and typing "Bedoone rishe" for no root.
        if (i == 0)
        {
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
        }
        if (i == 1)
        {
            printf("BEDOONE RISHE\n");
            printf("BEDOONE RISHE\n");
        }
        if (i == 2)
            printf("BEDOONE RISHE\n");
    }
}