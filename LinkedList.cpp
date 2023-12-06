#include <iostream>

using namespace std;

#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
struct Node{
    /// Data stored in the lined list SuffixNode
    T item;
    /// pointer to point to next
    Node *next;
    /// Empty constructor used to initialize data
    Node()
    {
        next = nullptr;
    }
    /// Parameterized constructor used to initialize data
    Node(T x, Node *nxt)
    {
        item = x;
        next = nxt;
    }
};

template<class T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size = 0;
public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    /// this function checks if a list is empty
    bool isEmpty() const { return size == 0; }
    /// this function searches for a node in the list
    Node<T>* search(T info)
    {
        Node<T>* current = head;
        for (int i = 0; i < size; i++)
        {
            // if the node is found, return it
            if (current->item == info) return current;
            current = current->next;
        }
        // if the whole list is searched and the node isn't found,
        // return null pointer
        return nullptr;
    }
    /// this function removes a node from a list
    void remove(T info)
    {
        // if the node is the head of the list
        if (info == head->item)
        {
            Node<T>* temp = head;
            head = head->next; // let the next of the head be the new head
            free(temp);
        }
        // if the node is the tail
        else if (info == tail->item){
            Node<T>* current = head;
            while (current->next != tail) // loop on the list until the tail is the next to the current node
                current = current->next;
            Node<T>* temp = current->next; // temp is pointing to the tail
            current->next = nullptr; // make the node before the tail point to node
            tail = current; // let the node before the tail be the new tail
            free(temp);
        }
        // if the node is neither the head nor the tail (could be found or not)
        else{
            Node<T>* current = head;
            while (current->next->item != info){ // loop on the list until the node to be removed is next
                current = current->next;
                // if the loop has come to an end and the node isn't yet found, let the user know it doesn't exist
                if(current == tail)
                {
                    cout << "This node does not exist" << "\n";
                    return;
                }
            }
            // if found
            Node<T>* temp = current->next; //
            current->next = temp->next;
            free(temp);
        }
        size--;
    }
    /// this function used to insert SuffixNode in the linked list
    void insert(T val) {
        // make a new SuffixNode where its next is NULL
        auto newNode = new Node<T>(val, nullptr);
        if (!head)
            // if the head is null, this SuffixNode will be head and tail
            head = tail = newNode;
        else
            // make the tails next points to the newNode
            tail->next = newNode;
        tail = newNode;
        size++;
    }

};

#endif //LINKED_LIST