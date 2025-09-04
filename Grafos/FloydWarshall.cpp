vector<vector<ll>> floydWarshall(vector<vector<pair<ll,ll>>> G, int n){

    vector<vector<ll>> dis(n+1, vector<ll>(n+1,INF));
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
    }
    for(int u = 1; u <= n; ++u){
        for(auto to : G[u]){
            ll v = to.F, w = to.S;
            dis[u][v] = min(dis[u][v],w);
            dis[v][u] = min(dis[v][u],w);
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int u = 1; u <= n; ++u){
            for(int v = 1; v <= n; ++v){
                dis[u][v] = min(dis[u][v],dis[u][k]+dis[k][v]);
            }
        }
    }
    
    return dis;
}