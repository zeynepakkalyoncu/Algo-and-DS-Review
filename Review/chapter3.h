#ifndef chapter3_h
#define chapter3_h

#include <cmath>
#include <vector>

#include "single_node.h"
#include "stack_array.h"

// naive solution
template <typename T>
class ThreeStacksInOne {
private:
    T* _arr;
    int _size;
    int _top1, _top2, _top3;
    int _capacity1, _capacity2, _capacity3;
public:
    ThreeStacksInOne(int size) {
        _arr = new T[size];
        _size = size;
        _capacity1 = ceil(size / 3); _capacity2 = ceil(size / 3) * 2; _capacity3 = size;
        _top1 = -1; _top2 = _capacity1 - 1; _top3 = _capacity2 - 1;
    }
    
    void push1(T element) {
        if (_top1 < _capacity1 - 1) {
            _arr[++_top1] = element;
        }
    }
    
    void push2(T element) {
        if (_top2 < _capacity2 - 1) {
            _arr[++_top2] = element;
        }
    }
    
    void push3(T element) {
        if (_top3 < _capacity3 - 1) {
            _arr[++_top3] = element;
        }
    }
    
    T pop1() {
        if (_top1 >= 0) {
            return _arr[_top1--];
        }
        else return NULL;
    }
    
    T pop2() {
        if (_top2 >= _capacity1) {
            return _arr[_top2--];
        }
        else return NULL;
    }
    
    T pop3() {
        if (_top3 >= _capacity2) {
            return _arr[_top3--];
        }
        else return NULL;
    }
    
    void print() {
        for (int i = 0; i <= _top1; i++)
            std::cout << _arr[i] << " ";
        std::cout << "| ";
        for (int i = _capacity1; i <= _top2; i++)
            std::cout << _arr[i] << " ";
        std::cout << "| ";
        for (int i = _capacity2; i <= _top3; i++)
            std::cout << _arr[i] << " ";
        std::cout << std::endl;
    }
    
    ~ThreeStacksInOne() { delete _arr; }
};

// keeping track of free space
template <typename T>
class ThreeStacksInOneAdvanced {
private:
    T* _arr;
    SingleNode<T>* freeList;
    SingleNode<T>* topList1, *topList2, *topList3;
public:
    ThreeStacksInOneAdvanced(int size) {
        if (size > 0) {
            _arr = new T[size];
            freeList = new SingleNode<T>(0);
            for (int i = 1; i < size; i++) {
                SingleNode<T>* newNode = new SingleNode<T>(i);
                newNode->next = freeList;
                freeList = newNode;
            }
            topList1 = NULL; topList2 = NULL; topList3 = NULL;
        }
    }
    
    void push1(T element) {
        if (freeList) {
            SingleNode<T>* freeNode = freeList;
            freeList = freeList->next;
            
            _arr[freeNode->data] = element;
            
            SingleNode<T>* newTop = new SingleNode<T>(freeNode->data);
            newTop->next = topList1;
            topList1 = newTop;
        }
        // else stack overflow
    }

    void push2(T element) {
        if (freeList) {
            SingleNode<T>* freeNode = freeList;
            freeList = freeList->next;
            
            _arr[freeNode->data] = element;
            
            SingleNode<T>* newTop = new SingleNode<T>(freeNode->data);
            newTop->next = topList2;
            topList2 = newTop;
        }
        // else stack overflow
    }
    
    void push3(T element) {
        if (freeList) {
            SingleNode<T>* freeNode = freeList;
            freeList = freeList->next;
            
            _arr[freeNode->data] = element;
            
            SingleNode<T>* newTop = new SingleNode<T>(freeNode->data);
            newTop->next = topList3;
            topList3 = newTop;
        }
        // else stack overflow
    }
    
    T pop1() {
        if (topList1) {
            SingleNode<T>* popNode = topList1;
            topList1 = topList1->next;
            
            SingleNode<T>* freeNode = new SingleNode<T>(popNode->data);
            freeNode->next = freeList;
            freeList = freeNode;
            
            return _arr[popNode->data];
        }
        else {
            // stack underflow
            return NULL;
        }
    }
    
    T pop2() {
        if (topList2) {
            SingleNode<T>* popNode = topList2;
            topList2 = topList2->next;
            
            SingleNode<T>* freeNode = new SingleNode<T>(popNode->data);
            freeNode->next = freeList;
            freeList = freeNode;
            
            return _arr[popNode->data];
        }
        else {
            // stack underflow
            return NULL;
        }
    }
    
    T pop3() {
        if (topList3) {
            SingleNode<T>* popNode = topList3;
            topList3 = topList3->next;
            
            SingleNode<T>* freeNode = new SingleNode<T>(popNode->data);
            freeNode->next = freeList;
            freeList = freeNode;
            
            return _arr[popNode->data];
        }
        else {
            // stack underflow
            return NULL;
        }
    }
    
    void print() {
        SingleNode<T>* ptr = topList1;
        while (ptr) {
            std::cout << _arr[ptr->data] << " ";
            ptr = ptr->next;
        }
        
        std::cout << "| ";
        
        ptr = topList2;
        while (ptr) {
            std::cout << _arr[ptr->data] << " ";
            ptr = ptr->next;
        }
        
        std::cout << "| ";
        
        ptr = topList3;
        while (ptr) {
            std::cout << _arr[ptr->data] << " ";
            ptr = ptr->next;
        }
        
        std::cout << std::endl;
    }
    
