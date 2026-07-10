#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;

    int res = 0;
    for(int i = 0; i<n; i++) {
        if(a[i] >= b[i]) res += a[i] - b[i];
        else {
            res = 1e9;
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res2 = 0;
    for(int i = 0; i<n; i++) {
        if(a[i] >= b[i]) res2 += a[i] - b[i];
        else {
            cout << "-1\n";
            return;
        }
    }
    cout << min(res, res2 + c) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
