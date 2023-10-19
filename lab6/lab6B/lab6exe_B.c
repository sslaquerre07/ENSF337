// ENSF 337 - lab 6 - exercise b
// M. Moussavi
// lab5exe_B.c

#include <stdio.h>
#include <stdlib.h>
#include "lab6exe_B.h"

int main(void) {
    char input_filename[30] = "lab6exe_B.txt";
    char output_filename[30]= "lab6exe_B_output.txt";
    IntVector intVec;
    intVec.number_of_data = 0;
    
    read_text_file(&intVec, input_filename);
    
    display_single_column(&intVec);
    
    display_multiple_column(&intVec, 4, output_filename);

    return 0;
}

void read_text_file (IntVector* vec, const char* input_filename){
    int nscan;
    FILE *fp = fopen (input_filename, "r");
    
    if(fp == NULL){
        fprintf(stdout, "Sorry cannot open the text file %s.\n", input_filename);
        exit(1);
    }
    
    do{
        nscan = fscanf(fp,"%d", &vec->storage[vec->number_of_data]);
        if(nscan == 1)
            (vec->number_of_data)++;
        else if (nscan != EOF){
            fprintf(stderr, "Invalid data in %s.\n", input_filename);
            exit(1);
        }
    }while ((nscan != EOF) & (vec->number_of_data < MAX_CAPACITY));
    
    fclose(fp);
}

void display_single_column(const IntVector* intV){
    int i;
    for (i = 0; i < intV ->number_of_data; i++ )
        printf("%10d\n", intV ->storage[i]);
}

void display_multiple_column(const IntVector *intV, int col, const char* output_filename)
{
    FILE *fp1 = fopen(output_filename, "wt");
    int data_num = intV->number_of_data;
    int rows;
    if(data_num % col != 0){
        rows = data_num/col + 1;
    }
    else{
        rows = data_num/col;
    }

    for(int row = 0; row<rows;row++){
        for(int line = 0;line<col;line++){
            int pos = (row*col+line);
            printf("%d ", intV->storage[pos]);
        }
        printf("\n");
    }
}

