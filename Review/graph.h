#ifndef graph_list_h
#define graph_list_h

#include <vector>
#include <queue>

#include "single_node.h"

enum VisitStatus { WHITE, GRAY, BLACK };

template <typename T>
class GraphList {
private:
    int vertex_count;
    std::vector<SingleNode<T>* > g;
public:
    GraphList() {}
    
    // time: O(V + E) - list O(V^2) - matrix / space: O(V)
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
    
    void BFS_alt(SingleNode<T>* start) {
        
        SingleNode<T>* prev[vertex_count] = { NULL};
        VisitStatus viisted[vertex_count] = { WHITE };
        int distance[vertex_count] = { INT_MAX };
        
        prev[start] = NULL; visited[start] = GRAY; distance[start] = 0;
        
        queue<SingleNode<T>*> q;
        q.push(start);
        
        while (!q.empty()) {
            SingleNode<T>* cur = q.pop();
            visited[cur] = BLACK;
            
            for (auto adj : g[cur]) {
                if (visited[adj] == WHITE) {
                    // not visited
                    prev[adj] = cur;
                    visited[adj] = GRAY;
                    distance[adj]++;
                    q.push(adj);
                }
            }
        }
    }
    
    ///////////////
    
    // time: O(V + E) - list O(V^2) - matrix / space: O(V)
    void DFS_rec(SingleNode<T>* node, bool* visited) {
        
        visited[node] = true;
        
        for (auto adj : g[node]) {
            if (!visited[adj]) {
                DFS_rec(adj, visited);
            }
        }
    
    }
    
    void DFS(SingleNode<T>* start) {
        bool visited[vertex_count] = { false };
        
        for (auto adj : g[start]) {
            DFS_rec(adj, visited);
        }
    }
    
    void DFS_alt_rec(SingleNode<T>* node, int time, SingleNode<T>* prev[vertex_count], VisitStatus visited[vertex_count], int start_time[vertex_count], int finish_time[vertex_count]) {
        visited[node] = GRAY; start_time = ++time;
        
        for (auto adj : g[node]) {
            if (visited[adj] == WHITE) {
                prev[adj] = node;
                DFS_alt_rec(adj, time, prev, visited, start_time, finish_time);
            }
        }
        
        visited[node] = BLACK; finish_time = ++time;
    }
    
    void DFS_alt(SingleNode<T>* start) {
        int time = 0;
        SingleNode<T>* prev[vertex_count] = { NULL };
        VisitStatus visited[vertex_count] = { WHITE };
        int start_time[vertex_count] = { INT_MAX };
        int finish_time[vertex_count] = { INT_MAX };
        
        for (auto adj : g[start]) {
            if (visited[adj] == WHITE) {
                prev[adj] = start;
                DFS_alt_rec(adj, time, prev, visited, start_time, finish_time);
            }
        }
    }
    
    ///////////////
    
    // time: O(VlgV + ElgE) - list O(V^2) - matrix / space: O(V)
    NTree<T>* prim_MST(SingleNode<T>* start) {
        priority_queue<T, std::vector<T>> pq;
        SingleNode<T>* prev[vertex_count] = { NULL };
        for (auto node : g) {
            pq.push(INT_MAX);
        }
        pq.push(start);
        
        while (!pq.empty()) {
            SingleNode<T>* cur = pq.pop();
            for (auto adj : g[cur]) {
                if ((pq.find(adj) != pq.end()) && (g[cur][adj] < pq[adj])) {
                    pq[adj] = g[cur][adj];
                    prev[adj] = cur;
                }
            }
        }
        
        // TODO: retrieve tree from prev
        return NULL;
    }

    ///////////////
    
    // TODO: fix
    
    #include "disjoint_set.h"
    NTree<T>* kruskal_MST(SingleNode<T>* start) {
        DisjointSet ds[vertex_count];
        
        // TODO: sort edges
        NTree<T>* tree;
        while (tree.size() < (n - 1)) {
            if (!find(edge.first, edge.second)) {
                union_set(edge.first, edge.second);
                tree.insert(edge);
            }
        }
        
        return tree;
    }
    
    ///////////////
    
    // time: O(VlgV + ElgV) - pq O(V^2) - array / space: O(V) - pq or array
    int* dijkstra(SingleNode<T>* start) {
        priority_queue<T, vector<T>> pq;
        int distance[vertex_count] = { INT_MAX};
        SingleNode<T>* prev = { NULL };
        
        pq.push(start); distance[start] = 0;
        
        for (auto node : g) {
            pq.push(node);
        }
        
        while (!pq.empty()) {
            SingleNode<T>* cur = pq.pop();
            for (auto adj : g[cur]) {
                if (distance[adj] > distance[cur] + g[cur][adj]) {
                    distance[adj] = distance[cur] + g[cur][adj];
                    prev[adj] = cur;
                }
            }
        }
        
        return distance;
    }
    
    
    ~GraphList() {}
};

#endif
