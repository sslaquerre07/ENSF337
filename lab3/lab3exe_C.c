/*
 *  File Name: lab3exe_C.c
 *  Assignment: Lab 3 Exercise C
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: Sept 27th,2023
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

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);  
    pascal_triangle(nrow);
}



void pascal_triangle(int n) {
    // STUDENTS MUST COMPLETE THE REST OF IMPLEMENATION OF THIS FUNCTION

    //Checks if the input is valid or not
    while((n < 0) || (n > 20)){
        printf("Invalid input, please try again:");
        scanf("%d", &n);
    }

    //Initializes the first two iterations of the array that don't fit into the algortithm
    int init_array[20][21] = {{1}, {1,1}};

    //Used to keep track of current # of elements in the row
    int elem_num;

    //Creates all new rows
    for(int i=2;i<n;i++){
        elem_num = i+1;
        //Checks if the input is already taken care of in the first two rows
        if(n<=2){
            break;
        }
        else{
            init_array[i][0] = 1;
            for(int j=1;j<elem_num-1;j++){
                init_array[i][j] = (init_array[i-1][j-1]) + (init_array[i-1][j]);
            }
            init_array[i][elem_num-1] = 1;
        }
    }

    //Prints out the array
    int elem = 0;
    for(int i = 0;i<n;i++){
        printf("Row #%d: ", i);
        elem = i+1;
        for(int j = 0; j<elem; j++){
            printf("%d ", init_array[i][j]);
        }
        printf("\n");
    }
}






