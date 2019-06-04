#define _XOPEN_SOURCE
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <unistd.h>

int main(void)
{
    string a = "AAAA";
    //printf("%c\n", a[2]);
    a[2] = (a[2] + 1);
    printf("%s\n", a);
}