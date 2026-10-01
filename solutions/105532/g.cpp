#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    vector<pair<int, int>> a = {{1, 0}, {0, 1}};
    int n, r; cin >> n >> r;
    for(int i = 0; i<n-2; i++) {
        pair<int, int> am2 = a[a.size()-2], am = a[a.size()-1];
        a.push_back({am2.first+am.first, am2.second+am.second});
    }
    pair<int, int> f = a[n-1];
    for(int i = 0; i<r; i++) {
        int a, b; cin >> a >> b;
        if((!f.first || b % f.first) && (!f.second || b % f.second)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
