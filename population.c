#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size

    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold

    // WITH WHILE------
    int years = 0;
    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }

    // WITH FOR--------
    /*int years;
    for (years = 0; start_size < end_size; years++)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        //printf("Years: %i\n", years);
        //printf("n: %i\n", start_size);

    }*/

    // TODO: Print number of years

    printf("Years: %i\n", years);
}
