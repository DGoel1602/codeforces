#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> DX = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
vector<int> DY = {-1, 0, 1, -1, 0, 1, -1, 0, 1};


using pii = pair<int, int>;
pii add(pii a, pii b) {
    int g = __gcd(a.second, b.second);
    pii res = {0, 0};
    res.first = (a.first * b.second / g) + (b.first * a.second / g);
    res.second = (a.second * b.second) / g;
    return res;
}

signed main(){
    int n, m, b; cin >> m >> n >> b;
    vector<vector<pii>> grid(n, vector<pii>(m, {0, 1}));
    for(auto &vec: grid) for(auto &x: vec) cin >> x.first;
    for(int _ = 0; _<b; _++) {
        vector<vector<pii>> g2(n, vector<pii>(m, {0, 1}));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                for(int d = 0; d<9; d++) {
                    int ni = i + DX[d], nj = j + DY[d];
                    if(ni < 0) ni = n + ni;
                    if(ni >= n) ni = ni - n;
                    if(nj < 0) nj = m + nj;
                    if(nj >= m) nj = nj - m;
                    g2[i][j] = add(g2[i][j], {grid[ni][nj].first, grid[ni][nj].second * 9});
                }
            }
        }
        swap(g2, grid);
    }

    set<pair<int, int>> s;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) s.insert(grid[i][j]);
    }
    cout << s.size() << '\n';
}
