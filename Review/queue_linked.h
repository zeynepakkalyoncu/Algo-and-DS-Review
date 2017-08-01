#ifndef queue_linked_h
#define queue_linked_h

#include "single_node.h"

template <typename T>
class QueueLL {
private:
    SingleNode<T>* head, *tail;
public:
    QueueLL() : head(NULL), tail(NULL) {}
    
    void enqueue(T element) {
        SingleNode<T>* newNode = new SingleNode<T>(element);
        if (!head) {
            head = newNode;
        }
        if (tail) tail->next = newNode;
        tail = newNode;
    }
    
    T dequeue() {
        if (head) {
            SingleNode<T>* deqNode = head;
            head = head->next;
            return deqNode->data;
        }
        return NULL;
    }
    
    void print() {
        SingleNode<T>* ptr = head;
        while (ptr != NULL) {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    
    ~QueueLL() {
        SingleNode<T>* ptr = head;
        while (ptr->next != NULL) {
            SingleNode<T>* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
        }
        if (head) delete head;
    }
};

#endif
