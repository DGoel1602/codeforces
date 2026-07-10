#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k == 0) {
        for(int i = 0; i < n; i++) cout << 0;
        cout << '\n';
        return;
    }
    if(k == n) {
        for(int i = 0; i < n; i++) cout << 1;
        cout << '\n';
        return;
    }
    cout << 1;
    k--;
    for(int i = 0; i < n-k-2; i++) {
        cout << 0;
    }
    for(int i = 0; i < k; i++) {
        cout << 1;
    }
    cout << 0 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
