#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex complex_calc(double complex imag_num){
    imag_num = sqrt(imag_num*-1);
    double complex num = imag_num * I;    
    return num;
}

void complex_add(double complex imaginary, double real){
    double complex pos_case = (real+imaginary);
    double complex neg_case = (real-imaginary);
    printf("Your two factors are %.1f%+.1fi and %.1f%+.1fi\n", creal(pos_case), cimag(pos_case), creal(neg_case), cimag(neg_case));
    return;
}

void regular_add(double real1, double real2){
    double pos_case = (real1+real2) * -1;
    double neg_case = (real1-real2) * -1;
    printf("Your two factors are %.1f and %.1f\n", creal(pos_case), creal(neg_case));
    return;
}

int main(){
    int a, b, c;
    printf("For the your quadratic formula, enter the three coefficients in the format a,b,c for the quadratic ax^2+bx+c\n");
    scanf("%d,%d,%d", &a, &b, &c);
    double num1 = (b*-1)/(2*a);
    double initial_num = (pow(b,2)-4*a*c);
    double complex num2;
    double num3;
    if(initial_num<0){
        num2 = (complex_calc(initial_num)/(2*a));
        complex_add(num2, num1);
    }
    else{
        num3 = sqrt(initial_num)/(2*a);
        regular_add(num1, num3);
    }
    return 0;
}