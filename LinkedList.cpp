#include <iostream>
#include "Node.cpp"
using namespace std;

#ifndef LINKED_LIST
#define LINKED_LIST

class LinkedList{
private:
private:
    node* head;
    node* tail;
    int size = 0;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    /// this function checks if a list is empty
    bool isEmpty() const { return size == 0; }
    /// this function searches for a node in the list
    node* search(node nd)
    {
        node* current = head;
        for (int i = 0; i < size; i++)
        {
            // if the node is found, return it
            if (current == &nd) return current;
            current = current->next;
        }
        // if the whole list is searched and the node isn't found,
        // return null pointer
        return nullptr;
    }
    /// this function removes a node from a list
    void remove(node* nd)
    {
        // if the node is the head of the list
        if (nd == head)
        {
            node* temp = head;
            head = head->next; // let the next of the head be the new head
            free(temp);
        }
        // if the node is the tail
        else if (nd == tail){
            node* current = head;
            while (current->next != tail) // loop on the list until the tail is the next to the current node
                current = current->next;
            node* temp = current->next; // temp is pointing to the tail
            current->next = nullptr; // make the node before the tail point to node
            tail = current; // let the node before the tail be the new tail
            free(temp);
        }
        // if the node is neither the head nor the tail (could be found or not)
        else{
            node* current = head;
            while (current->next != nd){ // loop on the list until the node to be removed is next
                current = current->next;
                // if the loop has come to an end and the node isn't yet found, let the user know it doesn't exist
                if(current == tail)
                {
                    cout << "This node does not exist" << "\n";
                    return;
                }
            }
            // if found
            node* temp = current->next; //
            current->next = temp->next;
            free(temp);
        }
        size--;
    }

};

#endif //LINKED_LIST