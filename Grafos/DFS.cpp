void dfs(int v, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[v] = true;
    for (int u : graph[v]) { 
        if (!visited[u]) {
            dfs(u, visited, graph);
        }
    }
}
bool dfsCiclo(int v,int parent, vector<bool>& visi, vector<vector<int>>& gr){
    visi[v] = true;
    for(int vis : gr[v]){ 
        if(!visi[vis]){
            if(dfsCiclo(vis, v,visi, gr))
                return true;
        }else if(vis != parent){
            return true;
        }
    }
    return false;
}
void tra(int n,vector<vii> G){
vector<vector<pair<ll,ll>>> Trans(n + 1);
    foree(i,1,n){
        for(auto g : G[i]){
            ll v = g.F;
            ll cost = g.S;
            Trans[v].pb({i,cost});
        }
    }
}