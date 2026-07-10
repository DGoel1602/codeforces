#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<vector<int>> dp(n+1, vector(3, -1));
    auto go = [&](int i, int j, auto&& go) -> int {
        if(i >= n) return 0;
        auto &ref = dp[i][j+1];
        if(ref != -1) return ref;

        if(i % 3 == 0 && j == 0) {
            int frv = (s[i] == 'A') + (t[i] == 'A');
            int ct = (frv + (s[i+1] == 'A')) >= 2;
            int cb = (frv + (t[i+1] == 'A')) >= 2;
            ref = max(ref, go(i+1, 1, go) + cb);
            ref = max(ref, go(i+2, -1, go) + ct);
        }

        if(j != 0) {
            int tp = i, bp = i + j;
            int tri = 0;
            if(bp < tp) tri += t[bp] == 'A', bp++;
            else tri += s[tp] == 'A', tp++;
            tri += s[tp] == 'A';
            tri += t[bp] == 'A';
            ref = (tri >= 2) + go(tp+1, 0, go);
        }

        int tp = i, bp = i + j;
        if(max(tp, bp) + 2 <= n-1) {
            int top = (s[tp] == 'A') + (s[tp+1] == 'A') + (s[tp+2] == 'A');
            int bot = (t[bp] == 'A') + (t[bp+1] == 'A') + (t[bp+2] == 'A');
            ref = max(ref, go(i+3, j, go) + (top >= 2) + (bot >= 2));
        }
        return ref;
    };
    cout << go(0, 0, go) << "\n";      
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

/*

1
6
JAJAJJ
JJAJAJ
4 1 1
4 1 1
3 0 2
3 0 2
1 1 3
1 1 3
0 0 3
0 0 3
3

*/
