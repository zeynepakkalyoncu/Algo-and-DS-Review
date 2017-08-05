#include <iostream>
#include <string>
#include <sstream>

#include "sort.h"
#include "utils.h"
#include "chapter5.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*vector<int> vec1, vec2;
    string line;
    getline(cin, line);
    istringstream os1(line);
    
    int val;
    while (os1 >> val) vec1.push_back(val);*/
    
    unsigned int a;
    cin >> a;
    print_binary(a);
    print_binary(swap_bits(a));
    
    return 0;
}
