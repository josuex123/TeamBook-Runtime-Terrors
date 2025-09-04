void dfs(int v, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[v] = true;
    for (int u : graph[v]) { 
        if (!visited[u]) {
            dfs(u, visited, graph);
        }
    }
}