    ~ThreeStacksInOneAdvanced() {
        delete _arr;
        
        SingleNode<T>* ptr = freeList;
        while (ptr && ptr->next) {
            SingleNode<T>* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
        }
        delete freeList;
        
        ptr = topList1;
        while (ptr && ptr->next) {
            SingleNode<T>* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
        }
        delete topList1;
        
        ptr = topList2;
        while (ptr && ptr->next) {
            SingleNode<T>* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
        }
        delete topList2;
        
        ptr = topList3;
        while (ptr && ptr->next) {
            SingleNode<T>* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
        }
        delete topList3;
        
    }
};

///////////////

template <typename T>
class StackWithMin {
private:
    std::pair<T, T>* _arr;
    int _top;
    int _capacity;
    int _min;
public:
    StackWithMin(int capacity) {
        _capacity = capacity;
        _top = -1;
        _arr = new std::pair<T, T>[capacity];
        _min = INFINITY;
    }
    
    int min() {
        return _min;
    }
    
    void push(T element) {
        if (_top < _capacity - 1) {
            _arr[++_top] = std::pair<T, T>(element, _min);
            if (element < _min) _min = element;
        }
    }
    
    T pop() {
        if (_top >= 0) {
            std::pair<T, T> top_pair = _arr[_top];
            if (top_pair.first == _min) {
                _min = top_pair.second;
            }
            _top--;
            return top_pair.first;
        }
        else return NULL; // stack underflow
    }
    
    void print() {
        for (int i = 0; i <= _top; i++) {
            std::cout << _arr[i].first << "-" << _arr[i].second << " ";
        }
        std::cout << std::endl;
    }
    
    ~StackWithMin() {
        if (_arr) delete _arr;
    }
};

///////////////

template <typename T>
class SetOfStacks {
private:
    std::vector<StackArr<T>* > _stacks;
    int _threshold;
public:
    SetOfStacks(int threshold) : _threshold(threshold) {
        _stacks.push_back(new StackArr<T>(_threshold));
    }
        
    void push(T element) {
        StackArr<T>* last_stack = _stacks.back();
        last_stack->push(element);
        if (last_stack->isFull(last_stack->top())) {
            _stacks.push_back(new StackArr<T>(_threshold));
        }
    }
    
    T pop() {
        if (!_stacks.empty()) {
            StackArr<T>* last_stack = _stacks.back();
            T element = last_stack->pop();
            if (last_stack->isEmpty()) _stacks.pop_back();
            return element;
        }
        else return NULL;
    }
    
    T popAt(int index) {
        
    }
    
    void print() {
        
        int num_of_stacks = _stacks.size();
        for (int i = 0; i < num_of_stacks; i++) {
            for (int j = 0; j < _threshold; j++) {
                _stacks[i]->print();
            }
            std::cout << "| ";
        }
        std::cout << std::endl;
    }
};

///////////////

// time: O(2^n) space: O(n)
void towers_of_hanoi_stack(StackArr<int> rods[3]) {
    StackArr<int> s;
    while (!rods[0].isEmpty()) {
        while (!rods[0].isEmpty()) {
            int top = rods[0].pop();
            rods[1].push(top);
        }
        
        int top = rods[1].pop();
        rods[2].push(top);
        
        while (!rods[1].isEmpty()) {
            int top = rods[1].pop();
            rods[0].push(top);
        }
    }
}

///////////////

template <typename T>
class MyQueue1 {
private:
    StackArr<T> s1, s2;
public:
    MyQueue1(int capacity) {
        s1 = StackArr<T>(capacity);
        s2 = StackArr<T>(capacity);
    }
    
    // time: O(n)
    void enqueue(T element) {
        while (!s1.isEmpty()) {
            T top = s1.pop();
            s2.push(top);
        }
        s1.push(element);
        while (!s2.isEmpty()) {
            T top = s2.pop();
            s1.push(top);
        }
    }
    
    // time: O(1)
    T dequeue() {
        return s1.pop();
    }

};

template <typename T>
class MyQueue2 {
private:
    StackArr<T> s1, s2;
public:
    MyQueue2(int capacity) {
        s1 = StackArr<T>(capacity);
        s2 = StackArr<T>(capacity);
    }
    
    // time: O(1)
    void enqueue(T element) {
        s1.push(element);
    }
    
    // time: O(n)
    T dequeue() {
        while (!s1.isEmpty()) {
            T pop = s1.pop();
            s2.push();
        }
        T front = s2.pop();
        while (!s2.isEmpty()) {
            T pop = s2.pop();
            s1.push();
        }
    }
};

///////////////

// time: O(n^2) space: O(n)
template <typename T>
void sort_stack(StackArr<T>& sarr) {
    StackArr<T> s2(10);
    
    while (!sarr.isEmpty()) {
        T temp = sarr.pop();
        if (s2.isEmpty() || s2.top() > temp) {
            s2.push(temp);
        }
        else {
            while (!s2.isEmpty()) {
                T top = s2.pop();
                sarr.push(top);
            }
            s2.push(temp);
        }
    }
    
    while (!s2.isEmpty()) {
        T top = s2.pop();
        sarr.push(top);
    }
}

#endif
