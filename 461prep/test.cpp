#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    const char* arr[3];
    arr[0] = "ABC";
    arr[1] = "DEF";
    arr[2] = "GHI";
    cout << *(arr[1] + 1);
}