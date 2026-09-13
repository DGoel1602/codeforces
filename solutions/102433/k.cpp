#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arrs;

struct Node2 {
    int lo, hi, mid;
    int val = 0;
    int lupd = 0;
    Node2 *left = nullptr, *right;

    Node2(int l, int r, int i): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) {
            val = arrs[i][l];
            return;
        }
        left = new Node2(lo, mid, i);
        right = new Node2(mid, hi, i);
    }

    Node2(Node2* cpy): lo(cpy->lo), hi(cpy->hi), mid(cpy->mid), val(cpy->val), lupd(cpy->lupd), left(cpy->left), right(cpy->right) {}

    void apply(int x) {
        val = val + x;
        lupd = lupd + x;
    }

    Node2* update(int l, int r, int x) {
        if(l >= hi || r <= lo) return this;
        Node2 *n = new Node2(this);
        if(r >= hi && l <= lo) {
            n->apply(x);
            return n;
        }
        n->left = left->update(l, r, x);
        n->right = right->update(l, r, x);
        return n;
    }

    int query(int i) {
        if(lo == hi - 1) return val;
        if(i < mid) return lupd + left->query(i);
        else return lupd + right->query(i);
    }
};


vector<vector<Node2>> sts;

struct Node {
    int lo, hi, mid;
    int val = 0;
    int lset = -1, ll = -1, li = -1;
    Node *left = nullptr, *right;

    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void apply(int x, int l, int i) {
        ll = l, li = i;
        if(lo == hi - 1) val = sts[x][i].query(lo - l);
        lset = x;
    }

    void push() {
        if(lo == hi - 1) return;
        if(lset != -1) left->apply(lset, ll, li), right->apply(lset, ll, li), lset = -1, ll = -1, li = -1;
    }

    void update(int l, int r, int x, int le, int i) {
        if(l >= hi || r <= lo) return;
        if(r >= hi && l <= lo) return void(apply(x, le, i));
        push();
        left->update(l, r, x, le, i);
        right->update(l, r, x, le, i);
    }

    int query(int i) {
        if(lo == hi - 1) return val;
        push();
        if(i < mid) return left->query(i);
        else return right->query(i);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    arrs.resize(m);
    for(int i = 0; i<m; i++) {
        int s; cin >> s;
        arrs[i].resize(s);
        for(int &x: arrs[i]) cin >> x;
    }

    Node st(0, n);
    for(int i = 0; i<m; i++) {
        sts.push_back({Node2(0, arrs[i].size(), i)});
    }

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int i, p; cin >> i >> p;
            --p;
            int len = arrs[--i].size();
            st.update(p, p+len, i, p, sts[i].size()-1);
        } else if(t == 2) {
            int p; cin >> p;
            --p;
            cout << (st.query(p) % 256) << '\n';
        } else {
            int i, l, r; cin >> i >> l >> r;
            sts[--i].push_back(sts[i].back().update(--l, r, 1));
        }
    }
}
