#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        n = get_float("Changed owed: "); //prompts the user for an amount of change
    }
    while (n < 0);
    int cents = round(n * 100);
    int quarters = cents / 25;
    int quarters_remainder = cents % 25;
    int dimes = quarters_remainder / 10;
    int dimes_remainder = quarters_remainder % 10;
    int nickels = dimes_remainder / 5;
    int pennies = dimes_remainder % 5;
    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}