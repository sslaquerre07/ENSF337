// ENSF 337 Fall 2023 - Lab 8 - exercise A
// lab8ExA.cpp

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main() {
    
    const int ROWS = 5;
    const int COLS = 4;
    
    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);
    
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }
    
    
    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }
    
    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;
    
    return 0;
}



String_Vector transpose (const String_Vector& sv) {
    String_Vector vs;
    vs.resize(sv.at(0).length());
    for(int i=0; i<vs.size();i++){
        for(int j=0; j<sv.size();j++){
            vs.at(i).push_back(sv.at(j).at(i));
        }
    }
    return vs;   
}
