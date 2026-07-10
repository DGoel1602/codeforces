#include <bits/stdc++.h>
using namespace std;

struct Node {
    int lo, hi;
    Node *left, *right;
    int val = 0, lazy = -1;

    Node(int l, int r): lo(l), hi(r) {
        if(l == r - 1) return;
        int mid = (lo + hi) / 2;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void apply(int x) {
        val = max(val, x);
        lazy = max(lazy, x);
    }

    void push() {
        if(lo == hi - 1 || lazy == -1) return;
        left->apply(lazy); right->apply(lazy);
        lazy = -1;
    }

    void update(int l, int r, int x) {
        if(l >= hi || r <= lo) return;
        if(r >= hi && l <= lo) return void(apply(x));
        push();
        left->update(l, r, x); right->update(l, r, x);
        val = max(left->val, right->val);
    }

    int query(int i) {
        if(lo == hi - 1) return val;
        int mid = (lo + hi) / 2;
        push();
        if(i < mid) return left->query(i);
        else return right->query(i);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> segs(m);
    for(auto &[l, r]: segs) cin >> l >> r;
    sort(segs.begin(), segs.end());
    vector<int> ends, begins;
    for(auto [l, r]: segs) ends.push_back(r), begins.push_back(l);
    sort(begins.begin(), begins.end());
    sort(ends.begin(), ends.end());

    Node st(0, n+5);
    for(auto [l, r]: segs) {
        // cout << l << " " << r << " " << r + 1 << endl;
        st.update(l, r, r+1);
    }

    vector<int> dp(n+2, 0);
    for(int i = n; i>=0; i--) {
        dp[i] = dp[i+1];
        int cs = m - 
            (lower_bound(ends.begin(), ends.end(), i) - ends.begin()) - 
            (m - (upper_bound(begins.begin(), begins.end(), i) - begins.begin()));
        int nx = max(i+1, st.query(i));
        dp[i] = max(dp[i], cs + dp[nx]);
        // cout << i << " " << cs << " " << nx << " " << dp[i] << endl; 
    }

    cout << dp[0] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
