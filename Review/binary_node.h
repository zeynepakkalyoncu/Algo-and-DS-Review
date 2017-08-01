#ifndef binary_node_h
#define binary_node_h

template <typename T>
class BinaryNode {
private:
    T _data;
    BinaryNode<T>* _left, *_right;
public:
    
    BinaryNode() : _parent(NULL) {}
    BinaryNode(T data) : _data(data), _parent(NULL) {}
    BinaryNode(T data, BinaryNode<T>* parent) : _data(data), _parent(parent) {}
    
    BinaryNode<T>* parent() {
        return _parent;
    }
    
    BinaryNode<T>* left() {
        return _left;
    }
    
    BinaryNode<T>* right() {
        return _right;
    }
    
    bool isLeaf() {
        return !_left && !_right;
    }
    
    bool isInternal() {
        return _left || _right;
    }
    
    bool isRoot() {
        return _parent == NULL;
    }
    
    ~BinaryNode() {
        if (_parent) delete _parent;
        if (_left) delete _left;
        if (_right) delete _right;
    }
};

#endif
