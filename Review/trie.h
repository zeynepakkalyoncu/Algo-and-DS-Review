#ifndef trie_h
#define trie_h

#include <string>
#include <map>
#include <vector>

#include <iostream>

struct TrieNode {
    char c;
    std::map<char, TrieNode*> children;
};

class Trie {
private:
    TrieNode root;
    std::vector<TrieNode*> nodes;
public:
    Trie() {
        root = new TrieNode();
        nodes.push_back(root);
    }
    
    void insert(std::string s) {
        std::map<char, TrieNode*>* current_tree = &head.children;
        std::map<char, TrieNode*>::iterator it;
        
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            
            if ((it = current_tree->find(ch)) != current_tree->end()) {
                // child with current character already exists
                current_tree = &it->second->children;
                continue;
            }
            
            if (it == current_tree->end()) {
                // need to add new child with current character
                TrieNode* newNode = new TrieNode();
                newNode->c = ch;
                (*current_tree)[ch] = new_node;
                
                // move to child to insert rest of word s
                current_tree = &new_node->children;
                
                nodes.push_back(new_node);
            }
        }
    }
    
    bool search(std::string s) {
        std::map<char, TrieNode*> currentTree = head.children;
        std::map<char, TrieNode*>::iterator it;
        
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if ((it = current_tree.find(s[i])) == current_tree.end()) {
                // branch doesn't exist
                return false;
            }
            current_tree = it->second->children;
        }
        
        return true;
    }
    
    /*int countPrefixes(std::string p) {
        
    }
    
    int countWords(std::string s) {
        
    }*/
    
    void print_tree(std::map<char, TrieNode*> tree) {
        if (!tree.empty()) {
            for (std::map<char, TrieNode*>::iterator it = tree.begin(); it != tree.end(); it++) {
                std::cout << it->first << endl;
                print_tree(it->second->children);
            }
        }
    }
    
    void print() {
        std::map<char, TrieNode*> current_node = head.children;
        print_tree(current_tree);
    }
    
    ~Trie() {
        int size = nodes.size();
        for (int i = 0; i < size; i++) {
            if (nodes[i]) delete nodes[i];
        }
    }
};

#endif
