#include <stdio.h>

#define WINDOWS
int main(){
    char s1[20] = "Barlow";
    char s2[] = "Victoria";
    const char* p = "ABC";
    printf("\n%2d %2d %2d %2d %2d", (int)sizeof(s1), (int)sizeof(s2), (int)sizeof(int), (int)sizeof(p), (int)sizeof(*p));


}

