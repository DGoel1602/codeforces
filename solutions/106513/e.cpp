#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

struct Data {
    bool w = true;
    int mx = 0, mn = 1e9;
};

Data merge(Data a, Data b) {
    Data n;
    n.w = a.w && b.w && (a.mx <= b.mn);
    n.mn = min(a.mn, b.mn);
    n.mx = max(a.mx, b.mx);
    return n;
}

struct Node {
    int lo, hi, mid;
    Data val;
    Node *left, *right;
    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }
    void update(int i, int x) {
        if(lo == hi - 1)  {
            val.w = true;
            val.mx = val.mn = x;
            return;
        }
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = merge(left->val, right->val);
    }
    Data query(int l, int r) {
        if(l >= hi || r <= lo) return Data();
        if(r >= hi && l <= lo) return val;
        return merge(left->query(l, r), right->query(l, r));
    }
};

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    Node st(0, n);
    rep(i, 0, n) st.update(i, a[i]);
    for(int k = n; k>=1; k--) {
        for(int i = 0; i<n; i+=k) if(!st.query(i, i+k).w) goto next;
        return void(cout << k << '\n');
        next:;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
