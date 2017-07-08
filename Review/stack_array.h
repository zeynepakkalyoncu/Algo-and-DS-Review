#ifndef stack_array_h
#define stack_array_h

template <typename T>
class Stack {
private:
    int _top;
    int _capacity;
    T* arr;
public:
    Stack(int capacity) : _top(-1), _capacity(capacity), arr(new T[capacity]) {}
    bool isEmpty() {
        return (this->_top == -1);
    }
    bool isFull(int current) {
        return (current == this->_capacity - 1);
    }
    void push(T data) {
        if (!this->isFull(this->_top + 1)) {
            // doesn't overflow
            arr[this->_top++] = data;
        }
    }
    T pop() {
        if (!this->isEmpty()) {
            T top = arr[this->_top--];
            return top;
        }
    }
    T top() {
        if (!this->isEmpty()) {
            T top = arr[this->_top];
            return top;
        }
    }
    ~Stack() {
        delete arr;
    }
};

#endif
