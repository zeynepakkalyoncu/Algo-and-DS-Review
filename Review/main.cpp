#include <iostream>
#include <string>
#include <sstream>

#include "utils.h"

#include "priority_queue.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*vector<int> vec1, vec2;
    string line;
    getline(cin, line);
    istringstream os1(line);
    
    int val;
    while (os1 >> val) vec1.push_back(val);*/
    
    PriorityQueue pq(5);
    pq.print_pq();
    
    pq.insert(4);
    pq.insert(2);
    pq.insert(1);
    pq.print_pq();
    
    pq.insert(3);
    pq.insert(5);
    pq.print_pq();
    
    cout << pq.extract_max() << endl;
    pq.print_pq();
    
    return 0;
}
