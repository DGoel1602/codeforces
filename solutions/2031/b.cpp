#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> p(n), loc(n);
    for(int i = 0; i < n; i++) cin >> p[i], loc[p[i]-1] = i;
    for(int i = 0; i < n; i++) {
        if(abs(loc[i]-i) > 1) return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
