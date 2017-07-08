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
        int size = data.size();
        SingleNode<T>* ptr = this->_head;
        for (int i = 1; i < size; i++) {
            SingleNode<T>* newNode = new SingleNode<T>(data[i]);
            ptr->_next = newNode;
            ptr = newNode;
        }
    }
    
    SinglyLinkedList(SingleNode<T>* head) {
        this->__head = head;
    }
    
    SingleNode<T>* head() {
        return this->_head;
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
        newNode->next = this->head;
        this->head = newNode;
        return newNode;
    }
    
    SingleNode<T>* addToEnd(T data) {
        SingleNode<T>* ptr = this->head;
        if (ptr == NULL) {
            // empty list
            SingleNode<T>* newNode = new SingleNode<T>(data);
            this->head = newNode;
            return this->head;
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
            if (ptr->next == NULL) {
                // single element list
                this->head = NULL;
                delete ptr;
            }
            else {
                while (ptr != NULL) {
                    if ((ptr->next != NULL) && (ptr->next->data == data)) {
                        SingleNode<T>* temp = ptr->next;
                        ptr->next = ptr->next->next;
                        delete temp;
                    }
                    ptr = ptr->next;
                }
            }
        }
    }
    
    void printList() {
        SingleNode<T>* ptr = this->_head;
        while (ptr != NULL) {
            std::cout << ptr->_data << " ";
            ptr = ptr->_next;
        }
        std::cout << std::endl;
    }
    
    ~SinglyLinkedList() {
        SingleNode<T>* ptr = this->_head;
        while (ptr != NULL) {
            SingleNode<T>* temp = ptr;
            ptr = ptr->next();
            delete temp;
        }
    }
};

#endif
