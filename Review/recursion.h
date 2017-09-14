#ifndef recursion_h
#define recursion_h

#include <iostream>

// time: O(n^(n / 2)) space: O(n)
void comb_n_k(int arr[], int data[], int start, int end, int index, int k) {
    if (index == k) {
        for (int i = 0; i < k; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    
    else {
        for (int i = start; (i <= end) && (end - i + 1) >= k - index); i++) {
            data[index] = arr[i]; // fix arr[i] at data[index] and recur
            comb_n_k(arr, data, i + 1, end, index + 1, k);
        }
        
        // handle duplicates
        while (arr[i] == arr[i + 1]) i++;
    }
}

// time: O(n^(n / 2)) space: O(n)
void comb_n_k_2(int arr[], int data[], int i, int n, int index, int k) {
    if (index == k) {
        for (int i = 0; i < k; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
    }
    
    else {
        // include arr[i]
        data[index] = arr[i];
        comb_n_k_2(arr, data, i + 1, n, index + 1, k);
        
        // handle duplicates
        while (arr[i] == arr[i + 1]) i++;
        
        // exclude arr[i]
        comb_n_k_2(arr, data, i + 1, n, index, k);
    }
}

void towers_of_hanoi(int n, string s, string i, string t) {
    if (n == 1) {
        std::cout << "Moved peg from " + s + " to " + i << std::endl;
        return;
    }
    towers_of_hanoi(n - 1, s, i, t);
    towers_of_hanoi(1, s, t, i);
    towers_of_hanoi(n - 1, i, s, t);
}

#endif
