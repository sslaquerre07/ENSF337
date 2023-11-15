#include <iostream>
using namespace std;

int Search(int key, const int* array, int low, int high);

int main(){
    int array[] = {1,2,3,4,5};
    cout << Search(6, array, 0, 4);

}

int Search(int key, const int* array, int low, int high){
    if(low>high)
        return -1;
    else{
        if(array[low]==key)
            return low;
        else
            Search(key, array, low+1, high);    
    }
}