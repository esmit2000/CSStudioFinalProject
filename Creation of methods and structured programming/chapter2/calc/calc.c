#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc == 4)//checks for the expected value of four arguments
    {
        float one = atof(argv[1]);
        //variable to simplify process, represents first argument (after call of ./calc)
        float two = atof(argv[3]);
        //Represents third argument or second digit, makes all the difference for some reason
        if (! strcmp(argv[2], "x"))//checks for multiplication sign, then performing the givin calculation
        {
            printf("%.6f\n", (one * two));
        }
        else if (! strcmp(argv[2], "/"))//checks for division
        {
            printf("%f\n", (one / two));
        }
        else if (! strcmp(argv[2], "+"))//checks for addition
        {
            printf("%f\n", (one + two));
        }
        else if (! strcmp(argv[2], "-"))//checks for subtraction
        {
            printf("%f\n", (one - two));
        }
        else if (! strcmp(argv[2], "%"))//checks for mod
        {
            printf("%f\n", fmod(one, two));
        }
        else//if different sign is used, returns error message
        {
            printf("Please try again\n");
            return 1;
        }
    }
    else//if there are not four arguments, error message is returned
    {
        printf("Please try again\n");
        return 1;
    }
}
