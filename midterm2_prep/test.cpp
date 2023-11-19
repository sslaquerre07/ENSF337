#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <iomanip>



int main(){
    const char* s = "ON TIME";
    const char ** m = &s;
    cout << *(*m+1);
}

