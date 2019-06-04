#define _XOPEN_SOURCE
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack k\n");
        return 1;
    }
    else
    {
        string hash = argv[1];
        string pass = "AAAA";
        //printf("%s\n", crypt(hash, "50"));
        for (int i = 0; i < 57; i++)
        {
            pass[0]++;
            if (crypt(pass, "50") == hash)
            {
                printf("%s", pass);
            }
            else
            {
                for (int j = 0; j < 57; j++)
                {
                    pass[1]++;
                    if (crypt(pass, "50") == hash)
                    {
                        printf("%s", pass);
                    }
                    else
                    {
                        for (int k = 0; k < 57; k++)
                        {
                            pass[2]++;
                            if (crypt(pass, "50") == hash)
                            {
                                printf("%s", pass);
                            }
                            else
                            {
                                for (int l = 0; l < 57; l++)
                                {
                                    pass[3]++;
                                    if (crypt(pass, "50") == hash)
                                    {
                                        printf("%s", pass);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}