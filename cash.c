#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    // geting the change from the user
    float change;
    do
    {
        change = get_float("Change: ");
    }
    while (change <= 0);
    //printf("Change : %f\n",change);
    
    // rounding
    int cents = round(change * 100);
    int coins = 0;
    // calculating the number of coins needed
    while (cents >= 25)
    {
        cents -= 25;
        coins += 1;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coins += 1;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coins += 1;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coins += 1;
    }

    printf("Coins: %i\n", coins);
}
