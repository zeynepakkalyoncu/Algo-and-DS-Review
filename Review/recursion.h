#ifndef recursion_h
#define recursion_h

void towers_of_hanoi(int n, string s, string i, string t) {
    if (n == 1) {
        std::cout << "Moved peg from " + s + " to " + i << std::endl;
        return;
    }
    towers_of_hanoi(n - 1, s, i, t);
    towers_of_hanoi(1, s, t, i);
    towers_of_hanoi(n - 1, i, s, t);
}

#endif
