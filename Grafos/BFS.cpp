vector<int> bfs(vector<vector<int>>& g , int u) {
    vector<int> dis(g.size(), -1); 
    queue<int> q;
    dis[u] = 0;
    q.push(u);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int v : g[node]) {
            if (dis[v] == -1) { 
                dis[v] = dis[node] + 1;
                q.push(v);
            }
        }
    }
    return dis;
}