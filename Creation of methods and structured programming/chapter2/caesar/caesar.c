#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

/*Hello, if you didn't get my first message than this one is irrelevant, I (with the help of Emmet)
figured out a better way of doing this problem and the following is the revision*/

int main(int argc, string argv[])
{
    if (argc != 2)//returns error message if a second argument is not given
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    else
    {
        string plaintext = get_string("Plaintext: ");
        int shift = (atoi(argv[1]) % 26);
        //second argument (the shift value) is modded by 26 in case the number is larger than 26

        printf("ciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
            //for loop that goes through each letter of the given plaintext
        {
            if (isalpha(plaintext[i]))
                //if the character in question is a letter, check if it is still alpha when added by shift
            {
                if (isalpha(plaintext[i] + shift) == false)
                {
                    printf("%c", (plaintext[i] + shift) - 26);
                    //if not, subtract shift and letter value by 26 to loop around

                }
                else
                {
                    printf("%c", (plaintext[i] + shift));
                    //else, print the letter [shift] spaces from the plaintext letter
                }
            }
        }
        printf("\n");
    }
}