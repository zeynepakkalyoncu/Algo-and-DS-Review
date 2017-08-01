#ifndef chapter8_h
#define chapter8_h

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



#endif
