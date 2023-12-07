//class SuffixNode {
//public:
//    int startIndex;
//    int suffixStartIndex;
//
//    class Node {
//    public:
//        SuffixNode* data;
//        Node* next;
//
//        Node(SuffixNode* data, Node* next){
//            this->data = data;
//            this->next = next;
//        }
//    };
//
//    class LinkedList {
//    public:
//        Node* head;
//        Node* tail;
//
//        LinkedList() {
//            head = nullptr;
//            tail = nullptr;
//        }
//
//        void insert(SuffixNode* data) {
//            Node* newNode = new Node(data, nullptr);
//            if (head == nullptr) {
//                head = tail = newNode;
//            } else {
//                tail->next = newNode;
//                tail = newNode;
//            }
//        }
//
//        Node* search(int start) {
//            Node* current = head;
//            while (current) {
//                if (current->data->startIndex == start) {
//                    return current;
//                }
//                current = current->next;
//            }
//            return nullptr;
//        }
//    };
//
//    LinkedList suffixes;
//
//    SuffixNode(int startIndex, int suffixStartIndex) {
//        this->startIndex = startIndex;
//        this->suffixStartIndex = suffixStartIndex;
//    }
//};
