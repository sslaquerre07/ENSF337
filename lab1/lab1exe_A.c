/*
 *  File Name: lab1exe_A.c
 *  Assignment: Lab 1 Exercise A
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: Sept 11th,2023
 */

#include <stdio.h>

int main(void){
    int a=0, b=0;
    printf("Please enter a value for variable a:\n");
    scanf("%d", &a);
    printf("Please enter a value for variable b:\n");
    scanf("%d", &b);
    printf("The values of a and b are %d for a and %d for b.\n", a, b);
    printf("The value of a %% b is %d.\n", a%b);
    return 0;
}