#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//PROTPTYPES
bool valid_key(string text);

int main(int argc, string argv[])
{
    //is the key valid ?
    if (argc != 2 || !valid_key(argv[1]))
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    //tuerns string into an int "2" >> 2
    int k = atoi(argv[1]);


    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char m = 'A';
            if (islower(plaintext[i]))
            {
                m = 'a';

            }
            //formula to apply ascii encode
            printf("%c", (plaintext[i] - m + k) % 26 + m);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}

//cheking if the key es valid
bool valid_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        // the ! mins if its diferent from a digit
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
