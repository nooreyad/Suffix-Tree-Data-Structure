class SuffixNode {
public:
    int startIndex{};
    int suffixStartIndex{};

    class Node {
    public:
        SuffixNode* data;
        Node* next;

        Node(SuffixNode* data, Node* next){
            this->data = data;
            this->next = next;
        }
    };

    class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size = 0;

        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void insert(SuffixNode* data) {
            Node* newNode = new Node(data, nullptr);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        /// this function checks if a list is empty
        bool isEmpty() const { return size == 0; }

        /// this function searches for a node in the list
        Node* search(int info)
        {
            Node* current = head;
            for (int i = 0; i < size; i++)
            {
                // TODO
               // if the node is found, return it
               if(current->item->startIndex == info) {
                    current = current->next;
               }
            }
            // if the whole list is searched and the node isn't found,
            // return null pointer
            return nullptr;
        }
    };

    LinkedList suffixes;

    SuffixNode(int startIndex, int suffixStartIndex) {
        this->startIndex = startIndex;
        this->suffixStartIndex = suffixStartIndex;
    }
    SuffixNode()= default;
};
