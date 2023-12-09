#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "SuffixTree.h"

using namespace std;

int main(){
    // Construct a suffix tree containing all suffixes of "bananabanaba$"

    char *str ;
    char str2[] =  "bananabanana";
    str = &str2[0];
    //              0123456789012
    SuffixTree *t= new SuffixTree(str, 12);



    //t.Search("ana"); // Prints: 1 3 7
    //t.Search("naba"); // Prints: 4 8

    // Add test cases here.


//SuffixTree t;

    return 0;
}