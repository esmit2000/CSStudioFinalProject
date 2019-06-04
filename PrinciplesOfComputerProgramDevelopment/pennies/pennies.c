#include <cs50.h>
#include <stdio.h>
#include <math.h>
#define MAX_DAYS 31

int main(void)
{
    int daysInMonth = get_float("Days in month: ");
    int start = get_float("Pennies on first day: ");
    //float total = (SA * pow(2, DIM)) / 100;
    long long total = start;


    if ((28 <= daysInMonth && daysInMonth <= 31) && (start >= 1))
    {
        for (int i = 1; i < daysInMonth; i = i + 1)
        {
            total = total + (start * pow(2, i));
            if (i == daysInMonth - 1)
            {
                printf("$%.2f\n", total / 100.0);
            }
        }
    }
    else
    {
        printf("Please input an accurate amount of days or pennies\n");
        main();
    }
}