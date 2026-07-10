#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x, x--;

    int cycles = 0;
    bool nt = false;
    vector<int> vis(n);
    for(int i = 0; i<n; i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        cycles++;

        set<int> thi;
        thi.insert(i);

        int cur = a[i];
        if(thi.count(cur+1) || thi.count(cur-1)) nt = true;
        thi.insert(cur);

        while(cur != i) {
            vis[cur] = 1;
            cur = a[cur];
            if(thi.count(cur+1) || thi.count(cur-1)) nt = true;
            thi.insert(cur);
        }
    }
    // cout << "CYC: " << cycles << endl;
    cout << (n - cycles + (nt ? -1 : 1)) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
