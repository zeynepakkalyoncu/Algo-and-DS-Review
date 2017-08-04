#include <iostream>
#include "utils.h"
#include <cmath>

int compute_parity_1(unsigned long x) {
    unsigned int c;
    for (c = 0; x; c++) {
        x = (x & (x - 1)) >> 1;
    }
    
    if (c % 2 == 0) return 0;
    else return 1;
}

int compute_parity_2(unsigned long x) {
    int c = 0;
    
    while (x) {
        c ^= x & 0x1;
        x >>= 1;
    }
    
    return c;
}

////

unsigned long swap_bits_1(unsigned long x, unsigned short i, unsigned short j) {
    if ((i >= 0) && (i <= 63) && (j >= 0) && (j <= 63)) {
        if (i == j) return x;
        unsigned long mask = (((x >> i) & 0x1) << j) | (((x >> j) & 0x1) << i);
        print_binary_long(mask);
        return (x & ~((0x1 << i) | (0x1 << j))) | mask;
    }
    
    return 0;
}

unsigned long swap_bits_2(unsigned long x, unsigned short i, unsigned short j) {
    if ((i >= 0) && (i <= 63) && (j >= 0) && (j <= 63)) {
        unsigned long index_bits = ((x >> i) & 0x1) ^ ((x >> j) & 0x1);
        unsigned long mask = (index_bits << i) | (index_bits << j);
        x ^= mask;
    }
    
    return x;
}

////

// O(n * 2^n)
void power_set(vector<int> set) {
    size_t set_size = set.size();
    int power_set_size = pow(2, set_size);
    
    for (int i = 0; i < power_set_size; i++) {
        int j = 0;
        for (; j < set_size; j ++) {
            if ((i & (0x1 << j)) != 0) {
                /*
                if (j != 0) {
                    cout << ",";
                }
                 */
                cout << set[j];
            }
        }
        cout << endl;
    }
}

////

int stringToInt(string str) {
    int num = 0;
    bool neg = false;
    size_t len = str.size();
    
    if (str[0] == '-') {
        len--;
        neg = true;
        str = str.substr(1, len);
    }
    
    for (int i = 0; i < len; i++) {
        int digit = str[len - 1 - i] - '0';
        num += digit * pow(10, i);
    }
    
    if (neg) {
        num *= -1;
    }
    
    return num;
}

string intToString(int num) {
    string str = "";
    bool neg = num < 0;
    
    if (num == 0) return "0";
    
    if (neg) {
        num *= -1;
    }
    
    while (num > 0) {
        char digit = num % 10 + '0';
        num = num / 10;
        str = digit + str;
    }
    
    if (neg) {
        str = "-" + str;
    }
    
    return str;
}
