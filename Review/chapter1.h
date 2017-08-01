#ifndef chapter1_h
#define chapter1_h

#include <string>
#include <sstream>

// time: O(n) space: O(n)
bool unique_bit(std::string& s) {
    int ssize = s.size();
    unsigned int seen = 0;
    
    for (int i = 0; i < ssize; i++) {
        if ((seen & (0x1 << (s[i] - '0'))) != 0) {
            return false;
        }
        seen |= 0x1 << s[i];
    }
    
    return true;
}

#include <unordered_set>
// time: O(n) space: O(n)
bool unique_hash(std::string& s) {
    int ssize = s.size();
    std::unordered_set<char> seen;
    
    for (int i = 0; i < ssize; i++) {
        if (seen.find(s[i]) != seen.end()) {
            return false;
        }
        seen.insert(s[i]);
    }
    
    return true;
}

// time: O() space: O()
bool unique_sort(std::string& s) {
    return true;
}

///////////////

// time: O(n) space: O(1)
void reverse(char* s, int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}

// time: O(n) space: O(1)
void reverse_rec(char* s, int i, int j) {
    if (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverse_rec(s, i + 1, j - 1);
    }
}

///////////////

// time: O(n^2) space: O(1)
std::string remove_dup(std::string s) {
    int len = s.size();
    bool dup = false;
    ostringstream os;
    
    for (int i = 0; i < len; i++) {
        
        char c = s[i];
        for (int j = i + 1; j < len; j++) {
            if (s[j] == c) {
                dup = true;
                break;
            }
        }
        
        if (!dup) {
            os << c;
        }
                
        dup = false;
    }
    
    return os.str();
}

///////////////

// time: O(n) space: O(n)
bool anagrams(std::string s1, std::string s2) {
    int len1 = s1.size(), len2 = s2.size();
    
    if (len1 != len2) return false;
    if (len1 == len2 == 0) return true;
    
    int c1[286] = { 0 }, c2[286] = { 0 };
    
    for (int i = 0; i < len1; i++) {
        c1[s1[i] - '0']++;
    }
    
    for (int i = 0; i < len2; i++) {
        c2[s2[i] - '0']++;
    }
    
    for (int i = 0; i < len1; i++) {
        int ind = s1[i] - '0';
        if (c1[ind] != c2[ind]) return false;
    }
    
    return true;
}

///////////////

// time: O(n) space: O(n)
std::string replace(std::string s) {
    int len = s.size();
    ostringstream os;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') os << "%20";
        else os << s[i];
    }
    
    return os.str();
}

// time: O(n) space: O(n)
char* replace_char(char* s) {
    int len = strlen(s);
    int space_count = 0;
    
    for (int i = 0; i < len; i++)
        if (s[i] == ' ') space_count++;
    
    char* s2 = new char[len + space_count * 2 + 1];
    int j = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            s2[j++] = '%';
            s2[j++] = '2';
            s2[j++] = '0';
        }
        else {
            s2[j++] = s[i];
        }
    }
    
    s2[j] = '\0';
        
    return s2;
}

///////////////

// time: O(mn) space: O(m + n)
void set_zeroes(int** mat, int m, int n) {
    bool rows[m], cols[n];
    
    for (int i = 0; i < m; i++) rows[i] = false;
    for (int i = 0; i < n; i++) cols[i] = false;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows[i] || cols[j]) {
                mat[i][j] = 0;
            }
        }
    }
}

///////////////

// time: O(isSubstring) space: O(n)
bool rotation(std::string s1, std::string s2) {
    
    if (s1.size() != s2.size()) return false;
    
    std::string temp = s1 + s1;
    std::size_t found = temp.find(s2);
    return found != std::string::npos;
}

#endif
