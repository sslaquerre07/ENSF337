#include <stdio.h>

int is_fibonacci_sequence(const int* x, int n){
    if (n<2) return 0;
    if(x[0] != 0 || x[1] != 1) return 0;
    for(int i=2;i<n;i++){
        if(x[i] == (x[i-1]+x[i-2])){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    int possible_fib[] = {0,1,1,2,3,4};
    printf("%d", is_fibonacci_sequence(possible_fib, 1));
}

