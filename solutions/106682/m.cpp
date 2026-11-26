#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> a;
vector<int> pref = {0};

struct Node {
    int lo, hi, mid;
    int val = 0;
    int lazy = 0; // 0 - nothing, 1 - set to 0, 2 - set to max
    Node *left, *right;

    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void apply(int type) {
        lazy = type;
        if(lazy == 2) val = pref[hi] - pref[lo];
        else val = 0;
        // cout << val << endl;
    }

    void push() {
        if(!lazy || lo == hi - 1) return;
        left->apply(lazy);
        right->apply(lazy);
        lazy = 0;
    }

    void update(int l, int r, int type) {
        if(l >= hi || r <= lo) return;
        if(r >= hi && l <= lo) return apply(type);
        push();
        left->update(l, r, type);
        right->update(l, r, type);
        val = left->val + right->val;
    }

    void update(int i, int x) {
        if(lo == hi - 1) return void(val = x);
        push();
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = left->val + right->val;
    }

    int query(int l, int r) {
        if(l >= hi || r <= lo) return 0;
        if(r >= hi && l <= lo) return val;
        push();
        return left->query(l, r) + right->query(l, r);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;

    Node st(0, n);
    a.resize(n);

    for(int i = 0; i<n; i++) cin >> a[i];
    for(int x: a) pref.push_back(pref.back() + x);
    st.update(0, n, 2);

    while(q--) {
        int T; cin >> T;
        if(T == 1) {
            int B, V; cin >> B >> V;
            --B;

            if(st.query(B, B + 1) > V) {
                st.update(B, st.query(B, B + 1) - V);
                // cout << "NORMAL ADD: " << st.query(B, B + 1) << endl;
                continue;
            }

            int lo = 0, hi = B;
            while(lo != hi) {
                int m = lo + (hi - lo) / 2;
                if(st.query(m, B + 1) > V) lo = m + 1;
                else hi = m;
            }

            int left = V - st.query(lo, B + 1);
            // cout << st.query(lo, B + 1) << " " << left << endl;
            st.update(lo, B + 1, 1);
            if(lo != 0) st.update(lo - 1, st.query(lo - 1, lo) - left);

            // for(int i = 0; i<n; i++) cout << st.query(i, i+1) << " ";
            // cout << endl;
        } else {
            int L, R; cin >> L >> R;
            --L;
            cout << pref[R] - pref[L] - st.query(L, R) << '\n';
            st.update(L, R, 2); 
        }
    }
}
