#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long isbn = get_long_long("What is the product's ISBN: ");
    int isbnarray[10];
    int constant = 1;
    int total = 0;

    //trasforms given isbn into an array by storing each number as an array digit periodically starting from the end, dividing total by ten each time to prepare for next.
    for (int i = 0; i < 10; i++)
    {
        isbnarray[i] = isbn % 10;
        isbn /= 10;
    }
    //starting from isbnarray[9] or the first digit, multiplies by corresponding digit number through int constant (ie first times one, second times 2, etc.). stores in total
    for (int i = 9; i > 0; i--)
    {
        total += isbnarray[i] * constant;
        constant ++;
    }
    //checks that total % 11 corresponds to the last digit of the isbn.
    if ((total % 11) == isbnarray[0])
    {
        printf("YES\n");
        printf("%d\n", total);
    }
    //if not, prints no. second print statement for debugging.
    else
    {
        printf("NO\n");
        printf("%d\n", total);
    }
}