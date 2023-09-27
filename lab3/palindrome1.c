/*
 *  File Name: lab3exe_E.c
 *  Assignment: Lab 3 Exercise E
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: Sept 27th,2023
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


/* function prototypes*/
int is_palindrome (const char *str);
/* REQUIRES: str is pointer to a valid C string.
 * PROMISES: the return value is 1 if the string a is palindrome.*/


void strip_out(char *str);
/* REQUIRES: str points to a valid C string terminated with '\0'.
 * PROMISES: strips out any non-alphanumerical characters in str*/

int main(void)
{
    int p =0;
    char str[SIZE], temp[SIZE];
    /*Opens and reads the file*/
    FILE *fp;
    fp = fopen("palindrome.txt", "r");
    fgets(str, SIZE,fp);
    
    /* Remove end-of-line character if there is one in str.*/
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    strcpy(temp,str);
    /* This loop is infinite if the string "done" never appears in the
     * input.  That's a bit dangerous, but OK in a test harness where
     * the programmer is controlling the input. */
    
    while(strcmp(str, "done") !=0) /* Keep looping unless str matches "done". */
    {
        strip_out(str);
        p = is_palindrome(str);
        if(!p)
            printf("\n \"%s\" is not a palindrome.", temp);
        else
            printf("\n \"%s\" is a palindrome.", temp);
        
        fgets(str, SIZE, fp);
        
        /* Remove end-of-line character if there is one in str.*/
        if(str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1]= '\0';
        strcpy(temp, str);
    }
    fclose(fp);
    return 0;
}



int is_palindrome (const char *str){
    //Makes another pointer that points to the end of the string
    const char *end_str = &str[strlen(str)-1];
    for(int i =0; i<strlen(str);i++){
        //Checks front and back of word at the same time
        if(str[i] == end_str[-i]){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}


void strip_out(char *str){
    for(int i =0;str[i] != '\0';i++){
        //Checks if a character is alphanumeric
        if(isalnum(str[i])){
            //True
            str[i] = tolower(str[i]);
            continue;
        }
        else{
            //False
            int j;
            for(j = i;str[j] != '\0';j++){
                //Moves each character up a space, essentially deleting the character
                str[j] = str[j+1];
            }
            //Moves index back one since deleting the character shifted every index.
            i--;
        }
    }
}





