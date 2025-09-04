void reduceFraction(int a, int b, int& n, int& d) {
    int g = gcd(a, b);
    n = a / g;
    d = b / g;
}
