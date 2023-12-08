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
         Node* head ;
        Node* tail;
        int size = 0;

        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void insert(SuffixNode* data) {
            size++;
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

        /// this function removes a node from a list
        void remove(int index)
        {
            // if the node is the head of the list
            if (index == head->data->startIndex)
            {
               Node* temp = head;
                head = head->next; // let the next of the head be the new head
                free(temp);
            }
                // if the node is the tail
            else if (index == tail->data->startIndex){
               Node* current = head;
                while (current->next != tail) // loop on the list until the tail is the next to the current node
                    current = current->next;
                Node* temp = current->next; // temp is pointing to the tail
                current->next = nullptr; // make the node before the tail point to node
                tail = current; // let the node before the tail be the new tail
                free(temp);
            }
                // if the node is neither the head nor the tail (could be found or not)
            else{
                Node* current = head;
                while (current->next->data->startIndex != index){ // loop on the list until the node to be removed is next
                    current = current->next;
                    // if the loop has come to an end and the node isn't yet found, let the user know it doesn't exist
                    if(current == tail)
                    {
                        return;
                    }
                }
                // if found
                Node* temp = current->next; //
                current->next = temp->next;
                free(temp);
            }
            size--;
        }

        /// this function searches for a node in the list
        SuffixNode* search(int index, const char* str, SuffixNode* prev , int len  )
        {
            Node* current = head;
            int temp = index;
            for (int i = 0; i < size; i++) // TODO
            {
                // if the node is found, return it
                if(str[current->data->startIndex] == str[index]) {
                    int sz;
                    if(current->data->suffixStartIndex != -1){
                        sz = len - current->data->startIndex;
                    }
                    else{
                       int minStart= getMinNode(current);
                       sz =minStart- current->data->startIndex;
                    }
                    ///
                    int j;
                    for ( j = current->data->startIndex; j <sz  ; ++j) {
                        if(str[j] != str[index++]){
                          int id=  current->data->suffixStartIndex;
                            current->data->suffixStartIndex = -1;
                            auto* newNode =  new SuffixNode(j -current->data->startIndex+temp, temp);
                            auto* newNode2 =  new SuffixNode(j ,id);
                            current->data->suffixes.insert(newNode2);
                            current->data->suffixes.insert(newNode);
                            return prev;
                        }
                    }

                    if(j != len-1){
                        std::cout << "here";
                    }
                    return current->data;
                }
                current = current->next;
            }
            prev->suffixes.insert(new SuffixNode(index, index));
            // if the whole list is searched and the node isn't found,
            // return null pointer
            return nullptr;
        }

     int getMinNode(Node* current ){
            SuffixNode* min = current->data;
            while (current){
                if(current->data->startIndex < min->startIndex){
                    min = current->data;
                }
                current = current->next;
            }
            return min->startIndex;
        }
    };



    LinkedList suffixes;

    SuffixNode(int startIndex, int suffixStartIndex) {
        this->startIndex = startIndex;
        this->suffixStartIndex = suffixStartIndex;
    }
    SuffixNode()= default;
};


//        {
//            if(current->data->suffixStartIndex == index){
//                return current->data;
//            }
//            if(current->data->suffixStartIndex > index){
//                return prev->data;
//            }
//            if(current->data->suffixes.isEmpty()){
//                return prev->data;
//            }
//            for (int i = 0; i < size; i++)
//            {
//                // if the node is found, return it
//                if(str[current->data->suffixStartIndex] == str[index]) {
//                    search( index+1, str, current->data->suffixes.head, head);
//
//                }
//            }
//            // if the whole list is searched and the node isn't found,
//            // return null pointer
//            return nullptr;
//        }