#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <iomanip>

int main(){
    string s1("Hello World");
    double a1 = 3.147367457736;
    s1.push_back('!');
    cout << s1 << endl;
    cout << setiosflags(ios::scientific) << setprecision(2) << a1 << endl;
    cout << setw(20) << s1 << setw(20) << a1;
}