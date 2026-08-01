#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    a[0] = 1;
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lo = 0, hi = n;
    while(lo < hi) {
        int x = (lo + hi) / 2;

        bool valid = true;
        int ap = 0, bp = x;
        for(; bp < n; ap++, bp++) {
            if(a[ap] >= b[bp]) valid = false;
        }
        if(valid) hi = x;
        else lo = x+1;
    }
    cout << hi << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
