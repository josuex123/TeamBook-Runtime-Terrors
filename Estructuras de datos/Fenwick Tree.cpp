const int N = 2e5 + 5;

int T[N];

int query(int i){
    int r = 0;
    while(i > 0){
        r += T[i];
        i -= i & -i;
    }
    return r;
}

void add(int i, int val){
    while(i < N){
        T[i] += val;
        i += i & -i;
    }
}