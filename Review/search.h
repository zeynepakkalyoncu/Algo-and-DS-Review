#ifndef search_h
#define search_h

#include <vector>

template <typename T>
int b_search(vector<T>& vec, T val) {
    int vec_size = vec.size();
    int low = 0, high = vec_size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (vec[mid] == val) return mid;
        else if (vec[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;
}

template <typename T>
int b_search_rec(vector<T>& vec, T val, int low, int high) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if (vec[mid] == val) return mid;
    else if (vec[mid] < val) return b_search_rec(vec, val, mid + 1, high);
    else return b_search_rec(vec, val, low, mid - 1);
}

#endif
