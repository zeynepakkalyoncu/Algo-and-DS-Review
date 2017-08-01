#ifndef ntree_node_h
#define ntree_node_h

#include <vector>

template <typename T>
class NTreeNode {
private:
    T _data;
    NTreeNode<T>* _parent;
    std::vector<NTreeNode<T>* >& _children;
public:
    
    NTreeNode() : _parent(NULL) {}
    NTreeNode(T data) : _data(data), _parent(NULL) {}
    NTreeNode(T data, NTreeNode<T>* parent) : _data(data), _parent(parent) {}
    
    NTreeNode<T>* parent() {
        return _parent;
    }
    
    std::vector<NTreeNode<T>* >& children() {
        return _children;
    }
    
    bool isLeaf() {
        return _children.empty();
    }
    
    bool isInternal() {
        return !_children.empty();
    }
    
    bool isRoot() {
        return _parent == NULL;
    }
    
    ~NTreeNode() {
        if (_parent) delete _parent;
    }
};

#endif
