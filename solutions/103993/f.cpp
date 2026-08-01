#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> dp(n, vector(2, -1));
    auto go = [&](int i, int lid, auto&& go) -> int {
        if(i == n) return 0;
        auto &ref = dp[i][lid];
        if(ref != -1) return ref;
        ref = go(i+1, s[i+1] - '0', go);
        if(lid) 
            return ref = ref + a[i];
        if(i < n-1 && s[i+1] == '1') {
            return ref = max(ref, a[i] + go(i+1, 0, go)); 
        }
        return ref;
    };
    cout << go(0, s[0]-'0', go) << '\n';
}
