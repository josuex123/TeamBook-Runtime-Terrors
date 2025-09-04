vector<int> topologicalSort(int n, vector<vector<int>> &G) {
    vector<int> indeg(n, 0), topo;
    queue<int> q;

    for (int u = 0; u < n; u++) {
        for (int v : G[u]) {
            indeg[v]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);

        for (int v : G[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)topo.size() != n) {
        return {}; 
    }

    return topo;
}