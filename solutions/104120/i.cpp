#include <bits/stdc++.h>
using namespace std;

vector<int> cc;
using ll = long long;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for(int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
            jmp.emplace_back(V.size() - pw * 2 + 1);
            for(int j = 0; j<jmp[k].size(); j++) jmp[k][j] = max(jmp[k-1][j], jmp[k-1][j+pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

using pii = pair<int, long long>;

pii merge(pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}

struct Node {
    int lo, hi, mid;
    pii val = {0, 0};
    int lazy = 0;
    Node *left = nullptr, *right = nullptr;
    
    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void apply() {
        val = {0, 0};
        lazy = 1;
    }

    void push() {
        if(lo == hi - 1 || !lazy) return;
        left->apply();
        right->apply();
        lazy = 0;
    }

    void update(int i, ll x) {
        if(lo == hi - 1) {
            return void(val = merge(val, {x, x*cc[lo]}));
        }
        push();
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = merge(left->val, right->val);
    }

    pii query(int l, int r) {
        if(l >= hi || r <= lo) return {0, 0};
        if(r >= hi && l <= lo) return val;
        push();
        return merge(left->query(l, r), right->query(l, r));
    }

    pii queryset(int l, int r) {
        if(l >= hi || r <= lo) return {0, 0};
        if(r >= hi && l <= lo) {
            pii va = val;
            apply();
            return va;
        };
        push();
        pii res = merge(left->queryset(l, r), right->queryset(l, r));
        val = merge(left->val, right->val);
        return res;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; cc.push_back(a[i]);
    }

    sort(cc.begin(), cc.end());
    cc.erase(unique(cc.begin(), cc.end()), cc.end());

    vector<int> a2;
    for(int i = 0; i<n; i++) {
        int idx = lower_bound(cc.begin(), cc.end(), a[i]) - cc.begin();
        a2.push_back(idx);
    }
    RMQ<int> rmq(a2);

    int q; cin >> q;
    Node st(0, n);
    while(q--) {
        int x; cin >> x;
        vector<int> idxs(x), v(x);
        for(int i = 0; i < x; i++) cin >> idxs[i];
        for(int i = 0; i < x; i++) v[i] = a2[--idxs[i]];
        int ls = -1;
        vector<int> submx(x);
        for(int i = 0; i<x; i++) submx[i] = rmq.query(ls+1, idxs[i]+1), ls = idxs[i];

        st.queryset(0, n);

        ll res = 0;
        for(int i = x-1; i>=0; i--) {
            pii que = st.query(v[i], n);
            res += (x - i - 1 - que.first) * (ll)cc[v[i]] + que.second + cc[v[i]];
            int tfeq = st.queryset(0, submx[i]).first;
            st.update(submx[i], tfeq+1);
        }
        cout << res << '\n';
    }
}
