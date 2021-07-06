#include <cs50.h>
#include <stdio.h>

//PROTOTYPES = functions
float mean(int lenght, int array[]);

int main(void)
{

    // creating an array in C of n size
    int total = get_int("Total nuber of scores: ");
    int scores[total];
    // asking the user to give me the socres to add to the array
    for (int i = 0; i < total; i++)
    {
        scores[i] = get_int("Score: ");
    }

    float average = mean(total, scores);
    printf("Average %f\n", average);

}
// function to return the average
float mean(int lenght, int array[])
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum += array[i];
    }

    return sum / (float)lenght; // im returning an float so i must cast to float
}
