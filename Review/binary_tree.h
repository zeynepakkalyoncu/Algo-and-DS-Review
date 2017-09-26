#ifndef binary_tree_h
#define binary_tree_h

#include "binary_node.h"

#include <queue>

template <typename T>
class BinaryTree {
private:
    BinaryNode<T>* _root;
public:
    BinaryTree() : _root(NULL) {}
    BinaryTree(BinaryNode<T>* root) : _root(root) {}
    
    // time: O(n) space: O()
    int nodeDepth(BinaryNode<T>* node) {
        if (node.isRoot()) return 0;
        else return 1 + nodeDepth(node->_parent);
    }
    
    // time: O(n) space: O()
    int nodeHeight(BinaryNode<T>* node) {
        
    }
    
    // time: O() space: O()
    void preorderTraversal(BinaryNode<T>* node) {
        if (node) {
            std::cout << node->data << " ";
            preorderTraversal(node->_left);
            preorderTraversal(node->_right);
        }
    }
    
    // time: O(n) space: O(n)
    void inorderTraversal(BinaryNode<T>* node) {
        if (node) {
            preorderTraversal(node->_left);
            std::cout << node->data << " ";
            preorderTraversal(node->_right);
        }
    }
    
    // time: O(n) space: O(n)
    void inorderTraversalIterative(BinaryNode<T>* node) {
        stack<BinaryNode<T>*> s;
        BinaryNode<T>* curNode = node;
        bool done = false;
        
        while (!done) {
            if (curNode != nullptr) {
                s.push(curNode);
                curNode = curNode->left;
            }
            else {
                if (!s.empty()) {
                    // backtrack to parent
                    curNode = s.top();
                    s.pop();
                    std::cout << curNode->data << " ";
                    curNode = curNode->right;
                }
                else done = true;
            }
        }
    }
    
    // time: O() space: O()
    void postorderTraversal(BinaryNode<T>* node) {
        if (node) {
            preorderTraversal(node->_left);
            preorderTraversal(node->_right);
            std::cout << node->data << " ";
        }
    }
    
    // time: O(n) space: O(n)
    void levelorderTraversalWithQueue(BinaryNode<T>* node) {
        queue<BinaryNode<T>* > q;
        q.push(node);
        
        while (!q.empty()) {
            BinaryNode<T>* curNode = q.pop();
            q.push(curNode->_left); q.push(curNode->_right);
            std::cout << curNode->_data << " ";
        }
        
        std::cout << std::endl;
    }
    
    // time: O(n) space: O(1) - skewed tree
    void printLevel(BinaryNode<T>* node, int level) {
        if (node) {
            if (level == 1) std::cout << node->_data << " ";
            else if (level > 1) {
                printLevel(node->_left, level - 1);
                printLevel(node->_height, level - 1);
            }
        }
    }
    
    // time: O(n^2) space: O(1) - skewed tree
    void levelorderTraversalWithHelper(BinaryNode<T>* node) {
        int height = nodeHeight(node);
        for (int i = 1; i <= height; i++) {
            printLevel(node, i);
        }
    }
    
    // time: O(n) space: O(n)
    void printLevels(BinaryNode<T>* node) {
        queue<BinaryNode<T>*> q;
        q.push(node);
        
        while (!q.empty()) {
            int levelCount = q.size();
            
            if (levelCount > 0) {
                while (levelCount) {
                    BinaryNode<T>* front = q.pop();
                    std::cout << front->data << " ";
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                    levelCount--;
                }
                std::cout << std::endl;
            }
        }
    }
    
    // time: O() space: O()
    bool isBSTMinMax(BinaryNode<T>* node, int min, int max) {
        
    }
    
    // time: O(n) space: O(1)
    bool isBSTInOrder(BinaryNode<T>* node) {
        static BinaryNode<T>* previous = NULL;
        
        if (node) {
            if (!isBSTInOrder(node->_left)) return false;
            if (previous && (node->_data > previous->_data)) return false;
            
            previous = node;
            
            return isBSTInOrder(node->right);
        }
    }
    
    // time: O() space: O()
    int size() {
        
    }
    
    // time: O() space: O()
    void swap(BinaryNode<T>* node1, BinaryNode<T>* node2) {
        
    }
    
    // time: O() space: O()
    void replace(T oldValue, T newValue) {
        
    }
    
    ~BinaryTree() {
        
    }
};

#endif
