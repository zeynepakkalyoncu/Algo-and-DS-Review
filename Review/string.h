#ifndef string_h
#define string_h

#include <string>
#include <iostream>
#include <vector>

// time: O(m(n - m + 1)) = O(mn) space: O(1)
void naive_sm(std::string txt, std::string pat) {
    int n = txt.size(), m = pat.size();
    for (int i = 0; i <= n - m; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (pat[j] != txt[i + j]) { // mismatch
                flag = false;
                break;
            }
        }
        if (flag) std::cout << "Found pattern at index " << i << std::endl;
    }
}

///////////////

const int d = 256;

// worst time: O(m(n - m + 1)) = O(mn) space: O(1)
// avg time: O(m + n) space: O(1)
void rabin_karp_sm(std::string txt, std::string pat) {
    int p = 0, t = 0, h = 1, n = txt.size(), m = pat.size();
    int q = 101;
    
    for (int i = 0; i < m - 1; i++) h = (d * h) % q;
    
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            // hash values match
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (pat[j] != txt[i + j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) std::cout << "Found pattern at index " << i << std::endl;
        }
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            while (t < 0) t += q;
        }
    }
}

///////////////

// time: O(m) space: O(m)
void computeLPS(std::string pat, vector<int>& lps) {
    int m = pat.size();
    int i = 1, j = 0;
    lps[0] = 0;
    
    while (i < m) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) j = lps[j - 1];
            else {
                lps[i] = 0;
                j++;
            }
        }
    }
}

// time: O(n + m) space: O(m)
void kmp_sm(std::string txt, std::string pat) {
    int n = txt.size(), m = pat.size();
    int i = 0, j = 0; // indices for txt and pat respectively
    std::vector<int> lps(m);
    computeLPS(pat, lps);
    
    while (i < n) {
        if (txt[i] == pat[j]) { i++; j++; }
        if (j == m) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if ((i < n) && (txt[i] != pat[j])) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

///////////////

// time: O(md) space: O(md)
void computeTF(std::string pat, vector<vector<int>>& tf) {
    int m = pat.size();
    int lps = 0;
    
    for (int i = 0; i < d; i++) tf[0][i] = 0;
    tf[0][pat[0]] = 1;
    
    for (int i = 1; i <= m; i++) {
        tf[i] = tf[lps];
        tf[i][pat[i]] = i + 1;
        lps = tf[lps][pat[i]];
    }
}

// time: O(md + n) space: O(md)
void finite_automata_sm(std::string txt, std::string pat) {
    int n = txt.size(), m = pat.size();
    vector<vector<int>> tf(m + 1);
    for (int i = 0; i <= m; i++) tf[i] = vector<int>(d);
        
    computeTF(pat, tf);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = tf[j][txt[i]];
        if (j == m) std::cout << "Found pattern at index " << i - m + 1 << std::endl;
    }
}

#endif
