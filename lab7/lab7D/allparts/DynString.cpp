// DynString.cpp
// ENSF 337 Fall 2023 lab 7 exercise D
//
// completed by:
// lab section:
#include <assert.h>
#include <string.h>
#include "DynString.h"

DynString::DynString()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

DynString::DynString(const char *s)
: lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
}

DynString::~DynString()
{
    delete [] storageM;
}

int DynString::length() const
{
    return lengthM;
}

const char DynString::at(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

const char * DynString::c_str() const
{
    return storageM;
}


void DynString::append(const DynString& tail)
{
    const char* new_str = tail.c_str();
    int tail_len = strlen(new_str);
    int new_len = lengthM + tail_len;
    char* new_array = new char[new_len+1];
    int i = 0;
    while(i<(new_len - tail_len)){
        new_array[i] = storageM[i];
        i++;
    }
    int j = 0;
    while(j<tail_len){
        new_array[i] = new_str[j];
        j++;
        i++;
    }
    new_array[new_len] = '\0';
    delete [] storageM;
    storageM = new_array;
    lengthM = new_len;
}

void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];
    assert(smaller_storage != NULL);
    
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';
    delete [] storageM;
    storageM = smaller_storage;
    lengthM = new_length;
    // Point one
}
