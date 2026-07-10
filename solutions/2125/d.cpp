#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353;

ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b * b) % mod, e /= 2)
        if(e & 1) res = (res * b) % mod;
    return res;
}

struct Node {
    int lo, hi;
    Node *left, *right;
    ll val = 1, lazy = 1;

    Node(int l, int r): lo(l), hi(r) {
        if(l == r - 1) return;
        int mid = (lo + hi) / 2;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int i, int x) {
        if(lo == hi - 1) return void(val = (val * x) % mod);
        int mid = (lo + hi) / 2;
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = (left->val * right->val) % mod;
    }

    int query(int l, int r) {
        if(l >= hi || r <= lo) return 1;
        if(r >= hi && l <= lo) return val;
        return (left->query(l, r) * right->query(l, r)) % mod;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    Node st(0, m);
    vector<vector<array<int, 3>>> upds(m);
    for(int i = 0; i<n; i++){
        int l, r, p, q; cin >> l >> r >> p >> q;
        l--;
        p = q - p;
        upds[l].push_back({r, p, q});
    }

    //cout << "ADA" << "\n";
    vector<int> dp(m+1, 0);
    dp[m] = 1;
    for(int i = m-1; i>=0; i--) {
        ll res = 0;
        for(auto [to, p, q]: upds[i]) {
            int orprob = p * modpow(q, mod - 2) % mod;
            st.update(i, orprob);
        }

        for(auto [to, p, q]: upds[i]) {
            int nonprob = st.query(i, to);
            int orprob = p * modpow(q, mod - 2) % mod;
            int didprob = (q-p) * modpow(q, mod - 2) % mod;
            nonprob = (((nonprob * (modpow(orprob, mod-2))) % mod) * didprob) % mod;
            //cout << i + 1 << " " << to << " " << orprob << " " << didprob << " " << nonprob << endl;
            res = (res + ((nonprob) * dp[to]) % mod) % mod;
        }
        dp[i] = res;
    }
    //for(int i = 0; i<=m; i++) cout << dp[i] << " ";
    //cout << endl;
    cout << dp[0] << "\n";
}

signed main() {
    //cin.tie(0)->sync_with_stdio(0);
    solve();
    //cout << 1 * modpow(3, mod-2) << endl;
}

// 2/18 * 3/1 * 2/3
// 2/6 * 2/3
// 4/18
