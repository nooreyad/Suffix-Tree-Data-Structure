#include <iostream>
#include <cstring>

class SuffixNode {
public:

    int startIndex = -1; // the start index of the substring that the edge has (the index of the first letter of the substring)
    int suffixStartIndex = -1; // the id of the suffix which will -1 if the node is internal node and will be the index of the suffix if the node is leaf

    // This class represents a node in the linked list
    class Node {
    public:
        SuffixNode *data; // the data of the node
        Node *next; // pointer to the next node

        Node(SuffixNode *data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
    };

    // This class represents a linked list of nodes which will be used to store the suffix node of the tree
    class LinkedList {
    public:
        Node *head; // pointer to the head of the list
        Node *tail; // pointer to the tail of the list
        int size = 0; // the size of the list

        // constructor to initialize the list with null pointers
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        // this function inserts a new node in the list
        void insert(SuffixNode *data)
        {
            size++; // increment the size of the list
            Node *newNode = new Node(data, nullptr);
            if (head == nullptr)
            {
                head = tail = newNode; // if the list is empty, the new node will be the head and the tail
            }
            else
            {
                tail->next = newNode; // if the list isn't empty, the new node will be the next of the tail
                tail = newNode;
            }
        }


        // this function searches for a substring that matches the new suffix and insert it in the right place
        void searchToBuild(int index, const char *str, SuffixNode *prev, int len, int temp)
        {
            Node *current = head; // pointer to the head of the list to loop on it to search for the substring that matches the new suffix
            int sz = -1; // the size of the substring that the edge has


            for (int i = 0; i < size; i++) // loop on all the suffixes that the node has
            {
                // if the node is found, return it
                if (str[current->data->startIndex] == str[index]) // if the first letter of the suffix is the same as the first letter of the new suffix
                {
                    // this if statement to get the size of the substring that the edge has
                    if (current->data->suffixStartIndex != -1)
                    {
                        // and if the node is leaf, the size is the length of the string - the start index of the suffix
                        sz = len - current->data->startIndex;
                    }
                    else
                    {
                        // else the size = minStartOfChildren  - the start index of the suffix
                        int minStart = current->data->suffixes.getMinNode();
                        sz = minStart - current->data->startIndex;
                    }

                    int j; // index to loop on the substring of the edge to check if it matches the new suffix or not

                    // this for loop to check if the substring matches the new suffix

                    for (j = current->data->startIndex; j < sz + current->data->startIndex; ++j)
                    {

                        // if the current index doesn't match the new suffix then here we will split the node
                        if (str[j] != str[index++])
                        {
                            index--; // decrement the index to be the same as the index of the first letter of the new suffix that doesn't match the substring of the edge
                            // sava the id of the suffix of the current node to be used in one of the new nodes
                            int id = current->data->suffixStartIndex;

                            // the current node will be internal node if it was a leaf or stay as it is if it was internal so the suffixStartIndex will be -1 at all cases
                            current->data->suffixStartIndex = -1;

                            // the first new node which will include the rest of the new suffix
                            auto *newNode = new SuffixNode(index, temp);

                            // the second new node which will include the rest of the suffix of the current node before splitting
                            auto *newNode2 = new SuffixNode(j, id);
                            newNode2->suffixes = current->data->suffixes;
                            current->data->suffixes = LinkedList();

                            // inserting the new nodes in the list of the current node
                            current->data->suffixes.insert(newNode2);
                            current->data->suffixes.insert(newNode);
                            return ;
                        }
                    }

                    // if the all the substring of the current node matches the new suffix, so we will complete searching in its children
                    current->data->suffixes.searchToBuild(index, str, current->data, len, temp);
                    return ;

                }
                current = current->next;
            }



            // if the start of the new suffix doesn't match any of the suffixes of the current node, so we will add a new node to the list of the current node
            prev->suffixes.insert(new SuffixNode(index, temp));

        }

        // this function returns the minimum start index of the children of the current node
        int getMinNode()
        {
            int mn = 1e6;
            Node *c = head;
            for (int i = 0; i < size; i++)
            {
                if (mn > c->data->startIndex)
                {
                    mn = c->data->startIndex;
                }
                c = c->next;
            }
            return mn;
        }

        // this function used to print the suffix start index of all the leaves below
        void printLeafNodes()
        {
            Node *current = head;
            //loop over the linked list of the current
            for (int i = 0; i < size; i++)
            {
                //if leaf print
                if (current->data->suffixStartIndex != -1)
                {
                    std::cout << current->data->suffixStartIndex << " ";
                }
                else //else recursively call the function on the linked list of the current
                {
                    current->data->suffixes.printLeafNodes();
                }
                current = current->next;
            }

        }

