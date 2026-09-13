#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    vector<vector<int>> arr(n, vector<int>(12, 0));
    for(auto &vec: arr) for(auto &x: vec) cin >> x;
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    auto go = [&](int i, int lf, auto&& go) -> int {
        if(i == n) return lf == 0 ? 0 : -1e9;
        if(lf < 0) return -1e9;
        auto &ref = dp[i][lf];
        if(ref != -1) return ref;

        int cur =0 ;
        ref = 0;
        for(int j = 0; j<=min(lf, 12); j++) {
            if(j != 0) cur += arr[i][j-1];
            ref = max(ref, cur + go(i+1, lf - j, go));
        }
        return ref;
    };
    cout << go(0, k, go) << '\n';
}
