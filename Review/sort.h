#ifndef sort_h
#define sort_h

#include <vector>
#include <cmath>

#include "max_heap.h"

///////// UTILITIES ///////////
template <typename T>
void dijkstra_partition(vector<T>& vec) {
    int size = vec.size();
    int lt = 0, gt = size - 1;
    
    T value = vec[0];
    
    for (int i = 0; i < size; i++) {
        if (vec[i] < value) {
            T temp = vec[i];
            vec[i] = vec[lt];
            vec[lt] = temp;
            lt++;
        }
        else if (vec[i] > value) {
            T temp = vec[i];
            vec[i] = vec[gt];
            vec[gt] = temp;
            gt--;
        }
    }
}

///////// COMPARISON SORT ///////////

// time: O(n^2) space: O(1)
template <typename T>
void selection_sort(vector<T>& vec) {
    size_t vec_size = vec.size();
    
    if (vec_size == 0) return;
    
    for (int i = 0; i < vec_size - 1; i++) {
        T min = vec[i];
        int min_index = i;
        for (int j = i + 1; j < vec_size; j++) {
            if (vec[j] < min) {
                min = vec[j];
                min_index = j;
            }
        }
        if (min_index != i) {
            vec[min_index] = vec[i];
            vec[i] = min;
        }
    }
}

// time: O(n^2) space: O(1)
template <typename T>
void bubble_sort(vector<T>& vec) {
    size_t vec_size = vec.size();
    for (int i = vec_size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j + 1] < vec[j]) {
                T temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

// time: O(n^2) space: O(1)
template <typename T>
void insertion_sort(vector<T>& vec) {
    size_t vec_size = vec.size();
    for (int i = 1; i < vec_size; i++) {
        int j = i;
        while ((j > 0) && (vec[j - 1] > vec[j])) {
            T temp = vec[j - 1];
            vec[j - 1] = vec[j];
            vec[j] = temp;
            j--;
        }
    }
}

// time: O(nlg^2n) space: O(1)
template <typename T>
void shell_sort(vector<T>& vec) {
    size_t vec_size = vec.size();
    int h = 1;
    
    while (h < (vec_size / 3)) h = 3 * h + 1;
    
    while (h >= 1) {
        for (int i = h; i < vec_size; i++) {
            int j = i;
            while ((j > 0) && (vec[j - h] > vec[j])) {
                T temp = vec[j - h];
                vec[j - h] = vec[j];
                vec[j] = temp;
                
                j -= h;
            }
        }
        
        h /= 3;
    }
}

template <typename T>
void merge(vector<T>& vec, int low, int mid, int high) {
    vector<T> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    
    while ((i <= mid) && (j <= high)) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        }
        else {
            temp[k++] = vec[j++];
        }
    }
    
    while (i <= mid) temp[k++] = vec[i++];
    while (j <= high) temp[k++] = vec[j++];
    
    k = 0;
    
    while (k <= high - low) {
        vec[low + k] = temp[k];
        k++;
    }
}

// time: O(nlg^2n) space: O(1)
template <typename T>
void merge_sort(vector<T>& vec, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(vec, low, mid);
        merge_sort(vec, mid + 1, high);
        merge(vec, low, mid, high);
    }
}

// time: O(n) space: O(1)
template <typename T>
int partition_last(vector<T>& vec, int low, int high) {
    T pivot = vec[low];
    int i = low;
    for (int j = low + 1; j < high; j++) {
        if (vec[j] < pivot) {
            T temp = vec[++i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    return i;
}

template <typename T>
int pivot_median(vector<T>& vec, int low, int high) {
    int mid = low + (high - low) / 2;
    return max(min(vec[low], vec[mid]), min(max(vec[low], vec[mid]), vec[high]));
}

// time: O(n^2) space: O(logn)
// time: O(nlgn) space: O(logn)
template <typename T>
void quick_sort(vector<T>& vec, int low, int high) {
    
    int pivot = pivot_median(vec, low, high);
    
    int i = low, j = high;
    
    while (i <= j) {
        while (vec[i] < pivot) i++;
        while (vec[j] > pivot) j--;
        
        if (i <= j) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++; j++;
        }
    }
    
    if (low < j) quick_sort(vec, low, j);
    if (i < high) quick_sort(vec, i, high);
    
}

// time: O(nlgn) space: O(1)
template <typename T>
void heap_sort(vector<T>& vec) {
    MaxHeap<T> h(vec);
    
    int vec_size = vec.size();
    for (int i = vec_size - 1; i > 0; i--) {
        T temp = h.arr[i];
        h.arr[i] = h.arr[0];
        h.arr[0] = temp;
        
        h.size--;
        
        h.max_heapify(0);
    }
    
    // normally don't need to use the extra space
    for (int i = 0; i < vec_size; i++) vec[i] = h.arr[i];
}



///////// LINEAR SORT ///////////

// time: O(n + k) space: O(k)
template <typename T>
void counting_sort(vector<T>& vec) {
    int max_value = *max_element(vec.begin(), vec.end());
    int min_value = *min_element(vec.begin(), vec.end());
    int size = vec.size();
    int k = max_value - min_value;
    vector<T> count(k + 1), output(size);
    
    for (int i = 0; i <= k; i++) count[i] = 0;
    for (int i = 0; i < size; i++) count[vec[i] - min_value]++;
    for (int i = 1; i <= k; i++) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[vec[i] - min_value] - 1] = vec[i];
        count[vec[i] - min_value]--;
    }
    
    vec = output;
}

// time: O(n^2) space: O(n)
// time: theta(n +k) space: O(n)
void bucket_sort(std::vector<double>& vec, int n) {
    int size = vec.size();
    std::vector<SinglyLinkedList<double> > buckets(n);
    
    for (int i = 0; i < size; i++) {
        buckets[floor(vec[i] * n)].addToFront(vec[i]);
    }
    
    for (int i = 0; i < n; i++) {
        buckets[i].insertion_sort();
    }
    
    SingleNode<double>* ptr;
    int ind = 0;
    for (int i = 0; i < n; i++) {
        ptr = buckets[i].head();
        while (ptr) {
            vec[ind++] = ptr->data;
            ptr = ptr->next;
        }
    }
}

// time: O(n + k) space: O(k)
template <typename T>
void counting_sort_2(vector<T>& vec, int base, int exp) {
    int size = vec.size();
    vector<T> count(10), output(size);
    
    for (int i = 0; i < 10; i++) count[i] = 0;
    for (int i = 0; i < size; i++) count[(vec[i] / exp) % base]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--) {
        output[count[(vec[i] / exp) % base] - 1] = vec[i];
        count[(vec[i] / exp) % base]--;
    }
    
    vec = output;
}

// time: O(nk) space: O(n + k)
template <typename T>
void radix_sort(vector<T>& vec, int base) {
    int max_value = *max_element(vec.begin(), vec.end());
    for (int exp = 1; max_value / exp > 0; exp *= 10) {
        counting_sort_2(vec, base, exp);
    }
}

#endif
