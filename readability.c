#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//PROTOTYPES
string users_text(void);
int counting_letter(string text);
int counting_words(string text);
int counting_sentences(string text);

int main(void)
{
    string text = users_text();
    int n_letters = counting_letter(text);
    int n_words = counting_words(text);
    int n_sentences = counting_sentences(text);
    /*printf("%i letter(s)\n",n_letters);
    printf("%i word(s)\n",n_words);
    printf("%i sentence(s)\n",n_sentences);*/

    // caltulating L and S variables for the formula
    float L = ((float) n_letters / (float) n_words) * 100;
    float S = ((float) n_sentences / (float) n_words) * 100;

    //using the formula to deterinate the grade of lecture
    int grade = (int) round(0.0588 * L - 0.296 * S - 15.8);

    //printing the grade
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }


}

//getting the text from the user
string users_text(void)
{
    string text = get_string("Text: ");
    return text;
}

//counting the numbers of N char in the text
int counting_letter(string text)
{
    int n_letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            n_letters++;
        }
    }
    return n_letters;
}

//counting the numbers of words in the text
int counting_words(string text)
{
    int n_words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((i == 0 && text[i] != ' ') || (i != len - 1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            n_words++;
        }
    }
    return n_words;
}

//counting sentences
int counting_sentences(string text)
{
    int n_sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            n_sentences ++;
        }
    }
    return n_sentences;
}
