#ifndef chapter4_h
#define chapter4_h

// time: O(n) space: O(n)
template <typename T>
int max_depth(NTreeNode<T>* node) {
    if (node.isLeaf()) return 0;
    else {
        int depth = INT_MIN;
        for (auto child : node->children) {
            depth = max(depth, max_depth(child));
        }
        return 1 + depth;
    }
}

int min_depth(NTreeNode<T>* node) {
    if (node.isLeaf()) return 0;
    else {
        int depth = INT_MAX;
        for (auto child : node->children) {
            depth = min(depth, max_depth(child));
        }
        return 1 + depth;
    }
}

bool balanced(NTreeNode<T>* node) {
    return (max_depth(node) - min_depth(node) >= 1)
}

///////////////

// time: O(V + E) space: O(V)
template <typename T>
void dfs_helper(NTreeNode<T>* node, NTreeNode<T>* target, bool* visited, bool state) {
    visited[node] = true;
    
    for (auto child : node->children) {
        if (child == target) {
            state = true;
            return;
        }
        dfs_helper(child, target, visited, state);
    }
}

template <typename T>
bool path_exists(NTreeNode<T>* node1, NTreeNode<T>* node2, int vertex_count) {
    
    if (node1 == node2) return true;
    
    bool visited[vertex_count] = { false };
    bool found = false;
    
    for (auto child : node1->children) {
        if (!visited[child->key]) {
            dfs_helper(child, node2, visited, found);
        }
        
        if (found) return true;
    }
}

///////////////

// time: O(n) space: O(n)
/*
template <typename T>
std::vector<LinkedList<T>> ll_depths(BinaryNode<T>* node) {
    std::vector<LinkedList<T>> vec;
    queue<BinaryNode<T>*> q;
    
    q.push(node);
    q.push(NULL);
    LinkedList<T> ll;
    ll.insert(node);
    
    while (!q.empty()) {
        BinaryNode<T>* top = q.pop();
        if (!top) {
            vec.push_back(ll);
            ll = LinkedList<T>();
        }
        else {
            q.push(top->left);
            q.push(top->right);
        }
    }
}*/

///////////////

// time: O(lgn) space: O(1)
template <typename T>
BinaryNode<T>* inorder_successor(BinaryNode<T>* node) {
    if (node->right) {
        return node->right;
    }
    else {
        while (node) {
            if (node->parent->left == node) {
                return node->parent;
            }
            else {
                node = node->parent;
            }
        }
    }
}

#endif
