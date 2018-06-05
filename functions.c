
/**
 * @file functions.c
 * @brief C library containing the functions used for making change
 * @author Streata Nicoleta Alexandra
 */
#include <stdio.h>
#include "functions.h"
    int *coins_value;
    int *coins_uses;
    int sum;
    int no_coins;
    int iterator;

void decreasing_ordering (int *coins_value, int no_coins)
{
/**
     * @fn void decreasing_ordering(int *coins_value, int no_coins)
     * @brief Decreases the values of the coins.
     * @param *coins_value The coin values vector given by the user.
     * @param no_coins The total number of coins given by the user.
     *
     * The function decreases the values of the coins given by the user.
     */
    int iterator_1;
    int iterator_2;
    int aux;

    for (iterator_1 = 0; iterator_1 < no_coins - 1; iterator_1++) {
        for (iterator_2 = iterator_1 + 1; iterator_2 < no_coins; iterator_2++) {
            if (coins_value[iterator_2] > coins_value[iterator_1]) {
                aux = coins_value[iterator_1];
                coins_value[iterator_1] = coins_value[iterator_2];
                coins_value[iterator_2] = aux;
            }
        }
    }
}

void making_change (int *coins_value, int *coins_uses, int no_coins, int sum)
{
/**
     * @fn void making_change(int *coins_value, int *coins_uses, int no_coins, int sum)
     * @brief Find the total number of used coins.
     * @param *coins_value The coin values vector given by the user.
     * @param *coins_uses The coin vector that gives the total number of uses of each coin.
     * @param no_coins The total number of coins given by the user.
     * @param sum The total amount of used coins.
     *
     * The function calculates how many coins are used to form the amount of money using a greedy algorithm and returns the value.
     *
     */
    int iterator = 0;
    int total_coins = 0;
    int temp_coins;

    while (sum > 0) {
        temp_coins = sum / coins_value[iterator];
        sum -= temp_coins * coins_value[iterator];
        total_coins += temp_coins;
        coins_uses[iterator] = temp_coins;
        if (sum % coins_value[iterator] == 0) { //
            break;
        }
        iterator++;
        if (iterator > no_coins) {
            printf ("\nIt can not make the amount with the entered coins!\n\n");
            break;
        }
    }

    printf ("\nTotal of coins : %d \n", total_coins);
    printf ("\n\n--------------------\n\n");
}

void print_coins(int *coins_value, int *coins_uses, int no_coins)
{
/**
     * @fn void print_coins(int *coins_value, int *coins_uses, int no_coins)
     * @brief Prints out the coins and their uses.
     * @param *coins_value The coin values vector given by the user.
     * @param *coins_uses The coin vector that gives the total number of uses of each coin.
     * @param no_coins The total number of coins given by the user.
     *
     * The function prints out the value of each coin and how many uses has.
     *
     */
    int iterator;

    printf ("\n Coins : \n");
    for (iterator = 0; iterator < no_coins; iterator++) {
        printf ("\n coin : %d  uses : %d \n", coins_value[iterator], coins_uses[iterator]);
    }

    printf ("\n\n------------------------\n\n");
}

