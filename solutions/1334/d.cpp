#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    ll n, l, r; cin >> n >> l >> r;
    ll len = r - l + 1;
    int curp = 1;
    while(true) {
        int segl = n - curp;
        segl = (segl * 2);
        if(segl >= l) break;
        l -= segl;
        curp++;
        if(curp == n) break;
    }
    vector<int> res;
    if(curp != n) {
        int cur = curp + 1;
        while (res.size() < len + l - 1) {
            res.push_back(curp);
            res.push_back(cur);
            if (cur == n) {
                curp++;
                cur = curp + 1;
                if (curp == n) break;
                continue;
            }
            cur++;
        }
    };
    while(res.size() < len + l - 1) {
        res.push_back(1);
    }
    for(int i = l-1; i<len+l-1; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
