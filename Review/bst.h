#ifndef bst_h
#define bst_h

#include "binary_node.h"

template <typename T>
class BST : BinaryTree {
private:
    BST<T>* _root;
public:
    BST() : _root(NULL) {}
    BST(BinaryNode<T>* root) : _root(root) {}
    
    void insertNode(BinaryNode<T>* node, T val) {
        if (!node) node = new BinaryNode<T>(val);
        else if (node->_data > val) insert(node->_left, val);
        else if (node->_data < val) insert(node->_right, val);
    }
    
    BinaryNode<T>* find(BinaryNode<T>* node, T val) {
        if (!node || node->_data == val) return node;
        else if (node->_data > val) return find(node->_left, val);
        else return find(node->_right, val);
    }
    
    // time: O(h) space: O(1)
    BinaryNode<T>* inorderSuccessor(BinaryNode<T>* node) {
        if (node->_right) {
            BinaryNode<T>* minNode = node->_right;
            while (minNode->_left != NULL) minNode = minNode->_left;
            return minNode;
        }
        else {
            BinaryNode<T>* successor = NULL, *ancestor = _root;
            while (node->_data != ancestor->_data) {
                if (node->_data < ancestor->_data) {
                    successor = ancestor;
                    ancestor = ancestor->_left;
                }
                else if (node->_data > ancestor->_data) {
                    ancestor = ancestor->_right;
                }
            }
            return successor;
        }
    }
    
    
    BinaryNode<T>* inorderPredessor(BinaryNode<T>* node) {
        if (node->_left) {
            return node->_left;
        }
        else {
            BinaryNode<T>* predecessor = NULL, *ancestor = _root;
            while (ancestor->_data != node->_data) {
                if (node->_data > ancestor->_data) {
                    predecessor = ancestor;
                    ancestor = ancestor->_right;
                }
                else {
                    ancestor = ancestor->_left;
                }
            }
            return predecessor;
        }
    }
    
    // time: O(h) space: O()
    BinaryNode<T>* deleteNode(BinaryNode<T>* node, T val) {
        if (!node) return node;
        else {
            if (val < node->_data) {
                node->_left = deleteNode(node->_left, val);
            }
            else if (val > node->_data) {
                node->_right = deleteNode(node->_right, val);
            }
            else {
                if (!node->_left && !node->_right) {
                    delete node;
                    return NULL;
                }
                else if (!node->_left && node->_right) {
                    BinaryNode<T>* childNode = node->_right;
                    delete node;
                    return childNode;
                }
                else if (node->_left && !node->_right) {
                    BinaryNode<T>* childNode = node->_left;
                    delete node;
                    return childNode;
                }
                else {
                    BinaryNode<T>* successor = inorderSuccessor(node);
                    node->_data = successor->_data;
                    node->_right = deleteNode(node->_right, successor->_data);
                }
            }
            return node;
        }
    }
    
    ~BST() {
        
    }
};

#endif
