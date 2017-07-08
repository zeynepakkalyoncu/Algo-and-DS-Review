#ifndef queue_array_h
#define queue_array_h

template <typename T>
class Queue {
private:
    int _head;
    int _tail;
    int _capacity;
    T* arr;
public:
    Queue(int capacity) : _head(0), _tail(0), _capacity(capacity), arr(new T[capacity]) {}
    bool isEmpty() {
        return (this->_head == this->_tail);
    }
    bool isFull() {
        // called before enqueue
        return ((this->_tail + 1) % this->_capacity == this->_head);
    }
    void enqueue(T data) {
        if (!this->isFull()) {
            arr[this->_tail++] = data;
        }
    }
    T dequeue() {
        if (!this->isEmpty()) {
            T front = arr[this->_head++];
            return front;
        }
    }
    ~Queue() {
        delete arr;
    }
};

#endif
