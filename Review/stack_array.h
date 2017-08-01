#ifndef stack_array_h
#define stack_array_h

template <typename T>
class StackArr {
private:
    int _top;
    int _capacity;
    T* arr;
public:
    StackArr() : _top(-1), _capacity(0), arr(new T[0]) {}
    StackArr(int capacity) : _top(-1), _capacity(capacity), arr(new T[capacity]) {}
    bool isEmpty() {
        return (this->_top == -1);
    }
    bool isFull(int current) {
        return (current == this->_capacity - 1);
    }
    void push(T data) {
        //if (!this->isFull(this->_top + 1)) {
        if (_top < _capacity - 1) {
            // doesn't overflow
            arr[++_top] = data;
        }
    }
    T pop() {
        if (!this->isEmpty()) {
            T top = arr[this->_top--];
            return top;
        }
        else return NULL;
    }
    
    T top() {
        if (!this->isEmpty()) {
            T top = arr[this->_top];
            return top;
        }
        else return NULL;
    }
    
    void print() {
        for (int i = 0; i <= _top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
    ~StackArr() {
        delete arr;
    }
};

#endif
