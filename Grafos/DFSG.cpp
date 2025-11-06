
int n, m;
vector<vector<bool>> vis;
vector<string> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};
void dfs(int x, int y) {
    vis[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            !vis[nx][ny] && grid[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }
}

void dfs8(int x, int y) {
    vis[x][y] = true;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx8[k];
        int ny = y + dy8[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            !vis[nx][ny] && grid[nx][ny] != '#') {
            dfs8(nx, ny);
        }
    }
}