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
    
    unsigned int m, n, i, j;
    cin >> n >> m >> i >> j;
    print_binary(n); print_binary(m); print_binary(i); print_binary(j);
    
    print_binary(copy_inside(n, m, i, j));
    
    return 0;
}
