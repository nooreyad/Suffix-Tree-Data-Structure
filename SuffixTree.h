#include "SuffixNode.h"
class SuffixTree{
    SuffixNode* root;
    int len;
    char *str; // pointer

public:
    SuffixTree( char *str , int len){
        this->str = str;
        this->len = len;
        root = new SuffixNode();
        build();
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
            insert(i);
        }
    }
    void insert(int start){

        if(root->suffixes.isEmpty()){
            root->suffixes.insert(new SuffixNode(start, start));
            return;
        }
        root->suffixes.search(start, str, root, len,  start);
    }



};
