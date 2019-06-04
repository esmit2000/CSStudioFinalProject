//Helper functions for the sort race

#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include "helpers.h"

//Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise
bool check_flag(char *str)
{
    //if (argv[1] == a || argv[1] == b || argv[1] == r || argv[1] == s)
    if (strcmp(str, "-a") == 0 || strcmp(str, "-b") == 0 || strcmp(str, "-r") == 0 || strcmp(str, "-s") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Sorts array of n values using bubble sort.
void bubble(int values[], int n)
{
    //placeholder variable used for swapping variables
    int placeHolder;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[j] > values[j + 1])
            {
                //swap function
                placeHolder = values[j];
                values[j] = values[j + 1];
                values[j + 1] = placeHolder;
            }
        }
    }
}

//Sorts array of n values using selection sort.
void selection(int values[], int n)
{
     int placeHolder = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        //for loop checking array for value less than given min
        for (int j = i; j < n - 1; j++)
        {
            if (values[j + 1] < values[min])
            {
                min = j + 1;
            }
        }
        //swaps values upon finding new min
        placeHolder = values[min];
        values[min] = values[i];
        values[i] = placeHolder;
    }
}

//Sorts array of n values using insertion sort.
void insertion(int values[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int element = values[i];
        int j = i;
        //As insertion shifts values over rather than replacing them, a swap function like those used above are not necessary.
        while (j > 0 && values[j - 1] > element)
        {
            values[j] = values[j - 1];
            j = j - 1;
        }
        values[j] = element;
    }
}

