const int N = 1e5+5;

vector<int> G[N];
int n, m;

bool onStack[N], visited[N];
int ids[N], low[N], cnt = 1, sccCnt = 0;
stack<int> st;
int sccs[N];

void dfs(int i) {
    st.push(i);
    onStack[i] = 1;
    ids[i] = low[i] = cnt++;

    for (int to : G[i]) {
        if (!visited[to]) {
            visited[to] = 1;
            dfs(to);
        }
        if (onStack[to]) {
            low[i] = min(low[i], low[to]);
        }
    }

    if (ids[i] == low[i]) {
        sccCnt++;
        while (1) {
            int node = st.top(); st.pop();
            onStack[node] = 0;
            sccs[node] = sccCnt;
            if (node == i) break;
        }
    }

}

void findSCC() {
    for (int i=1; i<=n; ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(i);
    }
}