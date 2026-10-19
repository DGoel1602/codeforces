#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<int> res;
    if(n % 3) {
        for(int k = 0; k<3; k++)
            for(int i = 2*n; i>=2; i -= 2) res.push_back(i);
    } else {
        for(int k = 0; k<3; k++)
            for(int i = 2*n-1; i>=2; i -= 2) res.push_back(i);
    }
    cout << res.size() << '\n';
    for(int x: res) cout << x << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t-- ) solve();
}
