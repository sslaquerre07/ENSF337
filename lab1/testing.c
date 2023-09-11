
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x = 5, y = -3, z;
    z = (x && y) + x++;
    printf("%d", z);
}
