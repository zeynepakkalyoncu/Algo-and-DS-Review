#ifndef double_node_h
#define double_node_h

template <typename T>
class DoubleNode<T> {
private:
    T _data;
    DoubleNode<T>* _next;
    DoubleNode<T>* _prev;
public:
    DoubleNode<T>() : _next(NULL), _prev(NULL);
    DoubleNode<T>(T data) : _data(data), _next(NULL), _prev(NULL);
    DoubleNode<T>(T data, DoubleNode<T>* next, DoubleNode<T>* prev) : _data(data), _next(next), _prev(prev);
};

#endif
