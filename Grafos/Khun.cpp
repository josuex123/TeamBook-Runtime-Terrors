vector<vector<int>> g; 
vector<int> mt;        
vector<bool> used;    

bool try_kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int kuhn(int n1) {
    int match = 0;
    for (int v = 0; v < n1; v++) {
        used.assign(n1, false);
        if (try_kuhn(v))
            match++;
    }
    return match;
}