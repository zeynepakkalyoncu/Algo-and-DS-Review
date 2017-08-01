#ifndef chapter9_h
#define chapter9_h

#include <vector>
#include "chapter1.h"

// time: O(n + m) space: O(1)
template <typename T>
void merge_arrays(std::vector<T>& vec1, std::vector<T>& vec2) {
    int size1 = vec1.size(), size2 = vec2.size();
    
    int n = 0;
    for (int i = 0; i < size1; i++) {
        if (vec1[n] == NULL) {
            break;
        }
        n++;
    }
    
    int new_ptr = size1 - 1;
    int a_ptr = n - 1, b_ptr = size2 - 1;
    
    while ((a_ptr >= 0) && (b_ptr >= 0)) {
        if (vec1[a_ptr] >= vec2[b_ptr]) {
            vec1[new_ptr--] = vec1[a_ptr--];
        }
        else {
            vec1[new_ptr--] = vec2[b_ptr--];
        }
        
        if (new_ptr < 0) break; // error
    }
    
    while (b_ptr >= 0) {
        vec1[new_ptr--] = vec2[b_ptr--];
        if (new_ptr < 0) break; // error
    }
}

///////////////

// time: O(nlgn) space: O(n)
void sort_anagrams(std::vector<string>& vec) {
    
}

///////////////

// time: O(lgn) space: O(1)
template <typename T>
int rotated_binary(std::vector<T>& vec, T val) {
    int size = vec.size();
    int low = 0, high = size - 1;
    
    if (size <= 0) return -1;
    
    T first = vec[0];
    
    while (low <= high) {
        
        int mid = low + (high - low) / 2;
        
        if (vec[mid] == val) return mid;
        else if (vec[mid] < val) {
            if (val > first) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if (val < first) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}

///////////////

// time: O(n) space: O(1)
int empty_binary(std::vector<string>& vec, std::string val) {
    int size = vec.size();
    int low = 0, high = size - 1;
    
    while (low <= high) {
        while ((low <= high) && (vec[high] == "")) {
            high--;
        }
        
        while ((low <= high) && (vec[low] == "")) {
            low++;
        }
        
        if (low > high) return -1;
        
        int mid = low + (high - low) / 2;
        while ((mid <= high) && (vec[mid] == "")) mid++;
        
        if (vec[mid] == val) {
            return mid;
        }
        else if (vec[mid] < val) low = mid + 1;
        else high = mid - 1;
        
    }
    
    return -1;
}

///////////////

struct coordinates {
    int row;
    int col;
};

// time: O(mn) space: O(1)
template <typename T>
struct coordinates find_mat(T** mat, int m, int n, T val) {
    int row = 0, col = n - 1;
    
    struct coordinates c;
    
    while ((col >= 0) && (row < m)) {
        if (mat[row][col] == val) {
            c.row = row;
            c.col = col;
            return c;
        }
        else if (mat[row][col] < val) {
            row++;
        }
        else {
            col--;
        }
    }
    
    c.row = -1;
    c.col = -1;
    return c;
}

#endif
