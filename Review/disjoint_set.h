#ifndef disjoint_set_h
#define disjoint_set_h

class DisjointSet {
private:
    int* _id;
    int* _size;
    int _count;
public:
    DisjointSet(int size) {
        _id = new int[size];
        _size = new int[size];
        _count = size;
        
        for (int i = 0; i < _count; i++) {
            // create _count number of sets of size 1
            _id[i] = i;
            _size[i] = 1;
        }
    }
    
    // time: O(n) space: O(1)
    int find(int x) {
        int root = x;
        while (root != _id[root]) {
            // follow parent to find root
            root = _id[root];
        }
        
        // path compression
        // set the parent of each visited to root
        while (x != root) {
            int temp = _id[x];
            _id[x] = root;
            x = temp;
        }
        
        return root;
    }
    
    // time: O(lgn) space: O(1)
    void union_sets(int id1, int id2) {
        // find roots of given ids
        int root1 = find(id1);
        int root2 = find(id2);
        
        if (root1 != root2) {
            // weighted union: point smaller tree to the other's root
            if (_size[root1] < _size[root2]) {
                _id[root1] = root2;
                _size[root2] += _size[root1];
            }
            else {
                _id[root2] = root1;
                _size[root1] += _size[root2];
            }
            _count--;
        }
    }
    
    ~DisjointSet() {
        if (_id) delete _id;
        if (_size) delete _size;
    }
};

#endif
