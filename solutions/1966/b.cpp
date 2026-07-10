#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        bool tr = true, br = true, lc = true, rc = true;
        vector<vector<char>> grid(n, vector<char>(m));
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            for(int j = 0; j < m; j++) {
                grid[i][j] = s[j];
            }
        }
        char c = grid[0][0];
        for(int i = 1; i < m; i++) {
            if(grid[0][i] != c) tr = false;
        }
        c = grid[0][0];
        for(int i = 1; i < n; i++) {
            if(grid[i][0] != c) lc = false;
        }
        c = grid[0][m-1];
        for(int i = 1; i < n; i++) {
            if(grid[i][m-1] != c) rc = false;
        }
        c = grid[n-1][0];
        for(int i = 1; i < m; i++) {
            if(grid[n-1][i] != c) br = false;
        }

        if(tr && br && grid[0][0] != grid[n-1][0]) cout << "NO\n";
        else if(lc && rc && grid[0][0] != grid[0][m-1]) cout << "NO\n";
        else cout << "YES\n";
    }
}
