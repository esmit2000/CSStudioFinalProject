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

    for (int i = 0; i < numberlength; i++)
    {
        creditarray[i] = cardnumber % 10;
        cardnumber /= 10;
        //printf("%d", creditarray[i]);
    }
    //printf("\n");
    //printf("%d\n", creditarray[(numberlength - 1)]);
    if (creditarray[numberlength - 1] == 4)
    {
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
        for (int i = 0; i < numberlength; i += 2)
        {
            leftoverdigits += creditarray[i];
        }
        //printf("%d\n", everyotherdigit);
        //printf("%d\n", leftoverdigits);
        if (((leftoverdigits + everyotherdigit) % 10) == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (creditarray[numberlength - 1] == 5)
    {
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
        for (int i = 0; i < numberlength; i += 2)
        {
            leftoverdigits += creditarray[i];
        }
        //printf("%d\n", everyotherdigit);
        //printf("%d\n", leftoverdigits);
        if (((leftoverdigits + everyotherdigit) % 10) == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (creditarray[numberlength - 1] == 3)
    {
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
        for (int i = 0; i < numberlength; i += 2)
        {
            leftoverdigits += creditarray[i];
        }
        //printf("%d\n", everyotherdigit);
        //printf("%d\n", leftoverdigits);
        if (((leftoverdigits + everyotherdigit) % 10) == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID");
    }
}
