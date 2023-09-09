#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex complex_calc(int a, int b, int c){
    double initial_num = (pow(b,2)-4*a*c);
    double complex num;
    initial_num = sqrt(initial_num*-1);
    num = initial_num * I;    
    return num;
}

int main()
{
  printf("%+.1fi", cimag(complex_calc(1,2,2)));

}