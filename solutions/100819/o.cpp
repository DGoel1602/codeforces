#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(string &x: grid) cin >> x;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[0][0] = 1;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        int diff = grid[i][j] - '0';
        int ni = i - diff, nj = j;
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
            q.push({ni, nj});
            vis[ni][nj] = vis[i][j] + 1;
        }
        ni = i + diff, nj = j;
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
            q.push({ni, nj});
            vis[ni][nj] = vis[i][j] + 1;
        }
        ni = i, nj = j - diff;
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
            q.push({ni, nj});
            vis[ni][nj] = vis[i][j] + 1;
        }
        ni = i, nj = j + diff;
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
            q.push({ni, nj});
            vis[ni][nj] = vis[i][j] + 1;
        }
    }
    if(vis[n-1][m-1] == 0) cout << "IMPOSSIBLE\n";
    else cout << vis[n-1][m-1] - 1 << '\n';
}
