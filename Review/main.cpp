#include <iostream>
#include "epi_sol.h"

int main(int argc, const char * argv[]) {
    
    SinglyLinkedList<int> myList = randomListGenerate();
    myList.printList();
    
    return 0;
}