        // this function searches for a substring that matches the new suffix and print the suffix start index of all the leaves below
        void searchFor(int index, const char *str, int subLen, int len, int temp, char *searchString)
        {
            Node *current = head; // pointer to the head of the list to loop on it to search for the substring that matches the new suffix
            int sz = -1;
            for (int i = 0; i < size; i++) // loop on all the suffixes that the node has
            {
                // if the node is found, return it
                if (searchString[current->data->startIndex] ==
                    str[index]) { // if the first letter of the suffix is the same as the first letter of the new suffix
                    // this if statement to get the size of the substring that the edge has
                    if (current->data->suffixStartIndex != -1)
                    {
                        // and if the node is leaf, the size is the length of the string - the start index of the suffix
                        sz = len - current->data->startIndex;
                    }
                    else
                    {
                        // else the size = minStartOfChildren  - the start index of the suffix
                        int minStart = current->data->suffixes.getMinNode();
                        sz = minStart - current->data->startIndex;
                    }
                    // this for loop to check if the substring matches the new suffix
                    int j;
                    for (j = current->data->startIndex; j < sz + current->data->startIndex; ++j, index++)
                    {
                        // if the current index doesn't match the new suffix then here we will split the node
                        if (searchString[j] != str[index] && index == subLen)
                        {
                            //if the current was a leaf it should be printed
                            if (current->data->suffixStartIndex != -1)
                            {
                                std::cout << current->data->suffixStartIndex << " ";
                            }
                            else
                            {
                                current->data->suffixes.printLeafNodes();
                            }
                            return ;
                        }
                            //we didn't get to the end of the substring, and we found char doesn't match
                        else if (searchString[j] != str[index] && index < subLen)
                        {
                            std::cout << "NOT FOUND!";
                            return ;
                        }
                    }
                    // if we got to the end of the substring, and we just ended the edge
                    if (index == subLen)
                    {
                        //if the current was a leaf
                        if (current->data->suffixStartIndex != -1)
                        {
                            std::cout << current->data->suffixStartIndex << " ";
                        }
                        else
                        {
                            current->data->suffixes.printLeafNodes();
                        }
                        return ;
                    }
                    //recursively search in the linked list of the current
                    return current->data->suffixes.searchFor(index, str, subLen, len, temp, searchString);
                }
                //go to next child if current doesn't match
                current = current->next;
            }

            std::cout << "NOT FOUND!" ;

        }
    };


    // this list contains all the suffixes of the current node
    LinkedList suffixes;

    SuffixNode(int startIndex, int suffixStartIndex)
    {
        this->startIndex = startIndex;
        this->suffixStartIndex = suffixStartIndex;
    }

    SuffixNode() = default;
};


class SuffixTree{
    SuffixNode *root; // the root of the tree (the first Suffix node)
    int len; // the length of the string
    char *str; // pointer to the string


public:
    SuffixTree(char *str)
    {
        this->str = str;
        this->len = strlen(str); // get the length of the string
        root = new SuffixNode(); // create the root node
        build(); // build the tree by adding all the suffixes to the tree and adding the suffixes of the suffixes  in O(n^2)
    }


    // O(n^2) time complexity and O(n) space complexity
    void build() // this function builds the tree by adding all the suffixes to the tree and adding the suffixes of the suffixes
    {
        for (int i = 0; i < len; ++i)
        {
            root->suffixes.searchToBuild(i, str, root, len, i); // search for suitable place to add the suffix
        }
    }

    // O(n) time complexity which n is the length of the substring which is being searched for
    void search(char *s) // this function acts as an interface for the search function in the linked list class
    {
        size_t sz = strlen(s);

        root->suffixes.searchFor(0, s, sz, len, 0, str);
        std::cout << std::endl;
    }


};


int main()
{
    // Construct a suffix tree containing all suffixes of "bananabanaba$"

    //            0123456789012
    SuffixTree t ("bananabanaba$");



    // const_cast<char*>("bananabanaba$") is a hack to convert a string literal to a char*
    
    std::cout << "bananabanaba$\n";
    t.search("ana"); // Prints: 1 3 7
    t.search("naba"); // Prints: 4 8
    t.search(("bananabanaba")); // Prints: 0
    t.search("a"); // Prints: 1 3 5 7 9 11
    t.search("ba"); // Prints: 0 6 10
    t.search("ana"); // Prints: 1 3 7
    t.search("naba"); // Prints: 4 8
    t.search("ban"); // Prints: 0 6
    t.search("anaba"); // Prints: 7 3
    t.search("banan"); // Prints: 0
    t.search("bananabanab"); // 0
    t.search("bananabanabaa"); // Prints: NOT FOUND!

                      //01234567890123456789012
    SuffixTree t2 ("abracadabraabracadabra$");
    std::cout << "abracadabraabracadabra$\n";
    t2.search("abra"); // Prints: 0 11 7 18
    t2.search("cadabra"); // Prints: 4 15
    t2.search("abracadabra"); // Prints: 0 11
    t2.search("abracadabraabra"); // Prints: 0
    t2.search("bra"); // Prints: 1 8 15
    t2.search("bracadabra$"); // Prints: 12
    t2.search("$");

    return 0;
}
