#ifndef chapter8_h
#define chapter8_h

#include <vector>
#include <cmath>

// time: O(2^n)?? space: O()
int fib_rec(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n >= 2) return fib_rec(n - 1) + fib_rec(n - 2);
    else return -1; // error
}

int fib_iter(int n) {
    return -1;
}

///////////////

// time: O(n*2^n) space: O(n*2^n)
vector<vector<int>> power_set(vector<int> nums) {
    int size = nums.size();
    int power_set_size = pow(2, size);
    int counter = 0;
    
    std::vector<vector<int>> res;
    for (int i = 0; i < power_set_size; i++) {
        
        std::vector<int> vec;
        for (int j = 0; j < size; j++) {
            if (counter & (0x1 << j)) {
                vec.push_back(nums[j]);
            }
        }
        
        res.push_back(vec);
    }
    
    return res;
}

///////////////



// time: O(n^(n / 2)) space: O()
void string_perm(string str, vector<string>& res, int i, int n, int index, int k) {
    int len = str.size();
    
}

#endif
