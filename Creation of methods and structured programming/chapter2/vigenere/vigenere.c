#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)//if a correct amount of arguments (two) is not given, an error message is given
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string shift = argv[1];//the second argument given is the shift value
    int shiftconstant = 0;
    //a constant variable used to shift the between letters of the shift value (without a second for loop)
    string a = "a";//constant "a" value to compare shift values to
    bool invalid = false;//boolean used for checking for invalid characters in shift
    for (int i = 0; i < strlen(shift); i++)
        //for loop used to check for invalid characters in shift
    {
        if (isalpha(shift[i]) == false)
        {
            invalid = true;
        }
    }
    if (invalid == true)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("Plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
            //for loop used for checking values and printing ciphertext
        {
            if (isalpha(plaintext[i]))
                //if the given character of plain text is alphabetical, check for given values
            {
                if (shiftconstant >= strlen(shift))
                    //if shift constant is larger than shift, it resets to the first letter of shift (0)
                {
                    shiftconstant = 0;
                }
                if (isalpha(plaintext[i] + (tolower(shift[shiftconstant]) - a[0])) == false)
                    //if given character plus shift value is not alphabetical, print that value minus 26
                {
                    printf("%c", (plaintext[i] + (tolower(shift[shiftconstant]) - a[0])) - 26);
                }
                else if (islower(plaintext[i]) == false &&
                         (isupper(plaintext[i] + (tolower(shift[shiftconstant]) - a[0])) == false))
                    //else if an uppercase value is given, and the outcome is lowercase, print that value minus 26
                {
                    printf("%c", (plaintext[i] + (tolower(shift[shiftconstant]) - a[0])) - 26);
                }
                else
                    //else, print the added value with no modifications
                {
                    printf("%c", (plaintext[i] + (tolower(shift[shiftconstant]) - a[0])));
                }
            }
            else//if given value of plain text is not alphabetical, print it.
            {
                printf("%c", plaintext[i]);
            }
            shiftconstant++;
            //shift constant equals itself plus one in order to shift to the next character of shift when the for loop resets
        }
        printf("\n");
    }
}