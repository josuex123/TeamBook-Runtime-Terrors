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
bool esBipartito(vector<vector<int>>& grafo, int n) {
    vector<int> color(n, 0); // 0 = no coloreado, 1 y 2 = colores
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : grafo[u]) {
                    if (color[v] == 0) {
                        color[v] = 3 - color[u]; // alterna entre 1 y 2
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // hay conflicto de colores
                    }
                }
            }
        }
    }
    return true;
}