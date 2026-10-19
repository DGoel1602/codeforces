#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> g1(r), g2(r);
    for(int i = 0; i < r; i++) cin >> g1[i];
    for(int i = 0; i < r; i++) cin >> g2[i];

    auto ind = [&](int x, int y) -> int { return x*c + y; };
    auto coord = [&](int x) -> pair<int, int> { return {x/c, x%c}; };

    int s1, s2, e;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(g1[i][j] == 'S') s1 = ind(i, j);
            if(g2[i][j] == 'S') s2 = ind(i, j);
            if(g2[i][j] == 'D') e = ind(i, j);
        }
    }

    vector<vector<int>> dp(r*c, vector<int>(r*c, -1));
    dp[s1][s2] = 0;   
    queue<pair<int, int>> q;
    q.push({s1, s2});

    vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    while(!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        auto [x1, y1] = coord(a);
        auto [x2, y2] = coord(b);

        for(int k = 0; k < 4; k++) {
            if(x1+dx[k] < 0 || x1+dx[k] >= r || y1+dy[k] < 0 || y1+dy[k] >= c) continue;
            if(g1[x1+dx[k]][y1+dy[k]] == 'X') continue;
            int nx1 = x1 + dx[k], ny1 = y1 + dy[k];

            int move = (x2+dx[k] >= 0 && x2+dx[k] < r && y2+dy[k] >= 0 && y2+dy[k] < c);
            if(move) move = (g2[x2+dx[k]][y2+dy[k]] != 'X');
            int nx2 = x2 + move*dx[k], ny2 = y2 + move*dy[k];

            int p1 = ind(nx1, ny1), p2 = ind(nx2, ny2);
            if(dp[p1][p2] != -1) continue;
            dp[p1][p2] = dp[a][b] + 1;
            q.push({p1, p2});
        }
    }

    int res = -1;
    for(int i = 0; i < r*c; i++) {
        if(dp[i][e] != -1) {
            if(res == -1) res = dp[i][e];
            else res = min(res, dp[i][e]);
        }
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
