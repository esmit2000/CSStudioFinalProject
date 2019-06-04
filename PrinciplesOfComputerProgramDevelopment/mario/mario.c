#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    //User input of height, this determines how tall the pyramid is and how large the base is
    int constant = height - 1;
    // A subtraction constant, this determines how many spaces are in the first row

    if (height >= 0 && height < 24)// checks for a height between 0 and 23
    {
        for (int i = 0; i < height; i++)//for loop that counts up until it gets to the correct height
        {
            for (int j = 0; j < (constant); j++)
                //for loop that counts up from zero until constant (or number of spaces) is reached, printing a space each time
            {
                printf(" ");
            }
            for (int j = 0; j < (height - constant); j++)
                //after spaces are printed, for loop counts up to difference of height and constant, printing the correct number if hashes
            {
                printf("#");
            }
            printf("  ");//prints center break in pyramid
            for (int j = 0; j < (height - constant); j++)
                //for loop repeats last print of hashes without spaces, making a mirror image
            {
                printf("#");
            }
            constant--;//subtracts one from constant so that the next row has one more hash on each side
            printf("\n");//new line for next row of the pyramid
        }
    }
    else//if height is not between 0 and 24, it will prompt the user to try again
    {
        printf("That number is invalid, please chooes a number between 0 and 23");
        main();
    }
}