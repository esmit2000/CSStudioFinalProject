#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int main (int argc, string argv[])
{
    if (argc == 2) //checks if two arguments are given
    {
        printf("Hello, %s!\n", argv[1]);//prints hello + argv[1], or the argument for given name
    }
    if (argc != 2)//If there are not two given arguments, a value of one will be returned.
    {
        return 1;
    }
}