#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

vi solve(int n, vi &a) {
    vi pa(n + 1, 0);
    rep(i, 1, n+1) pa[i] = pa[i-1] + a[i-1];
    vi res(n, 1e9);
    int ls = -1;
    for(int i = 0; i<n; i++) {
        int lls = ls;
        if(i > 0 && a[i] != a[i-1]) ls = i-1;
        int lo = -1, hi = i-1;
        while(lo != hi) {
            int mid = lo + (hi - lo + 1) / 2;
            int rem = mid == -1 ? -1e9 : pa[mid - 1 + 1];
            int s = pa[i - 1 + 1] - rem;
            if(s <= a[i]) hi = mid - 1;
            else lo = mid;
        }
        if(i > 0 && a[i-1] > a[i]) lls = i-1;
        if(lls != -1 && lo != -1) res[i] = i - min(lls, lo);
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n);
        for(int &x: a) cin >> x;
        vi res = solve(n, a);
        reverse(all(a));
        vi res2 = solve(n, a);
        reverse(all(res2));

        rep(i, 0, n) cout << (min(res[i], res2[i]) > 1e8 ? -1 : min(res[i], res2[i])) << " ";
        //for(int x: res) cout << x << " ";
        cout << "\n";
    };
}
