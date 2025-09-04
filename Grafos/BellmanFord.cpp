vector<int> bellmanFord(int n, vector<vector<pair<int,int>>> &G, int src) {
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            if (dist[u] == INF) continue;
            for (auto [v, w] : G[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        if (dist[u] == INF) continue;
        for (auto [v, w] : G[u]) {
            if (dist[u] + w < dist[v]) {
                return {}; 
            }
        }
    }

    return dist;
}