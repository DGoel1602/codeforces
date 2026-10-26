#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    vector<vector<ll>> pf(n+1, vector<ll>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> pf[i][j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) pf[i][j] += (pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1]);
    }

    ll sum = 0;
    int ls = n - k + 1, ts = m - l + 1;
    for(int i = 1; i<=k; i++) {
        for(int j = 1; j<=l; j++) {
            ll cur = pf[i + ls - 1][j + ts - 1] - pf[i-1][j + ts - 1] - pf[i+ls-1][j-1] + pf[i-1][j-1];
            sum += abs(cur);
        }
    }
    cout << sum << '\n';
}
