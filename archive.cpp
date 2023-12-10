
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


///// this function removes a node from a list
//void remove(int index) {
//    // if the node is the head of the list
//    if (index == head->data->startIndex) {
//        Node *temp = head;
//        head = head->next; // let the next of the head be the new head
//        free(temp);
//    }
//        // if the node is the tail
//    else if (index == tail->data->startIndex) {
//        Node *current = head;
//        while (current->next != tail) // loop on the list until the tail is the next to the current node
//            current = current->next;
//        Node *temp = current->next; // temp is pointing to the tail
//        current->next = nullptr; // make the node before the tail point to node
//        tail = current; // let the node before the tail be the new tail
//        free(temp);
//    }
//        // if the node is neither the head nor the tail (could be found or not)
//    else {
//        Node *current = head;
//        while (current->next->data->startIndex !=
//               index) { // loop on the list until the node to be removed is next
//            current = current->next;
//            // if the loop has come to an end and the node isn't yet found, let the user know it doesn't exist
//            if (current == tail) {
//                return;
//            }
//        }
//        // if found
//        Node *temp = current->next; //
//        current->next = temp->next;
//        free(temp);
//    }
//    size--;
//}