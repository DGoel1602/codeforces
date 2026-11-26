#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> a1dp (n+1), b1dp (n+1), a2dp (n+1), b2dp (n+1);
    vector<int> ap (n+2), bp (n+2);
    ap[n+1] = 2e9; bp[n+1] = -2e9;
    for (int i = n; i >= 0; i--) {
        a2dp[i] = max(a[i], bp[i+1]);
        b2dp[i] = min(b[i], ap[i+1]);
        a1dp[i] = max(b2dp[i], bp[i+1]);
        b1dp[i] = min(a2dp[i], ap[i+1]);
        ap[i] = min(a1dp[i], ap[i+1]);
        bp[i] = max(b1dp[i], bp[i+1]);
    }

    cout << a1dp[0] << "\n";
}
