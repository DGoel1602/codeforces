#include <bits/stdc++.h>
using namespace std;

struct Node {
    int lo, hi;
    int val = 0;
    Node *left = nullptr, *right = nullptr;

    Node(int l, int r): lo(l), hi(r) {}

    void check() {
        if(left != nullptr) return;
        int mid = (lo + hi) / 2;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int i, int x) {
        if(lo == hi - 1) return void(val = x);
        check();
        int mid = (lo + hi) / 2;
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = max(left->val, right->val);
    }

    int query(int l, int r) {
        if(l >= hi || r <= lo) return 0;
        if(r >= hi && l <= lo) return val;
        check();
        return max(left->query(l, r), right->query(l, r));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    Node st(0, 1e9 + 5);
    for(int x: a) {
        int b = max(st.query(0, x - k + 1), st.query(x+k, 1e9 + 5));
        st.update(x, b + 1);
    }
    cout << st.query(0, 1e9 + 5) << "\n";
}
