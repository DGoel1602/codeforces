#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int l = -1;
    bool b = true;
    for(int i = 0; i<n; i++) {
        if(l > a[i]) b = false;
        l = a[i];
    }
    cout << (b ? a.size() : 1) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
