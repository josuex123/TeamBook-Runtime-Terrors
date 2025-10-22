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
vector<int> bfs(vector<vector<int>>& g , int u,int t) {
    vector<int> dis(g.size(), -1);
    vector<int> parent(g.size(), -1); 
    queue<int> q;
    dis[u] = 0;
    q.push(u);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int v : g[node]) {
            if (dis[v] == -1) { 
                dis[v] = dis[node] + 1;
                parent[v] = node;
                q.push(v);
            }
        }
    }

    if(dis[t] == -1) return {};
    vector<int> path;
    for(int v = t; v != -1; v = parent[v]){
      path.push_back(v);
    }
    reverse(all(path));
    return path;
}