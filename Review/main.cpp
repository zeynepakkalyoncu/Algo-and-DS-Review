#include <iostream>
#include <string>
#include <sstream>

#include "sort.h"
#include "utils.h"
#include "chapter8.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*vector<int> vec1, vec2;
    string line;
    getline(cin, line);
    istringstream os1(line);
    
    int val;
    while (os1 >> val) vec1.push_back(val);*/
    
    cout << fib_rec(1) << " " << fib_rec(2) << " " << fib_rec(3) << " " << fib_rec(4) << endl;
    
    return 0;
}
