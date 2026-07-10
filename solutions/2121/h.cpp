#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> ls(n), rs(n);
    for(int i = 0; i<n; i++) cin >> ls[i] >> rs[i];
    multiset<int> cur;
    cur.insert(0);
    cur.insert(INT_MAX);
    for(int i = 0; i<n; i++) {
        cur.insert(ls[i]);
        auto ne = cur.lower_bound(rs[i]+1);
        if(*ne != INT_MAX) cur.erase(ne);
        // cur.insert(rs[i]); 
        cout << cur.size() - 2 << " ";
    }    
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
