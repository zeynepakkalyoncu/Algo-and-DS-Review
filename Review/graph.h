#ifndef graph_list_h
#define graph_list_h

#include <vector>
#include <queue>

#include "single_node.h"

template <typename T>
class GraphList {
private:
    int vertex_count;
    std::vector<SingleNode<T>* > g;
public:
    GraphList() {}
    
    void BFS(SingleNode<T>* start) {
        bool* visited = new bool[vertex_count];
        for (auto vertex in adjacency) {
            visited[vertex] = false;
        }
        
        queue<SingleNode<T>* > q;
        visited[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            SingleNode<T>* node = q.pop();
            SingleNode<T>* ptr = node;
            
            while (ptr) {
                if (!visited[ptr]) {
                    visited[ptr] = true;
                    q.push(ptr);
                }
                ptr = ptr->next;
            }
        }
    }
    
    ~GraphList() {}
};

#endif
