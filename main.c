/**
 * @file main.c
 * @brief Main file where all the functions are called from.
 *
 * @author Streata Nicoleta Alexandra
 *
 * Allows the user to select options based on what he wants from the program.
 */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
 /**
    * @fn int main ()
    * @brief Main function that takes user input for generating output
    */
{ int choice;

    int *coins_value;
    int *coins_uses;
    int sum;
    int no_coins;
    int iterator;

    printf("\n-----------------------------\n\n");
    printf("\n--------MAKING CHANGE--------\n\n");
    printf("\n-----------------------------\n\n");


    printf("\n\nEnter the amount : ");
    scanf("%d", &sum);

    if(sum < 1) {
        printf("\nInvalid amount!\n");
        return 0;
    }

    printf("\n\nEnter the number of coin types : ");
    scanf("%d", &no_coins);

    if(no_coins < 1) {
        printf("\nInvalid value!\n");
        return 0;
    }

    coins_value = malloc(no_coins * sizeof(int));
    coins_uses = malloc(no_coins * sizeof(int));

    memset(coins_uses, 0, no_coins * sizeof(int));

    printf("\n\nEnter the distinct value of coins : \n");
    for(iterator = 0; iterator < no_coins; iterator++) {
        printf("(%d) : ", iterator + 1);
        scanf("%d", &coins_value[iterator]);
        if(coins_value[iterator] < 1) {
            printf("\nInvalid value!\n");
            return 0;
        }
    }

    decreasing_ordering(coins_value, no_coins);
    making_change(coins_value, coins_uses, no_coins, sum);
    print_coins(coins_value, coins_uses, no_coins);

    return 0;
}
