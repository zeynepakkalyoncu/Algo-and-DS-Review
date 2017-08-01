#ifndef singly_linked_list_h
#define singly_linked_list_h

#include "single_node.h"

template <typename T>
class SinglyLinkedList {
private:
    SingleNode<T>* _head;
public:
    SinglyLinkedList() {
        this->_head = NULL;
    }
    
    SinglyLinkedList(std::vector<T> data) {
        this->_head = new SingleNode<T>(data[0]);
        size_t size = data.size();
        SingleNode<T>* ptr = this->_head;
        for (int i = 1; i < size; i++) {
            SingleNode<T>* newNode = new SingleNode<T>(data[i]);
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    
    SinglyLinkedList(SingleNode<T>* head) {
        this->_head = head;
    }
    
    SingleNode<T>* head() {
        return this->_head;
    }
    
    void setHead(SingleNode<T>* head) {
        this->_head = head;
    }
    
    bool isEmpty() {
        return (this->_head == NULL);
    }
    
    SingleNode<T>* getNodeByKey(T data) {
        SingleNode<T>* ptr = this->_head;
        while (ptr != NULL) {
            if (ptr->data == data) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }
    
    int size() {
        int count = 0;
        SingleNode<T>* ptr = this->_head;
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    
    SingleNode<T>* addToFront(T data) {
        SingleNode<T>* newNode = new SingleNode<T>(data);
        newNode->next = this->_head;
        this->_head = newNode;
        return newNode;
    }
    
    SingleNode<T>* addToEnd(T data) {
        SingleNode<T>* ptr = this->_head;
        if (ptr == NULL) {
            // empty list
            SingleNode<T>* newNode = new SingleNode<T>(data);
            this->_head = newNode;
            return this->_head;
        }
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        SingleNode<T>* newNode = new SingleNode<T>(data);
        ptr->next = newNode;
        return newNode;
    }
    
    SingleNode<T>* addAfter(SingleNode<T>* node, T data) {
        SingleNode<T>* ptr = this->head;
        if (ptr == NULL) {
            // empty list
            SingleNode<T>* newNode = new SingleNode<T>(data);
            this->head = newNode;
            return this->head;
        }
        while ((ptr != NULL) && (ptr != node)) {
            ptr = ptr->next;
        }
        if (ptr == NULL) return NULL; // reached end
        SingleNode<T>* newNode = new SingleNode<T>(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
        return newNode;
    }
    
    SingleNode<T>* addBefore(SingleNode<T>* node, T data) {
        SingleNode<T>* ptr = this->head;
        if (ptr == NULL) {
            // empty list
            SingleNode<T>* newNode = new SingleNode<T>(data);
            this->head = newNode;
            return newNode;
        }
        while ((ptr != NULL) && (ptr->next != node)) {
            ptr = ptr->next;
        }
        if (ptr == NULL) return NULL; // reached end
        SingleNode<T>* newNode = new SingleNode<T>(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
        return newNode;
    }
    
    void removeFromFront() {
        SingleNode<T>* ptr = this->head;
        if (ptr != NULL) {
            // not empty list
            this->head = this->head->next;
            delete ptr;
        }
    }
    
    void removeFromEnd() {
        SingleNode<T>* ptr = this->head;
        if (ptr != NULL) {
            // not empty list
            if (ptr->next == NULL) {
                // single element list
                this->head = NULL;
                delete ptr;
            }
            else {
                while ((ptr->next != NULL) && (ptr->next->next != NULL)) {
                    ptr = ptr->next;
                }
                SingleNode<T>* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
        }
    }
    void remove(SingleNode<T>* node) {
        SingleNode<T>* ptr = this->head;
        if (ptr != NULL) {
            // not empty list
            while ((ptr != NULL) && (ptr->next != node)) {
                ptr = ptr->next;
            }
            if (ptr == NULL) return; // couldn't find
            SingleNode<T>* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }
    }
    
    void remove(T data) {
        SingleNode<T>* ptr = this->head;
        if (ptr != NULL) {
            // not empty list
            while ((ptr != NULL) && (ptr->next->data != data)) {
                ptr = ptr->next;
            }
            if (ptr == NULL) return; // couldn't find
            SingleNode<T>* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }
    }
    
    void removeAll(T data) {
        SingleNode<T>* ptr = this->head;
        if (ptr != NULL) {
            // not empty list
            if (ptr->data == data) {
                SingleNode<T>* delNode = this->head;
                this->head = this->head->next;
                delete delNode;
                ptr = this->head;
            }
            while (ptr->next != NULL) {
                if (ptr->next->data == data) {
                    // delete node
                    SingleNode<T>* delNode = ptr->next;
                    ptr->next = ptr->next->next;
                    delete delNode;
                }
                ptr = ptr->next;
            }
        }
    }
    
    void printList() {
        SingleNode<T>* ptr = this->_head;
        while (ptr != NULL) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    
    ~SinglyLinkedList() {
        SingleNode<T>* ptr = this->_head;
        while (ptr != NULL) {
            SingleNode<T>* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
    
    // MERGE SORT
    void split(SingleNode<T>*& head, SingleNode<T>*& front, SingleNode<T>*& back) {
        
        if ((head == NULL) || (head->next == NULL)) {
            front = head;
            back = NULL;
        }
        
        else {
            SingleNode<T> *s = head, *f = head;
            
            while (s && f && f->next) {
                s = s->next;
                f = f->next->next;
            }
            
            front = head;
            back = s->next;
            s->next = NULL;
            
            /*front->printNode();
            back->printNode();*/
        }
        
    }
    
    SingleNode<T>* merge(SingleNode<T>*& ptr1, SingleNode<T>*& ptr2) {
        SingleNode<T>* newPtr = NULL;
        
        if (!ptr1) return ptr2;
        else if (!ptr2) return ptr1;
        
        if (ptr1->data <= ptr2->data) {
            newPtr = ptr1;
            newPtr->next = merge(ptr1->next, ptr2);
        }
        else {
            newPtr = ptr2;
            newPtr->next = merge(ptr1, ptr2->next);
        }
        
        newPtr->next = NULL;
        return newPtr;
    }
    
    void merge_sort(SingleNode<T>* headPtr) {
        SingleNode<T>* head = headPtr;
        SingleNode<T> *l = NULL, *m = NULL;
        
        if (head && head->next) {
            split(head, l, m);
            merge_sort(l);
            merge_sort(m);
            headPtr = merge(l, m);
        }
    }
    
    // INSERTION SORT
    // best - time: O(n) space: O(n)
    // average - time: O(n^2) space: O(n)
    // worst - time: O(n^2) space: O(n)
    void insertion_sort() {
    
        SingleNode<T>* ptr = _head, *out_head = NULL;
        
        while (ptr) {
            
            if (!out_head) {
                // empty linked list
                out_head = new SingleNode<T>(ptr->data);
            }
            else if (!out_head->next) {
                // single element
                if (out_head->data > ptr->data) {
                    SingleNode<T>* newHead = new SingleNode<T>(ptr->data);
                    newHead->next = out_head;
                    out_head = newHead;
                }
                else {
                    SingleNode<T>* newNode = new SingleNode<T>(ptr->data);
                    out_head->next = newNode;
                }
            }
            else {
                SingleNode<T>* ptr2 = out_head;
                while (ptr2->next) {
                    if (ptr2->next->data >= ptr->data) {
                        SingleNode<T>* newNode = new SingleNode<T>(ptr->data);
                        newNode->next = ptr2->next;
                        ptr2->next = newNode;
                        break;
                    }
                    ptr2 = ptr2->next;
                }
                if (!ptr2->next) {
                    SingleNode<T>* newNode = new SingleNode<T>(ptr->data);
                    ptr2->next = newNode;
                }
            }
            
            ptr = ptr->next;
        }
        
        _head = out_head;
    }
};

#endif
