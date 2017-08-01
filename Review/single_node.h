#ifndef single_node_h
#define single_node_h

#include <iostream>

template <typename T>
class SingleNode {
public:
    T data;
    SingleNode<T>* next;
    
    SingleNode() : next(NULL) {};
    SingleNode(T data) : data(data), next(NULL) {};
    SingleNode(T data, SingleNode<T>* next) : data(data), next(next) {};
    /*
    SingleNode<T>* next() {
        return this->_next;
    }
    T data() {
        return this->_data;
    }
     */
    void printNode() {
        std::cout << data << std::endl;
    }
    bool operator==(const SingleNode<T>& rhs) {
        return (this->data == rhs.data);
    }
    bool operator!=(const SingleNode<T>& rhs) {
        return !(*this == rhs);
    }
};

#endif
