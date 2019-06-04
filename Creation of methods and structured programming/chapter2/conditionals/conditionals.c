/* CONDITIONAL PRACTICE PROBLEMS
 * Developed by: Mr. Richardi 2017
 *
 * Completed by: Eric Smith
 */

// See reference.cs50.net for detailed manuals
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*  GRADUATION COMPARISON
        Define an integer variable named richardi_grad_year and initialize it to a value of 2002
        Define an integer variable named my_birth_year and intialize it to the 4 digit year you were born.
        Create an if / else block that prints "I was born BEFORE Richardi graduated Kennett", or
        "I was born AFTER Richardi graduated Kennett", after comparing your birth year to my graduation year
    */

    // TODO - ADD YOUR CODE AFTER THIS
    int richardi_grad_year = 2002;
    int my_birth_year = 2000;
    if (richardi_grad_year < my_birth_year)
    {
        printf("I was born AFTER Richardi graduated Kennett\n");
    }
    else
    {
        printf("I was born BEFORE Richardi graduated Kennett\n");
    }



    /*  AGE COMPARISON
        Ask the user for their age using get_string() {see reference.cs50.net for documentation} and store it in
        an integer variable called user_age
        Print a message that says if the user is able to drive
        Print a message that says if the user is able to vote
        Print a message that says if the user is at standard retirement age for social security (65)
        For all the messages, if the user is NOT the minimum age, print how many years until they do qualify
    */

    // TODO - ADD YOUR CODE AFTER THIS
    int user_age = atoi(get_string("How old are you? "));
    if (user_age >= 16)
    {
        printf("You are able to drive\n");
    }
    else
    {
        int years_until = 16 - user_age;
        printf("You will be able to drive in %d years\n", years_until);
    }
    if (user_age >= 18)
    {
        printf("You are old enough to vote\n");
    }
    else
    {
        int years_until = 18 - user_age;
        printf("You will be able to vote in %d years\n", years_until);
    }
    if (user_age >= 65)
    {
        printf("You are at the standard retirement age for social security\n");
    }
    else
    {
        int years_until = 65 - user_age;
        printf("You will be able to retire (hopefully) in %d years\n", years_until);
    }


    /*  FREEZING OR BOILING COMPARISON
        Ask the user for a water temperature in fahrenheit and store it as a floating point value
        Construct an if / else if / else block that prints a message that states if the water is freezing (solid), boiling (gas),
        or inbetween (liquid).  Your code should only print a single message.
    */

    // TODO - ADD YOUR CODE AFTER THIS
    float water_temperature = atof(get_string("What is the temperature of the water? "));
    if (water_temperature <= 32.0)
    {
        printf("solid\n");
    }
    else if (water_temperature > 32.0 && water_temperature < 212.0)
    {
        printf("liquid\n");
    }
    else if (water_temperature >= 212.0)
    {
        printf("gas\n");
    }


    /*  COUNTING
        COUNTUP: Construct a loop (while loop or for loop) that prints all numbers from 1 to 50.
        COUNTDOWN: Construct a loop that prints numbers from 50 to 1.
        EVENS: Construct a loop that prints all even numbers from 1 to 100.
        FIFTH: Construct a loop that prints every 5th number from 1 to 100.
    */

    // TODO - ADD YOUR CODE AFTER THIS
    int start = 0;
    int end = 51;
    int even = 0;
    int fifth = 0;
    for (int i = 0; i < 50; i++)
    {
        start++;
        printf("%d, ", start);
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < 50; i++)
    {
        end--;
        printf("%d, ", end);
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < 50; i++)
    {
        even += 2;
        printf("%d, ", even);
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        fifth += 5;
        printf("%d, ", fifth);
    }
    printf("\n");


    /*  DIVISIBLE
        Ask the user for an integer between 1 and 10 named divisor, ensure you do not move forward until they enter a valid number
        Print out all numbers from 1 to 250 that are divisible by divisor (e.g. divide evenly with 0 remainder)
    */

    // TODO - ADD YOUR CODE AFTER THIS
    int divisor = atoi(get_string("Give me a number between 1 and 10: "));
    while (divisor < 1 || divisor > 10)
    {
        divisor = atoi(get_string("Please enter a valid number: "));
    }
    for (int i = 1; i <= 250; i++)
    {
        if (i % divisor == 0)
        {
            printf("%d, ", i);
        }
    }
    printf("\n");



}