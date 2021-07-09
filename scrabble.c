#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins! \n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        //just taking in count letter no any other char
        if (isalpha(word[i]))
        {
            //turning to upper casa so i have no problem is the players put the word in both cases
            char upper_letter = (char) toupper(word[i]);
            // we take - 'A' bc is the value 65 in the ASCII code so for example letter K(75) - A(65) = 10 so POINT[10] = 5
            score += POINTS[upper_letter - 'A'];
        }
    }
    return score;
}
