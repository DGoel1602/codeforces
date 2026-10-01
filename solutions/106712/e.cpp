#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> pref(n+1), mxs(n+1);
    for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + s[i-1] - '0';
    int res = 0;
    for(int i = 0; i<n; i++) {
        int cur = pref[min(i+k, n)] - pref[i];
        mxs[i+1] = max(mxs[i], cur);
        if(i - k + 1 >= 0) {
            cur += mxs[i-k+1];
        } else {
            cur += pref[i];
        }
        res = max(res, cur);
    }
    cout << res << '\n';
}
