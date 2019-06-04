#define _XOPEN_SOURCE
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string a = argv[1];
        a[3] = a[3] + 1;
        printf("%s\n", a);
    }
}