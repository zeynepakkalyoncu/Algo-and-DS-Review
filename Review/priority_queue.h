#ifndef priority_queue_h
#define priority_queue_h

#include <vector>

#include "utils.h"

// int max PQ
class PriorityQueue {
private:
    //T* _array;
    int _size;
    
    std::vector<int> _array;
public:
    PriorityQueue(int size) {
        //_array = new T[size];
        _size = size;
        
        _array = vector<int>(size);
    }
    
    // time: O(lgn) space: O(1)
    void insert(int elem) {
        _array.push_back(INT_MAX);
        int ind = _array.size() - 1;
        increase_key(ind, elem);
    }
    
    // time: O(lgn) space: O(1)
    void increase_key(int ind, int new_val) {
        _array[ind] = new_val;
        while ((ind > 0) && (_array[ind / 2] < _array[ind])) {
            int temp = _array[ind / 2];
            _array[ind / 2] = _array[ind];
            _array[ind] = temp;
            
            ind = ind / 2;
        }
    }
    
    // time: O(1) space: O(1)
    int max() {
        if (_array.size() > 0) return _array[0];
        else return -1; // underflow
    }
    
    // could have used max heap instead
    void max_heapify(int ind) {
        
        if (ind >= _size) return;
        
        int largest = ind;
        
        if (_array[2 * ind] > _array[largest]) largest = 2 * ind;
        if (_array[2 * ind + 1] > _array[largest]) largest = 2 * ind + 1;
        
        int temp = _array[largest];
        _array[largest] = _array[ind];
        _array[ind] = temp;
        
        max_heapify(largest);
    }
    
    // time: O(lgn) space: O(1)
    int extract_max() {
        int max = _array[0];
        
        int last_ind = _array.size() - 1;
        
        // swap last and first
        int temp = _array[0];
        _array[0] = _array[last_ind];
        _array[last_ind] = temp;
        
        // decrease heap size
        _size--;
        _array.pop_back();
        
        // max heapify
        max_heapify(0);
        
        return max;
    }
    
    // time: O(n) space: O(1)
    void print_pq() {
        print_vec(_array);
    }
    
    ~PriorityQueue() {
       
    }
};


#endif
