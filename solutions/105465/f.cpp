#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)(a).size()

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) {
        for(; pos < sz(s); pos |= pos+1) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for(; pos > 0; pos &= pos-1) res += s[pos-1];
        return res;
    }
};

ll cnt_inv(vector<int> &a) {
    // for(int x: a) cout << x << " ";
    // cout << endl;
    FT bit(sz(a));
    ll res = 0;
    for(int i = 0; i < sz(a); i++) {
        res += bit.query(sz(a)) - bit.query(a[i]);
        bit.update(a[i], 1);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    ll init_invs = cnt_inv(a);
    int xo = 0;
    for(int i = __lg(n)-1; i>=0; i--) {
        vector<int> cp(a);
        for(int &x: cp) x ^= (1 << i);
        if(cnt_inv(cp) < init_invs) xo |= (1 << i);
    }
    for(int &x: a) x ^= xo;
    cout << cnt_inv(a) + (xo != 0) << '\n';
}
