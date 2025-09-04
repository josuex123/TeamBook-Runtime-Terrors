inline long long shiftLeft(long long num, int k, int n) {
    k %= n;
    return (num << k) & ((1LL << n) - 1);
}

inline long long shiftRight(long long num, int k, int n) {
    k %= n;
    return (num >> k) & ((1LL << n) - 1);
}

inline long long rotateLeft(long long num, int k, int n) {
    k %= n;
    return ((num << k) | (num >> (n - k))) & ((1LL << n) - 1);
}

inline long long rotateRight(long long num, int k, int n) {
    k %= n;
    return ((num >> k) | (num << (n - k))) & ((1LL << n) - 1);
}
