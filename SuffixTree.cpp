//
// Created by Rana Essam on 12/4/2023.
//
#include "SuffixNode.cpp"


class SuffixTree{
    SuffixNode root;
    int len;
    char str[]; // pointer

    explicit SuffixTree( char str [], int len){
        strcpy(this->str, str);
        this->len = len;
    }
    int getIndex(char crnt){
        for (int i = 0; i < len ; ++i) {
            if(crnt == str[i]){
                return i;
            }
        }
        return -1;
    }
    // O^3
    void build(){
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len ; ++j) {

            }
        }
    }



};
