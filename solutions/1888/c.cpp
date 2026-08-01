#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> ns(n, 0);
    set<int> s;
    for(int i = 0; i<n; i++) {
        s.insert(a[i]);
        ns[i] = s.size();
    }    
    s = set<int>();
    ll res = 0;
    for(int i = n-1; i>=0; i--) {
        if(!s.count(a[i])) {
            res += ns[i];
        }
        s.insert(a[i]);
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
