#include "LinkedList.cpp"

#ifndef NODE
#define NODE


struct SuffixNode {
private:
    LinkedList<SuffixNode> list ;
    int startIndex{-1};
    int suffixStartIndex{-1};
    /// this constructor will be used to create the head and tail nodes for the linked list;
public:
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
    SuffixNode()= default;
    /// this function overrides the == operator to check if a node is equal to another
    bool operator== (const SuffixNode &nd) const{
        if (nd.suffixStartIndex == suffixStartIndex && nd.startIndex == startIndex)
            return true;
        return false;
    }
};


#endif //NODE