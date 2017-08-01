#ifndef n_tree_h
#define n_tree_h

#include "ntree_node.h"

#include <algorithm>
#include <queue>

template <typename T>
class NTree {
private:
    NTreeNode<T>* _root;
public:
    NTree() : _root(NULL) {}
    NTree(NTreeNode<T>* root) : _root(root) {}
    
    // time: O(n) space: O()
    int nodeDepth(NTreeNode<T>* node) {
        if (node.isRoot()) return 0;
        else return 1 + nodeDepth(node->_parent);
    }
    
    // time: O(n) space: O()
    int nodeHeight(NTreeNode<T>* node) {
        if (node.isLeaf()) return 0;
        else {
            int h = 0;
            std::vector<NTreeNode<T>* >& children = node->_children;
            int num_of_children = children.size();
            for (int i = 0; i < num_of_children; i++)
                h = max(h, nodeHeight(children[i]));
            return h + 1;
        }
    }
    
    // time: O() space: O()
    void preorderTraversal(NTreeNode<T>* node) {
        if (node) {
            std::cout << node->data << " ";
            std::vector<NTreeNode<T>* >& children = node->_children;
            int num_of_children = children.size();
            for (int i = 0; i < num_of_children; i++) {
                preorderTraversal(children[i]);
            }
        }
    }
    
    // time: O() space: O()
    void postorderTraversal(NTreeNode<T>* node) {
        if (node) {
            std::vector<NTreeNode<T>* >& children = node->_children;
            int num_of_children = children.size();
            for (int i = 0; i < num_of_children; i++) {
                postorderTraversal(children[i]);
            }
            std::cout << node->data << " ";
        }
        
        std::cout << std::endl;
    }
    
    // time: O(n) space: O(n)
    void levelorderTraversal(NTreeNode<T>* node) {
        queue<NTreeNode<T>* > q;
        q.push(node);
        
        while (!q.empty()) {
            NTreeNode<T>* curNode = q.pop();
            std::vector<NTreeNode<T>* > children = curNode->children();
            for (auto child : children) {
                q.push(child);
            }
            std::cout << curNode->data << " ";
        }
        
        std::cout << std::endl;
    }
    
    // time: O() space: O()
    int size() {
        
    }
    
    // time: O() space: O()
    void swap(NTreeNode<T>* node1, NTreeNode<T>* node2) {
        
    }
    
    // time: O() space: O()
    void replace(T oldValue, T newValue) {
        
    }
    
    ~NTree() {
        
    }
};

#endif
