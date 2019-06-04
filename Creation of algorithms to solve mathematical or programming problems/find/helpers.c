/**
 * helpers.c
 *
 * CS50 AP
 * Find
 *
 * Helper functions.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   int countingArray[5] = {0,0,0,0,0};
   int countValue;
   for (int i = 0; i < n - 1; i++)
   {
       countValue = values[i];
       countingArray[countValue]++;
   }
   for (int i = 0; i < n - 1; i++)
   {
       printf("%i,", countingArray[i]);
   }
}
