#ifndef single_node_h
#define single_node_h

#include <iostream>

template <typename T>
class SingleNode {
public:
    T _data;
    SingleNode<T>* _next;
    
    SingleNode() : _next(NULL) {};
    SingleNode(T data) : _data(data), _next(NULL) {};
    SingleNode(T data, SingleNode<T>* next) : _data(data), _next(next) {};
    SingleNode<T>* next() {
        return this->_next;
    }
    void printNode() {
        std::cout << _data << std::endl;
    }
    bool operator==(const SingleNode<T>& rhs) {
        return (this->data == rhs.data);
    }
    bool operator!=(const SingleNode<T>& rhs) {
        return !(*this == rhs);
    }
};

#endif
