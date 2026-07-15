#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, cur = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) cur++;
        else cur = 1;
        res = max(res, cur);
    }
    cout << n-res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
