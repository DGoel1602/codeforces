#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<int> ones, zeros;
    for(int i = 0; i<n; i++)
        (s[i] == '1' ? ones : zeros).insert(i);
    int cost = 0;
    while(ones.size()) {
        int lso = *prev(ones.end());
        auto suz = zeros.lower_bound(lso);
        if(suz != zeros.begin()) {
            --suz;
            cost += *suz + 1;
            zeros.erase(suz);
            ones.erase(lso);
        } else {
            if(ones.size() == 1) break;
            cost += *ones.begin() + 1;
            ones.erase(lso);
            ones.erase(ones.begin());
        }
    }
    for(int x: ones) cost += x + 1;
    for(int x: zeros) cost += x + 1;
    cout << cost << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
