/*
 *  File Name: lab3exe_D.c
 *  Assignment: Lab 3 Exercise D
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: Sept 27th,2023
 */

#include <stdio.h>
#include <string.h>

int substring(const char *string, const char *sub);
/* REQUIRES
 * string and sub are valid C-string terminated with '\0';
 * PROMISES
 * returns one if sub is a substring of string). Otherwise returns zero.
 */

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives);
/* REQUIRES
 *   n_source >= 0.
 *   Elements source[0], source[1], ..., source[n_source - 1] exist.
 *   Elements negatives_only[0], negatives_only[1], ..., negatives_only[n_source - 1] exist.
 * PROMISES
 *   number_of_negatives == number of negative values in source[0], ..., source[n_source - 1].
 *   negatives_only[0], ..., negatives_only[number_of_negatives - 1] contain those negative values, in
 *   the same order as in the source array.                           */

int main(void)
{
    char s[] = "Knock knock! Who's there?";
    int a[] = { -11, 90, -11, 5, -22 };
    int size_a;
    int i;
    int negative[5];
    int n_negative;
    
    size_a = sizeof(a) / sizeof(a[0]);
    
    printf("a has %d elements:", size_a);
    for (i = 0; i < size_a; i++)
        printf("  %d", a[i]);
    printf("\n");
    select_negatives(a, size_a, negative, &n_negative);
    printf("\nnegative elements from array a are as follows:");
    for (i = 0; i < n_negative; i++)
        printf("  %d", negative[i]);
    printf("\n");
    
    printf("\nNow testing substring function....\n");
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "Who"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "knowk"));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "knock"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, ""));
    printf("Answer must be 1. substring function returned: %d\n" , substring(s, "ck! Who's"));
    printf("Answer must be 0. substring function returned: %d\n" , substring(s, "ck!Who's"));
    return 0;
}

int substring(const char *string, const char* sub)
{
    //Used to check whether there is a potential match or not
    int match = 0;

    //Letter Check
    for(int i = 0;i<strlen(string);i++){
        if(string[i] == sub[0]){
            match = 1;
            for(int j = 1;j<strlen(sub);j++){
                if(string[i+1] == sub[j]){
                    i++;
                    continue;
                }
                else{
                    match = 0;
                    break;
                }
            }
            if(match == 1){
                return 1;
            }
            else{
                continue;
            }    
        }
        else{
            continue;
        }
    }
    return 0;
}

void select_negatives(const int *source, int n_source,
                      int* negatives_only, int* number_of_negatives)
{
    int i;
    *number_of_negatives = 0;
    for(i=0;i<n_source;i++){
        if (source[i] < 0){
            negatives_only[*number_of_negatives] = source[i];
            *number_of_negatives += 1;
        }
    }
    
    return;
}

