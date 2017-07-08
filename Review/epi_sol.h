#ifndef epi_sol_hpp
#define epi_sol_hpp

#include "singly_linked_list.h"
#include <vector>

using namespace std;

// UTILITIES

SinglyLinkedList<int> randomListGenerate() {
    vector<int> vec(10);
    for (int i = 0; i < 10; i++)
        vec[i] = rand() % 100;
    return SinglyLinkedList<int>(vec);
}

// SOLUTIONS

#endif
