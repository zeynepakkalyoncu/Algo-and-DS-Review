#ifndef utils_h
#define utils_h

#include "singly_linked_list.h"
#include <vector>

using namespace std;

SinglyLinkedList<int> randomListGenerate() {
    vector<int> vec(10);
    for (int i = 0; i < 10; i++)
        vec[i] = rand() % 100;
    return SinglyLinkedList<int>(vec);
}

void print_binary_long(unsigned long x) {
    for (int i = 63; i >= 0; i--) {
        cout << ((x >> i) & 0x1);
    }
    cout << endl;
}

void print_binary(unsigned int x) {
    for (int i = 31; i >= 0; i--) {
        cout << ((x >> i) & 0x1);
    }
    cout << endl;
}

template <typename T>
void print_vec(vector<T>& vec) {
    size_t size = vec.size();
    for (int i = 0; i < size; i++) cout << vec[i] << " ";
    cout << endl;
}

template <typename T>
void knuth_shuffle(vector<T>& vec) {
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        int r = rand() % i;
        T temp = vec[r];
        vec[r] = vec[i];
        vec[i] = temp;
    }
}

#endif
