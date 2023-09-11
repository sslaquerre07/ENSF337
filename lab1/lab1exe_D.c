/*
 *  File Name: lab1exe_D.c
 *  Assignment: Lab 1 Exercise D
 *  Lab section: 03
 *  Completed by: Sam Laquerre
 *  Submission Date: September 11th,2023
 */


#include <stdio.h>
#include <math.h>

int factorial(int num){
    /*Calculates the factorial of any number*/
    int fact = num;
    for(int i = num-1;i>0;i--){
        fact *= i;
    }
    return fact;
}

double taylor_approx(double angle){
    /*Does the taylor approximation of up to the power of 7*/
    double approx = angle;
    int sign_check = 0;
    for(double i=3;i<=7;i+=2){
        if(sign_check){
            approx += (pow(angle, i)/factorial(i));
            sign_check = 0;
        }
        else{
            approx -= (pow(angle, i)/factorial(i));
            sign_check = 1;
        }
    }
    return approx;
}

int main()
{
    double angle;
    printf("Please enter the desired angle in radians for both sine functions:");
    scanf("%lf", &angle);
    double sin_func = sin(angle);
    double sin_approx = taylor_approx(angle);
    printf("The exact value is: %lf\nThe approximate value is: %lf\n", sin_func, sin_approx);
    return 0;
}