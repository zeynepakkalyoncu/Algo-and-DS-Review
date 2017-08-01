#ifndef stack_linked_h
#define stack_linked_h

#include "single_node.h"

template <typename T>
class StackLL {
private:
    SingleNode<T>* top;
public:
    StackLL() : top(NULL) {}
    
    void push(T element) {
        SingleNode<T>* newNode = new SingleNode<T>(element);
        newNode->next = top;
        top = newNode;
    }
    
    T pop() {
        if (top) {
            SingleNode<T>* popNode = top;
            top = top->next;
            return popNode->data;
        }
        
        return NULL; // stack underflow
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    void print() {
        // reverse print
        SingleNode<T>* ptr = top;
        
        while (ptr != NULL) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    
    ~StackLL() { delete top; }
};

#endif
