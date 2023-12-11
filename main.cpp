#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>



class SuffixNode {
public:

    int startIndex = -1;
    int suffixStartIndex = -1;

    class Node {
    public:
        SuffixNode *data;
        Node *next;

        Node(SuffixNode *data, Node *next) {
            this->data = data;
            this->next = next;
        }
    };

    class LinkedList {
    public:
        Node *head;
        Node *tail;
        int size = 0;

        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        /// this function inserts a new node in the list
        void insert(SuffixNode *data)
        {
            size++;
            Node *newNode = new Node(data, nullptr);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }


        /// this function searches for a substring that matches the new suffix and insert it in the right place
        SuffixNode *searchToBuild(int index, const char *str, SuffixNode *prev, int len, int temp)
        {
            Node *current = head;
            int sz = -1;


            for (int i = 0; i < size; i++) // loop on all the suffixes that the node has
            {
                // if the node is found, return it
                if (str[current->data->startIndex] == str[index]) { // if the first letter of the suffix is the same as the first letter of the new suffix
                    // this if statement to get the size of the substring that the edge has
                    if (current->data->suffixStartIndex != -1) {

                        // and if the node is leaf, the size is the length of the string - the start index of the suffix
                        sz = len - current->data->startIndex;
                    } else {

                        // else the size = minStartOfChildren  - the start index of the suffix
                        int minStart = current->data->suffixes.getMinNode();
                        sz = minStart - current->data->startIndex;
                    }

                    // this for loop to check if the substring matches the new suffix
                    int j;


                    for (j = current->data->startIndex; j < sz + current->data->startIndex; ++j)
                    {

                        // if the current index doesn't match the new suffix then here we will split the node
                        if (str[j] != str[index++]) {
                            index--;
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
                            return prev;
                        }
                    }
//
                    // if the all the substring of the current node matches the new suffix, so we will complete searching in its children
                    return current->data->suffixes.searchToBuild(index, str, current->data, len, temp);

                }
                current = current->next;
            }

//

            // if the start of the new suffix doesn't match any of the suffixes of the current node, so we will add a new node to the list of the current node
            prev->suffixes.insert(new SuffixNode(index, temp));
            // if the whole list is searched and the node isn't found,
            // return null pointer
            return nullptr;
        }

        /// this function returns the minimum start index of the children of the current node
        int getMinNode()
        {
            int mn = 1e6;
            Node *c = head;
            for (int i = 0; i < size; i++) {
                if (mn > c->data->startIndex) {
                    mn = c->data->startIndex;
                }
                c = c->next;
            }
            return mn;
        }

        void printLeafNodes()
        {
            Node *current = head;
            for (int i = 0; i < size; i++)
            {
                if (current->data->suffixStartIndex != -1)
                {
                    std::cout << current->data->suffixStartIndex << " ";
                }
                else
                {
                    current->data->suffixes.printLeafNodes();
                }
                current = current->next;
            }

        }

        SuffixNode *searchFor(int index, const char *str,int subLen , int len, int temp, char *searchString) {
            Node *current = head;
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
                    } else
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
                            if(current->data->suffixStartIndex != -1)
                            {
                                std::cout << current->data->suffixStartIndex << " ";
                            }
                            else
                            {
                                current->data->suffixes.printLeafNodes();
                            }
                            return nullptr;
                        } else if (searchString[j] != str[index] && index < subLen)
                        {
                            std::cout << "NOT FOUND! \a" << std::endl;
                            return nullptr;
                        }
                    }
                    if (index == subLen)
                    {
                        if(current->data->suffixStartIndex != -1)
                        {
                            std::cout << current->data->suffixStartIndex << " ";
                        }
                        else
                        {
                            current->data->suffixes.printLeafNodes();
                        }
                        return nullptr;
                    }
                    return current->data->suffixes.searchFor(index, str,subLen, len, temp, searchString);
                }
                current = current->next;
            }

            std::cout << "NOT FOUND! \a" << '\n';
            return nullptr;
        }
    };


    /// this list contains all the suffixes of the current node
    LinkedList suffixes;

    SuffixNode(int startIndex, int suffixStartIndex)
    {
        this->startIndex = startIndex;
        this->suffixStartIndex = suffixStartIndex;
    }

    SuffixNode() = default;
};


class SuffixTree {
    SuffixNode *root; // the root of the tree (the first node)
    int len; // the length of the string
    char *str; // pointer to the string


public:
    SuffixTree(char *str, int len) {
        this->str = str;
        this->len = len;
        root = new SuffixNode(); // create the root node
        build(); // build the tree by adding all the suffixes to the tree and adding the suffixes of the suffixes  in O(n^2)
    }


    // O(n^2) time complexity and O(n) space complexity
    void build() {
        for (int i = 0; i < len; ++i) {
            root->suffixes.searchToBuild(i, str, root, len, i);
        }
    }

    // O(n) time complexity which n is the length of the substring which is being searched for
    void search(char *s){
        size_t sz = strlen(s);
        root->suffixes.searchFor(0, s, sz,len, 0, str);
        std::cout<< std::endl;
    }


};






int main(){
    // Construct a suffix tree containing all suffixes of "bananabanaba$"


    //              0123456789012
    char *str =  "bananabanaba$";


    SuffixTree *t= new SuffixTree(str, 13);
//    t->print();
  char *subStr [] = {"bananabanaba$", "ananabanaba$", "nanabanaba$", "anabanaba$",
                         "nabanaba$", "abanaba$", "banaba$", "anaba$", "naba$", "aba$",
                         "ba$", "a$", "$", "ba", "bana", "banan", "banana", "bananab",
                         "bananaba", "bananaban", "bananabana", "bananabanab", "bananabanaba",
                         "bananabanaba$", "ananabanaba$", "nanabanaba$", "anabanaba$",
                         "nabanaba$", "abanaba$", "banaba$", "anaba$", "naba$", "aba$",
                         "ana", "a$", "$", "ban", "bana", "banan", "banana", "bananab",
                         "bananaba", "bananaban", "bananabana", "bananabanab", "bananabanaba",
                         "bananabanaba$"};
    std::cout<< "String is: " << str << std::endl;
    for (int i = 0; i < 47; ++i) {
        std::cout << "Searching for: " << subStr[i] << " ";
        t->search(subStr[i]);
    }
    std::cout << std::endl;

    str = "abracadabra$";
   t = new SuffixTree(str, 12);
//    t->print();
  char*  suffix_array []= {"abracadabra$", "bracadabra$", "racadabra$", "acadabra$", "cadabra$", "adabra$", "dabra$", "abra$", "bra$", "ra$", "a$",
            "$", "abracadabra", "bracadabra", "racadabra", "acadabra", "cadabra", "adabra", "dabra", "abra", "bra", "ra", "a", "$"};

    for (int i = 0; i < 24; ++i) {
        std::cout << "Searching for: " << suffix_array[i] << " ";
        t->search(suffix_array[i]);
    }


    //t.Search("ana"); // Prints: 1 3 7
    //t.Search("naba"); // Prints: 4 8

    // Add test cases here.


    return 0;
}
