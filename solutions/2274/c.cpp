#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define int long long

void check(vector<int> &a, int amt, int n) {
    map<int, int> freq;
    for(int i = 0; i<n; i++) {
        freq[a[i]]++;
    }
    vector<int> mul(n+1);
    for(auto [el, cnt]: freq) {
        mul[cnt] += cnt;
    }
    int res = *max_element(mul.begin(), mul.end());
    assert(amt == res);
}

void solve() {
    int n; cin >> n;

    int lo = 1, hi = 1e3;
    while(lo != hi) {
        int m = lo + (hi - lo) / 2;
        int cnt = 0;
        for(int i = 1; i<=m; i++) {
            cnt += (m / i) * i;
        }
        if(cnt < n) lo = m + 1;
        else hi = m;
    }

    int res = lo;
    int t = 0;
    cout << res << '\n';
    int id = 1;

    int cnt = 0;
    vector<int> cnts(res+1);
    for (int i = 1; i <= res; i++) {
        cnt += (res / i) * i;
        cnts[i] = (res / i);
    }
    int need_rem = cnt - n;
    for (int i = res; i > 0; i--) {
        int rem = min((need_rem / i), (res / i));
        need_rem -= rem * i;
        cnts[i] -= rem;
    }

    vector<int> fn;
    for(int i = 1; i<=res; i++) {
        for(int j = 0; j<cnts[i]; j++) {
            for(int k = 0; k<i && t < n; k++) {
                t++;
                fn.push_back(id);
            }
            id++;
        }
    }
    for(int x: fn) cout << x << " ";
    cout << '\n';
    //check(fn, res, n);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    // x = 2p - x
    // x = 2p2 - (2p - x)
    // x = 2p3 - (2p2 - (2p - x))
    // x = 2p3 - (2p2 - (2p))
    // 

    // x = 3 - (0 - 3) = 6
    // x = 2*3-0

    int t;
    cin >> t;
    while(t-- ) solve();
}
