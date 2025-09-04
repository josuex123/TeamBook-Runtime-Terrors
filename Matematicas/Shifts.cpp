inline long long shiftLeft(long long num, int k, int n) {
    k %= n;
    return (num << k) & ((1LL << n) - 1);
}

// Shift lógico a la derecha
inline long long shiftRight(long long num, int k, int n) {
    k %= n;
    return (num >> k) & ((1LL << n) - 1);
}

// ===== ROTATE =====

// Rotación circular a la izquierda
inline long long rotateLeft(long long num, int k, int n) {
    k %= n;
    return ((num << k) | (num >> (n - k))) & ((1LL << n) - 1);
}

// Rotación circular a la derecha
inline long long rotateRight(long long num, int k, int n) {
    k %= n;
    return ((num >> k) | (num << (n - k))) & ((1LL << n) - 1);
}
