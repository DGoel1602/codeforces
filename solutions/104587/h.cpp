#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int s, n; cin >> s >> n;
    vector<int> ys, ns;
    for(int i = 0; i<n; i++) {
        int d; cin >> d;
        char t; cin >> t;
        (t == 'y' ? ys : ns).push_back(d);
    }
    sort(ys.begin(), ys.end());
    sort(ns.begin(), ns.end());
    for(int i = 1; i<=n; i++) {
        int tot_gone = i * s;
        int gone_ys = upper_bound(ys.begin(), ys.end(), i) - ys.begin();
        int gone_ns = upper_bound(ns.begin(), ns.end(), i) - ns.begin();
        if(gone_ys > i || gone_ns + gone_ys > tot_gone) {
            cout << "No\n";
            return 0;
        }
    }    
    cout << "Yes\n";
}
