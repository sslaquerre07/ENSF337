#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

int is_palindrome (const char *str);
void strip_out(char *str);


int main(){
    char str[100] = "Madam I'm Adam";
    strip_out(str);
    printf("%d", is_palindrome(str));
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

