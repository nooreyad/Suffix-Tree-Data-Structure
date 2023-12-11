#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "SuffixTree.h"

int main(){
    // Construct a suffix tree containing all suffixes of "bananabanaba$"

    char *str ;
    //              0123456789012
    char str2[] =  "bananabanaba$";


    SuffixTree *t= new SuffixTree(&str2[0], 13);
    t->print();
    t->search("naba", 4);



    //t.Search("ana"); // Prints: 1 3 7
    //t.Search("naba"); // Prints: 4 8

    // Add test cases here.


    return 0;
}