#ifndef dp_h
#define dp_h

// time: O(wv) space: O(wv)
int binary_knapsack(vector<int> weights, vector<int> values, int total_weight) {
    int count = weights.size();
    
    int K[count][total_weight];
    
    for (int i = 0; i < count; i++) K[i][0] = 0;
    
    for (int i = 0; i < count; i++) {
        for (int w = 1; w < total_weight; w++) {
            if (w < weights[i]) {
                K[i][w] = K[i][w - 1];
            }
            else {
                K[i][w] = std::max(K[i - 1][w], // exclude
                                   values[i] + K[i - 1][w - values[i]]); // include
            }
        }
    }
    
    return K[count - 1][total_weight - 1];
}

///////////////

#include <string>

// time: O(nm) space: O(nm)
int longest_common_subsequence(std::string s1, std::string s2) {
    int size1 = s1.size(), size2 = s2.size();
    int LCS[size1 + 1][size2 + 2];
    
    for (int i = 0; i <= size1; i++) LCS[i][0] = 0;
    for (int i = 1; i <= size2; i++) LCS[0][i] = 0;
    
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                LCS[i][j] = 1 + LCS[i][j - 1];
            }
            else {
                LCS[i][j] = std::max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    
    return LCS[size1][size2];
}

#uninclude <string>

#endif
