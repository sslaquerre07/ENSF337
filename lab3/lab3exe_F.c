// lab3exe_F.c

// ENSF 337 Lab 3 Exercise F

#include <stdio.h>

int main(void)
{
    int i;
    int a[ ] = { 1000, 1200, 300, 1400, 1500, 30 };
    int *z;
    
    *a = 99;
    *(a + 2) = 55;
    a[1] = 11;
    
    z = a + 2;
    
    i = 2;
    
    *(z-1) = *(z-i) + z[0];
    z[1] = *z * i;
    *(z+2) = *(&a[2] - i);
    z = z+3;
    z[3] = -9;
    
    i = a - &a[6];
    printf("%d", z[3]);
    // point one
    
    return 0;
}

