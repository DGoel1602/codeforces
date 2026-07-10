#include <bits/stdc++.h>
using namespace std;

vector<int> DX = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> DY = {-1, -1, -1, 0, 0, 1, 1, 1};

int dp[10][10][10][101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(auto &vec: grid) for(auto &x: vec) cin >> x;

    int k; cin >> k;
    string word; cin >> word;
    memset(dp, -1, sizeof(dp));

    auto cnt = [&](int dd, int dlx) -> int {
        return (dlx != -1 && dd != dlx);
    };

    auto inb = [&](int r, int c) -> int {
        return (r >= 0 && r < n && c >= 0 && c < m);
    };
    
    auto go = [&](int r, int c, int dlx, int k, int i, auto&& go) -> int {
        if(i == word.size()) return k == 0;
        if(k < 0) return 0;
        auto &ref = dp[r][c][dlx+1][k][i];
        if(ref != -1) return ref;
        for(int j = 0; j<8; j++) {
            int nr = r + DY[j], nc = c + DX[j];
            if(!inb(nr, nc)) continue;
            if(grid[nr][nc] != word[i]) continue;
            if(go(nr, nc, j, k-cnt(j, dlx), i+1, go)) return ref = 1;
        }
        return ref = 0;
    };

    if(word.size() > 1 && k >= word.size()-1) {
        cout << "NO\n";
        return 0;
    }
    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(grid[i][j] == word[0]) {
                if(go(i, j, -1, k, 1, go)) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";    
}
