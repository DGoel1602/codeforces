#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int solve2(vi &a, int n, set<int> &s) {
    int el = rand() % a.size();
    int a1 = a[el];
    vi seq;
    rep(i, 0, el) seq.push_back(a[i]);
    seq.push_back(0);
    for(int i = el + 1; i<2 * n; i++) seq.push_back(a[i]);

    int res = 0;
    rep(i, 0, 2 * n) res += seq[i] * (i % 2 == 0 ? 1 : -1);
    res = a1 - res;
    if(el % 2 == 1) res *= -1;
    if(res > 0 && !s.count(res)) {
        cout << abs(a1) << " ";
        for(int i = 0; i<seq.size(); i++) cout << (seq[i] == 0 ? res : seq[i]) << " ";
        cout << "\n";
        return 1;
    }
    return 0;
};

void solve() {
    int n; cin >> n;
    vi a(2 * n);
    for(int &x: a) cin >> x;
    mt19937 rng;
    set<int> s;
    for(int x: a) s.insert(x);
    while(true) {
        shuffle(all(a), rng);
        int res = 0;
        rep(i, 0, 2 * n) res += a[i] * (i % 2 == 0 ? 1 : -1);
        if(res > 0 && !s.count(abs(res))) {
            if (res < 0) reverse(all(a));
            res = abs(res);
            cout << res << " ";
            for (int x : a)
                cout << x << " ";
            cout << "\n";
            break;
        } 
        if(solve2(a, n, s)) break;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
