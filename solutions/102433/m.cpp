#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    auto inbound = [&](int x, int y, int xb, int yb) -> bool {
        return (x >= 0 && x < xb && y >= 0 && y < yb);
    };

    vector<vector<int>> rg(2*n, vector<int>(2*m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '/') {
                rg[2*i+1][2*j] = rg[2*i][2*j+1] = 1;
            }
            if(g[i][j] == '\\') {
                rg[2*i][2*j] = rg[2*i+1][2*j+1] = 1;
            }
        }
    }

    int cmp = 0;
    queue<pair<int, int>> q;
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < 2*m; j++) {
            if(rg[i][j] == 1) continue;
            cmp++;
            q.push({i, j}); rg[i][j] = 1;

            bool edge = false;

            while(!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                if(x == 0 || x == 2*n-1 || y == 0 || y == 2*m-1) edge = true;

                for(int k = 0; k < 4; k++) {
                    if(!inbound(x+dx[k], y+dy[k], 2*n, 2*m)) continue;
                    if(rg[x+dx[k]][y+dy[k]] == 1) continue;
                    rg[x+dx[k]][y+dy[k]] = 1;
                    q.push({x+dx[k], y+dy[k]});
                }
            }
            if(edge) cmp--;
        }
    }
    
    cout << cmp << endl;
}
