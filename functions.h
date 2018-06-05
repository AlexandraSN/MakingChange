/**
 * @file functions.h
 * @brief C library containing the functions used by the program
 */
#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

void decreasing_ordering(int *coins_value, int no_coins);
void making_change(int *coins_value, int *coins_uses, int no_coins, int sum);
void print_coins(int *coins_value, int *coins_uses, int no_coins);

#endif // MAIN_FUNCTIONS_H

