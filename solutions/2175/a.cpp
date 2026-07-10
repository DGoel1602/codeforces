#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    set<int> dist;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        dist.insert(x);
    }
    int prev = -1;
    while(true) {
        int cur = dist.size();
        dist.insert(cur);
        if(cur == prev) break;
        prev = cur;
    }
    cout << prev << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
