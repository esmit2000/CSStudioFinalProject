/**
 * generate.c
 *
 * CS50 AP
 * Find
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if the correct number of command line arguments (two or three) is not given, return an error of 1 and a usage message
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // saving the first command line argument (or technically second when including the call) as an int n
    int n = atoi(argv[1]);

    // if there are three arguments and a seed is given, use this argument as the seed value for srand48
    // if not, use null as the seed value to create "random values"
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // for loop that iterates n times, printing a random int per drand48 times the limit value
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int)(drand48() * LIMIT));
    }

    // success
    return 0;
}
