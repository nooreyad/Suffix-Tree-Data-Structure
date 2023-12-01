#ifndef SUFFIX_TREE_DATA_STRUCTURE_SINGLELINKEDLIST_H
#define SUFFIX_TREE_DATA_STRUCTURE_SINGLELINKEDLIST_H
#include <iostream>

template<typename T>
struct Node{
    //Data stored in the lined list node
    T item;
    //pointer to point to next
    Node *next;

    //Empty constructor
    //used to initialize data
    Node() {
        item = 0;
        next = nullptr;
    }

    //Parameterized constructor
    //used to initialize data
    Node(T x, Node *nxt) {
        item = x;
        next = nxt;
    }
};


template<typename T>
class SingleLinkedList {
protected:
    Node<T> *head = nullptr, *tail = nullptr;
    int size = 0;
public:
    //this function used to insert node in the linked list
    void insert(T val) {
        // make a new node where its next is NULL
        auto newNode = new Node<T>(val, nullptr);
        if (!head)
            // if the head is null, this node will be head and tail
            head = tail = newNode;
        else
            // make the tails next points to the newNode
            tail->next = newNode;
        tail = newNode;
        size++;
    }
};
#endif //SUFFIX_TREE_DATA_STRUCTURE_SINGLELINKEDLIST_H
