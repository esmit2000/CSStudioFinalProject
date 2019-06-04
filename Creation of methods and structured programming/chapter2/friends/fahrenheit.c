#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)//if two arguments are given, sets celsius equal to given argument in command line
    {
        float celsius = atoi(argv[1]);
        float fahrenheit = ((celsius * 9) / 5) + 32;//equation for celsius to fahrenheit conversion
        printf("F: %.1f\n", fahrenheit);//prints fahrenheit value
    }
    else//if not two arguments, returns value of 1
    {
        return 1;
    }
}