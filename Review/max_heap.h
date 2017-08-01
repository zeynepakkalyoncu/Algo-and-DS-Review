#ifndef max_heap_h
#define max_heap_h

#include "utils.h"



template <typename T>
class MaxHeap {
private:
    int length;
    // int size;
    // T* arr;
public:
    int size;
    T* arr;
    
    MaxHeap(int length) : length(length), size(0), arr(new T[length]) {}
    
    MaxHeap(vector<T>& vec) {
        int vec_size = vec.size();
        
        arr = new T[vec_size];
        length = vec_size;
        size = vec_size;
        
        for (int i = 0; i < vec_size; i++) {
            arr[i] = vec[i];
        }
        
        for (int i = vec_size / 2; i >= 0; i--) {
            max_heapify(i);
        }
    }
    
    void max_heapify(int i) {
        int largest = i;
        
        if (arr[2 * i] > arr[largest]) largest = 2 * i;
        if (arr[2 * i + 1] > arr[largest]) largest = 2 * i + 1;
        if (largest == i) return;
        
        T temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        
        max_heapify(largest);
    }
    
    void print_heap() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    
    ~MaxHeap() {
        delete arr;
    }
};

#endif
