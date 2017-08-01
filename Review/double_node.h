#ifndef double_node_h
#define double_node_h

template <typename T>
class DoubleNode<T> {
private:
    T _data;
    DoubleNode<T>* _next;
    DoubleNode<T>* _prev;
public:
    DoubleNode() : _next(NULL), _prev(NULL) {}
    DoubleNode(T data) : _data(data), _next(NULL), _prev(NULL) {}
    DoubleNode(T data, DoubleNode<T>* next, DoubleNode<T>* prev) : _data(data), _next(next), _prev(prev) {}
};

#endif
