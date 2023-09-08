#include <stdio.h>
#include <math.h>

int factorial(int num){
    int fact = num;
    for(int i = num-1;i>0;i--){
        fact *= i;
    }
    return fact;
}

double taylor_approx(double angle){
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

int main(){
    printf("%lf", taylor_approx(1.57));
}