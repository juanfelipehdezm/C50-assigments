#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //promping height from user
    int height;
    do
    {
        height = get_int("Height: ");

    }
    while (height < 1 || height > 8);

    // amking the columns
    for (int i = 0; i < height; i ++)
    {
        //printf("#");
        //making the horizontal lines
        for (int j  = 0; j < height; j++)
        {
            if (i + j  < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");

    }

}
