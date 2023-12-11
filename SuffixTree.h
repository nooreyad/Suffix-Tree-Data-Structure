#include "SuffixNode.h"

class SuffixTree {
    SuffixNode *root;
    int len;
    char *str; // pointer

    void print(SuffixNode *current , SuffixNode *prev ) {
        int ln = current->suffixStartIndex == -1 ?  current->suffixes.getMinNode()- current->startIndex : len-
                                                                                                          current->startIndex;
        char *edgeStr = new char[ln + 1];
        if (current != root) {
            strncpy(edgeStr, str + current->startIndex, ln);
            edgeStr[ln] = '\0';
            std::cout << "[" << current->startIndex << ", " << ln << ", " << current->suffixStartIndex << "] parent("
                      << prev->startIndex << ") -> " << edgeStr << std::endl;
        }

        SuffixNode *curChild;
        for (int i = 0; i < current->suffixes.getSize(); i++) {
            curChild = current->suffixes.get(i);
            if (!curChild) return;
            print(curChild, current);
        }

        /*
         * nput:
banana$

output:
[6, 1, 6] parent(-1) -> $ //
[2, 2, -1] parent(-1) -> na //
[6, 1, 4] parent(2) -> $ //
[4, 3, 2] parent(2) -> na$ //
[1, 1, -1] parent(-1) -> a //
[6, 1, 5] parent(1) -> $ //
[2, 2, -1] parent(1) -> na //
[6, 1, 3] parent(2) -> $ //
[4, 3, 1] parent(2) -> na$ //
[0, 7, 0] parent(-1->)banana$*/


    }



public:
    SuffixTree(char *str, int len) {
        this->str = str;
        this->len = len;
        root = new SuffixNode();
        build();
    }

    int getIndex(char crnt) {
        for (int i = 0; i < len; ++i) {
            if (crnt == str[i]) {
                return i;
            }
        }
        return -1;
    }

    // O^3
    void build() {
        for (int i = 0; i < len; ++i) {
            root->suffixes.searchToBuild(i, str, root, len, i);
        }
    }

    void search(char *s, int sz){
        root->suffixes.searchFor(0, s, sz,len, 0, str);
    }

    void print(){
        print(root, root);
    }



};
