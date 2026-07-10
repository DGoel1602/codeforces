#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> res(n, 0);
    --x; --y;
    for(int i = y; i<=x; i++) res[i] = 1;
    int par = 0;
    for(int i = y-1; i>=0; i--) {
        if(par) res[i] = 1;
        else res[i] = -1;
        par ^= 1;
    }
    par = 0;
    for(int i = x+1; i<n; i++) {
        if(par) res[i] = 1;
        else res[i] = -1;
        par ^= 1;
    }
    for(int x: res) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
