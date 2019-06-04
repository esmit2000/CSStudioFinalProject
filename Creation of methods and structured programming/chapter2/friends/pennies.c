#include <cs50.h>
#include <stdio.h>
#include <math.h>
#define MAX_DAYS 31

int main(int argc, string argv[])
{
    if (argc == 3)
    {
        int daysInMonth = atoi(argv[1]);//takes input of days in month from command line 2nd argument
        int start = atoi(argv[2]);//takes input of starting amount from command line 3rd argument
        long long total = start;


        if ((argc == 3 && 28 <= daysInMonth && daysInMonth <= 31) && (start >= 1))
            //as long as three arguments are given, the days in month are between 28 and 31, and at least one penny to start
            //the following for loop will occur
        {
            for (int i = 1; i < daysInMonth; i = i + 1)
                //for loop that doubles the ammount of pennies gained each day and adds to total
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
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
