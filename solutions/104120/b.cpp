#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    pair<int, int> s, e;
    cin >> s.first >> s.second >> e.first >> e.second;
    --s.first, --s.second;
    --e.first, --e.second;

    vector<vector<int>> g(r, vector<int>(c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) cin >> g[i][j];
    }

    int res = 10;
    for(int m = 0; m < (1 << 10); m++) {
        vector<vector<bool>> avail(r, vector<bool>(c, false));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(m & (1 << (g[i][j]-1))) avail[i][j] = true;
            }
        }
        if(!avail[s.first][s.second] || !avail[e.first][e.second]) continue;

        queue<pair<int, int>> q;
        q.push({s.first, s.second});
        vector<vector<bool>> seen(r, vector<bool>(c, false));
        seen[s.first][s.second] = true;
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int xd = -1; xd <= 1; xd++) {
                for(int yd = -1; yd <= 1; yd++) {
                    if(abs(xd) == abs(yd)) continue;
                    if(x+xd >= 0 && x+xd < r && y+yd >= 0 && y+yd < c) {
                        if(avail[x+xd][y+yd] && !seen[x+xd][y+yd]) {
                            seen[x+xd][y+yd] = true;
                            q.push({x+xd, y+yd});
                        }
                    }
                }
            }
        }

        if(seen[e.first][e.second]) res = min(res, __popcount(m));
    }
    cout << res << '\n';
}
