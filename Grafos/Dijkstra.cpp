vector<ll> dijkstra(vector<vector<pair<ll,ll>>> G, int n, int s){

    vector<ll> dis(n+1, INF);
    dis[s]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pair<ll,ll> menor = pq.top();
        pq.pop();
        int w = menor.F;
        int nodo = menor.S;
        if(dis[nodo] < w) continue;
        for( auto to : G[nodo]){
            int v = to.F;
            int cost = to.S;
            if(dis[nodo]+cost < dis[v]){
                dis[v] = dis[nodo] + cost;
                pq.push({dis[v],v});
            }
        }
    }
return dis;

}