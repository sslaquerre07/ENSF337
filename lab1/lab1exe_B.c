
/*
 *  File Name: lab1exe_B.c
 *  Assignment: Lab 1 Exercise B
 *  Lab section: 03
 *  Completed by: Sam Laquerre
 *  Submission Date: September 11th,2023
 */

#include <stdio.h>
int main(void)
{
    double num1 = -34.5;
    double num2 = 98.7;
    double sum;          // sum of num1 and num2
    double sumSquared;   // the square of num2 plus num2
    int a = 2, b = 3;
    double avg;
    int celsius, fahrenheit = 110;
    // 1) Add num1 and num2 and store the result in the variable 'sum'
    sum = num1+num2;

    // 2) Compute the square of the sum and store the result in the variable 'sumSquared'
    //    Use the variable 'sum' (computed above) for this computation
    sumSquared = sum*sum;
    printf( "The sum squared is: %f \n", sumSquared);
    
    // 3) Now double the sum squared value and store the result in 'sumSquared'
    sumSquared *= 2;
    printf( "The sum squared is now: %f \n",  sumSquared);
    
    // 4) calculate average of values in a and b store in 'avg'
    avg = (a/b)*2;
    printf("The average a and b is: %f \n", avg);
    
    // In the science textbooks the formulae to convert fahrenheit to celsius is
    // celsius = (fahrenheit - 32) * 5/9
    // for your information 110 (F) is approximately 43.
    // 5) display the value in fahrenheit and its equivallent in celsius. Don't worry
    //    about the fractions in this exercise.
    celsius = (fahrenheit - 32) * 5/9;
    printf("%d in fahrenheit is equal to %d celsius. \n", fahrenheit, celsius);
    return 0;
}
