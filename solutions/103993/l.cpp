#include <bits/stdc++.h>
using namespace std;
#define ll long long

using ppii = array<array<ll, 2>, 2>;
ppii def(int a, int b, int c, int d) {
    ppii res;
    res[0][0] = a, res[0][1] = b, res[1][0] = c, res[1][1] = d;
    return res;
}

const ll mod = 998244353;

ppii merge(ppii a, ppii b) {
    ppii res = def(0, 0, 0, 0);
    res[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % mod;
    res[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % mod;
    res[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod;
    res[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % mod;
    return res;
}

struct node {
    int lo, hi, mid;
    ppii val = def(3, 0, 1, 2);
    node *left = nullptr, *right = nullptr;

    node(int l, int r) : lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new node(l, mid);
        right = new node(mid, r);
        val = merge(left->val, right->val);
    }

    void update(int pos, ll nv) {
        if(lo == hi - 1) {
            if(nv == 1) val = def(1, 2, 1, 2);
            else val = def(3, 0, 1, 2);
            return;
        }
        if(pos < mid) left->update(pos, nv);
        else right->update(pos, nv);
        val = merge(left->val, right->val);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> segs(n);
    for(auto &[a, b]: segs) cin >> a >> b;
    map<int, vector<pair<int, int>>> events;
    for(int i = 1; i<n; i++) {
        auto [a, b] = segs[i];
        events[a].push_back({1, i});
        events[b+1].push_back({0, i});
    }
    node st(0, n-1);
    ll ret = 0;
    for(int x = 0; x<=3e5; x++) {
        for(auto [t, idx]: events[x])
            st.update(idx-1, t);
        ppii res = st.val;
        ll r = (segs[0].first <= x && segs[0].second >= x) ? res[1][1] : res[0][1];
        ret = (ret + r) % mod;
    }
    cout << ret << '\n';
}
