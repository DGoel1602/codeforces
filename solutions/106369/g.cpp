#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

signed main() {
    int r, c; cin >> r >> c;
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(1 << 11, -1)));
    auto nx = [&](int i, int j) -> pair<int, int> {
        if(i == r - 1) return {0, j+1};
        return {i+1, j};
    };
    vector<int> dl = {0, r - 2, r - 1, r};
    auto go = [&](int i, int j, int ls, auto&& go) -> int {
        if(j == c) {
            return 1;
        }
        bool allow = true;
        if(i != 0 || (r == 2)) allow = allow && (((ls >> dl[0]) & 1) == 0);
        if(j != 0 && i != r - 1) allow = allow && (((ls >> dl[1]) & 1) == 0);
        if(j != 0) allow = allow && (((ls >> dl[2]) & 1) == 0);
        if(j != 0 && i != 0) allow = allow && (((ls >> dl[3]) & 1) == 0);

        auto &ref = dp[i][j][ls];
        if(ref != -1) return ref;
        
        ref = 0;
        auto [ni, nj] = nx(i, j);
        if(allow) {
            ref = (ref + go(ni, nj, ((ls << 1) & ((1 << (r + 1)) - 1)) | 1, go)) % mod;
        }
        ref = (ref + go(ni, nj, ((ls << 1) & ((1 << (r + 1)) - 1)), go)) % mod;

        return ref;
    };

    cout << go(0, 0, 0, go) << '\n';
}

// sqrt(x^2 + m^2x^2 + b^2 + 2mxb)
// sqrt(x^2(1 + m^2) + b^2 - 2mxb)
// 2x(1 + m^2) - 2mb

// 011 
// 000
