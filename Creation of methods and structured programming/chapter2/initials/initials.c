#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("");
    //takes input of name from user
    string zero = " ";
    string null = "\x00";
    //sets a standard for checking for space
    if (name[0] != *zero)
    {
        printf("%c", toupper(name[0]));
    }
    //prints the first letter of name in upper case (first letter will always be an initial if not a space)
    for (int i = 0; i < strlen(name); i++)
        //for loop that checks every letter of name for a space
    {
        if (name[i + 1] != *null)
        {
            if (name[i] == *zero && name[i + 1] != *zero)
            {
                printf("%c", toupper(name[i + 1]));
            }
        }
    }
    printf("\n");
}
