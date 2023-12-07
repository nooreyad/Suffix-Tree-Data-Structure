#include "SuffixNode.h"
class SuffixTree{
    SuffixNode* root;
    int len;
    char str[]; // pointer

    explicit SuffixTree( char str [], int len){
        strcpy(this->str, str);
        this->len = len;
        root = new SuffixNode();
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
        strcat(str, "$");
        len++;
        for (int i = 0; i < len; ++i) {
        }
    }
    void insert(int start){

        if(root->suffixes){
            root->list.insert(start, start);
            return;
        }

        if(root->list.)



    }


};
