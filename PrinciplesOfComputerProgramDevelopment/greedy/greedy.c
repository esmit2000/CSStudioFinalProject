#include <cs50.h>
#include <stdio.h>
#include <math.h>
#define QUARTERS 25
#define DIMES 10
#define NICKELS 5
#define PENNIES 1

int main(void)
{
    //Gets input of change from user, forces float and rejects submission of whole numbers
    float inputchange = ((get_float("How much change is needed: ")) * 1000) / 10;
    int coins = 0;

    //Cycles through, counts number of quarters and then subracts from total, this number of quarters to total coins that will be returned at the end. Repeats with other coins.
    int quarters = floor(inputchange / QUARTERS);
    coins += quarters;
    inputchange -= (quarters * QUARTERS);
    int dimes = floor(inputchange / DIMES);
    coins += dimes;
    inputchange -= (dimes * DIMES);
    int nickels = floor(inputchange / NICKELS);
    coins += nickels;
    inputchange -= (nickels * NICKELS);
    int pennies = floor(inputchange / PENNIES);
    coins += pennies;
    inputchange -= (pennies * PENNIES);

    //Prints end value of coins.
    printf("%d\n", coins);
}
