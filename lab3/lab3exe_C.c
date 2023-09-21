/*
 *  lab3exe_C.c
 *  ENSF 337, lab3 Exercise C
 *
 *  In this program the implementatiom of function pascal_trangle is missing.
 *  Studtent must complete this function.
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

void print_triangle(int **array[][21], int *rows);

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);  
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
    // STUDENTS MUST COMPLETE THE REST OF IMPLEMENATION OF THIS FUNCTION

    while((n < 0) || (n > 20)){
        printf("Invalid input, please try again:");
        scanf("%d", &n);
    }
    int init_array[20][21] = {{1}, {1,1}};
    print_triangle(init_array[0][0], &n);
}

void print_triangle(int **array[][21], int *rows){
    int elem = 0;
    for(int i = 0;i<=*rows;i++){
        printf("Row #%d: ", i);
        elem = i+1;
        for(int j = 0; j<elem; j++){
            printf("%d ", *array);
        }
        printf("\n");
    }
}






