#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long long cardnumber = get_long_long("Credit Card Number Please: ");
    int everyotherdigit = 0;
    int leftoverdigits = 0;
    int firstdigit = 0;
    int seconddigit = 0;

    int numberlength = floor(log10(llabs(cardnumber))) + 1;
    int creditarray[numberlength];

    for (int i = 0; i < numberlength; i++)//creates an array of the given credit card number
    {
        creditarray[i] = cardnumber % 10;
        cardnumber /= 10;
    }
    //checks to see that the given credit card number has a valid number in its first digit
    if (creditarray[numberlength - 1] == 3 ||
        creditarray[numberlength - 1] == 4 ||
        creditarray[numberlength - 1] == 5)
    {
        //a for loop that creates a total for the digits of everyother number multiplied by two (starting with the second to last),
        //checking whether or not the total in a cycle is two digits or larger
        for (int i = 1; i < numberlength + 1; i += 2)
        {
            if ((creditarray[i] * 2) >= 10)
            {
                firstdigit = floor((creditarray[i] * 2) / 10);
                seconddigit = (creditarray[i] * 2) % 10;
                everyotherdigit += firstdigit + seconddigit;
            }
            else
            {
                everyotherdigit += (creditarray[i] * 2);
            }
        }
        //for loop that adds together the remaining digits
        for (int i = 0; i < numberlength; i += 2)
        {
            leftoverdigits += creditarray[i];
        }
        //checks if the card could be a real credit card, then checks to see if it is a visa
        if (((leftoverdigits + everyotherdigit) % 10) == 0 && creditarray[numberlength - 1] == 4)
        {
            printf("VISA\n");
        }
        //checks if the credit card is real, then checks first digit for american express
        if (((leftoverdigits + everyotherdigit) % 10) == 0 && creditarray[numberlength - 1] == 3)
        {
            printf("AMEX\n");
        }
        //checks for card legitimacy, then checks for mastercard
        if (((leftoverdigits + everyotherdigit) % 10) == 0 && creditarray[numberlength - 1] == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
