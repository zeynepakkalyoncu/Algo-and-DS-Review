#ifndef queue_array_h
#define queue_array_h

template <typename T>
class QueueArr {
private:
    int _head;
    int _tail;
    int _capacity;
    T* arr;
public:
    QueueArr(int capacity) : _head(0), _tail(0), _capacity(capacity), arr(new T[capacity]) {}
    
    bool isEmpty() {
        return (_head == _tail);
    }
    
    bool isFull() {
        return (_tail % _capacity == _head);
    }
    
    void enqueue(T data) {
        if (!isFull()) {
            arr[_tail++ % _capacity] = data;
        }
    }
    
    T dequeue() {
        if (!isEmpty()) {
            return arr[_head--];
        }
    }
    
    void print() {
        for (int i = _head; i <= _tail; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
    ~QueueArr() {
        delete arr;
    }
};

#endif
