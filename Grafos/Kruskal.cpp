ll kruskal(vector<pair<ll,pair<int,int>>> edges, int n){

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cntAristas = 0;
    ll res = 0;
    for(auto e : edges){
        ll peso = e.first;
        int u = e.S.first;
        int v = e.S.second;
        if(dsu.unionSet(u, v)){
            cntAristas++;
            res += peso;
        }
        if(cntAristas == n-1){
            return res;
        }
    }
    if(cntAristas < n - 1){
        return -1;
    }
    return res;

}