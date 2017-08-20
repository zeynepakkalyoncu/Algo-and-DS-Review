#ifndef chapter2_h
#define chapter2_h

#include "singly_linked_list.h"

#include <unordered_set>
// time: O(n) space: O(n)
void remove_dup_buffer(SinglyLinkedList<int>& list) {
    std::unordered_set<int> dup_set;
    SingleNode<int>* ptr = list.head();
    dup_set.insert(ptr->data);
    
    while (ptr->next != NULL) {
        if (dup_set.find(ptr->next->data) != dup_set.end()) {
            SingleNode<int>* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
        }
        else {
            dup_set.insert(ptr->next->data);
            ptr = ptr->next;
        }
    }
}

// time: O(nlogn) space: O(n)
void remove_dup_sort(SinglyLinkedList<int>& list) {
    
}

// time: O(n^2) space: O(1)
void remove_dup_double(SinglyLinkedList<int>& list) {
    SingleNode<int>* ptr = list.head();
    while (ptr != NULL) {
        SingleNode<int>* ptr2 = ptr;
        while (ptr2->next != NULL) {
            if (ptr->data == ptr2->next->data) {
                // duplicate => remove
                SingleNode<int>* delNode = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete delNode;
            }
            else {
                ptr2 = ptr2->next;
            }
        }
        ptr = ptr->next;
    }
}

///////////////

// m: number of nodes

// time: O(m) (iterate twice) space: O(1)
SingleNode<int>* last_nth_iterate(SinglyLinkedList<int>& list, int n) {
    
    if (n < 0) return NULL; //
    
    int counter = 0;
    SingleNode<int>* ptr = list.head();
    while (ptr != NULL) {
        counter++;
        ptr = ptr->next;
    }
    
    if (counter <= n) return NULL; //
    
    ptr = list.head();
    
    for (int i = 1; i < counter - n; i++) {
        ptr = ptr->next;
    }
    
    return ptr;
}

#include <queue>
// time: O(m) (iterate once) space: O(n)
SingleNode<int>* last_nth_queue(SinglyLinkedList<int>& list, int n) {
    std::queue<SingleNode<int>* > q;
    SingleNode<int>* ptr = list.head();
    
    while (ptr != NULL) {
        
        q.push(ptr);
        
        if (ptr->next == NULL) {
            // reached tail
            return q.front();
        }
        
        if (q.size() > n) {
            q.pop();
        }
        
        ptr = ptr->next;
    }
    
    return NULL;
}

///////////////

// time: O(1) space: O(1)
void delete_middle(SingleNode<int>* given) {
    SingleNode<int>* delNode = given->next;
    given->data = given->next->data;
    given->next = given->next->next;
    delete delNode;
}

///////////////

// time: O(n) space: O(n)
SinglyLinkedList<int> add_linked_lists(SinglyLinkedList<int>& list1, SinglyLinkedList<int>& list2) {
    SingleNode<int>* ptr1 = list1.head(), *ptr2 = list2.head();
    SinglyLinkedList<int> newList;
    
    int carry_on = 0;
    
    while ((ptr1 != NULL) || (ptr2 != NULL)) {
        int val = 0;
        if (ptr1) {
            val += ptr1->data;
            ptr1 = ptr1->next;
        }
        if (ptr2) {
            val += ptr2->data;
            ptr2 = ptr2->next;
        }
        
        if (newList.isEmpty()) newList.setHead(new SingleNode<int>(val % 10 + carry_on));
        else {
            newList.addToEnd(val % 10 + carry_on);
        }
        
        carry_on = val / 10;
    }
    
    return newList;
}

///////////////

// time: O(n) space: O(1)
SingleNode<int>* loop_beginning(SinglyLinkedList<int> list) {
    SingleNode<int>* h = list.head(), *t = list.head();
    
    while (t && h && h->next) {
        if (t == h) break;
        t = t->next;
        h = h->next->next;
    }
    
    t = list.head();
    
    while (t != h) {
        t = t->next;
        h = h->next;
    }
    
    return t;
}

#endif
