vector<ll> dijkstra(vector<vector<pair<ll,ll>>> G, int n, int s){

    vector<ll> dis(n+1, INF);
    dis[s]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pair<ll,ll> menor = pq.top();
        pq.pop();
        int w = menor.first;
        int nodo = menor.second;
        if(dis[nodo] < w) continue;
        for( auto to : G[nodo]){
            int v = to.first;
            int cost = to.second;
            if(dis[nodo]+cost < dis[v]){
                dis[v] = dis[nodo] + cost;
                pq.push({dis[v],v});
            }
        }
    }
return dis;

}