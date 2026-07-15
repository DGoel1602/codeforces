#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; i++)

struct Node {
    int lo, hi, mid;
    int val = 0;
    Node *left, *right;

    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int i, int x) {
        if(lo == hi - 1) return void(val = x);
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = max(left->val, right->val);
    }
    
    int query(int l, int r) {
        if(l >= hi || r <= lo) return 0;
        if(r >= hi && l <= lo) return val;
        return max(left->query(l, r), right->query(l, r));
    }
};

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;

    vi dp(n, 0);

    vector<pii> segs;
    rep(i, 0, n) segs.push_back({i - a[i], i});
    sort(all(segs));
    int cur = n;

    Node st(0, n);
    for(int i = n-1; i>=0; i--) {
        while(cur > 0 && segs[cur-1].first > i) {
            cur--;
            st.update(segs[cur].second, dp[segs[cur].second]);
        }
        dp[i] = st.query(i + a[i] + 1, n) + a[i];
    }
    cout << *max_element(all(dp)) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
