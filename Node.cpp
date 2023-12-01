#include "LinkedList.cpp"

#ifndef NODE
#define NODE

struct node {
    LinkedList list;
    int startIndex;
    int suffixStartIndex;
    node * next;
    /// this constructor will be used to create the head and tail nodes for the linked list;
    node()
    {
        next = nullptr;
        startIndex = -1;
        suffixStartIndex = -1;
    }
    /// this constructor will be used to create leaf nodes of the suffix
    node(int startIndex, int suffixStartIndex)
    {
        next = nullptr;
        this->suffixStartIndex = suffixStartIndex;
        this->startIndex = startIndex;
    }
    /// this constructor will be used to create internal node of the suffix
    explicit node(int startIndex)
    {
        next = nullptr;
        this->startIndex = startIndex;
        suffixStartIndex = -1;
    }
    /// this function overrides the == operator to check if a node is equal to another
    bool operator== (const node &nd) const{
        if (nd.suffixStartIndex == suffixStartIndex && nd.startIndex == startIndex)
            return true;
        return false;
    }
};


#endif //NODE