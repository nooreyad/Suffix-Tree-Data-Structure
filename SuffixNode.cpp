#include "LinkedList.cpp"

#ifndef NODE
#define NODE

struct SuffixNode {
    LinkedList list = *new LinkedList();
    int startIndex;
    int suffixStartIndex;
    /// this constructor will be used to create the head and tail nodes for the linked list;
    SuffixNode()
    {
        startIndex = -1;
        suffixStartIndex = -1;
    }
    /// this constructor will be used to create leaf nodes of the suffix
    SuffixNode(int startIndex, int suffixStartIndex)
    {
        this->suffixStartIndex = suffixStartIndex;
        this->startIndex = startIndex;
    }
    /// this constructor will be used to create internal node of the suffix
    explicit SuffixNode(int startIndex)
    {
        this->startIndex = startIndex;
        suffixStartIndex = -1;
    }
    /// this function overrides the == operator to check if a node is equal to another
    bool operator== (const SuffixNode &nd) const{
        if (nd.suffixStartIndex == suffixStartIndex && nd.startIndex == startIndex)
            return true;
        return false;
    }
};


#endif //NODE