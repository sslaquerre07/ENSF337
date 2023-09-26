/* lab3exe_G.c
 * ENSF 337 Lab 3 Exercise  G
 */

#include <stdio.h>

void funct (const char x [8], char y[], int n);

int main()
{
    // It is unusual to intialize a string with '\0' in the middle of string,
    // but it's allowed and we did it delibrately for the educational pruposes.
    const char* sc = "\n\0map";
    
    char sa[5] = {'\0'};
    
    while (*sc) sc++;
    
    sc += 3;
    
    // Point One
    
    funct(sc, sa, &sa[5] - &sa[0]);
    
    return 0;
}

void funct (const char x[8], char y[], int n)
{
    
    while (n ) {
        y[0] = x[0];
        n--;
        x--;
        y++;
    }

    printf("%c", x[3]);
    
    // Point Two
    
}
