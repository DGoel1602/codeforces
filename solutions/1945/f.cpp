#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

using ll = long long;

// struct Node {
//     int lo, hi;
//     Node *left = nullptr, *right = nullptr;
//     int val = 0;

//     Node(int l, int r): lo(l), hi(r) {}

//     void check() {
//         if(left != nullptr || lo == hi - 1) return;
//         int mid = (lo + hi) / 2;
//         left = new Node(lo, mid);
//         right = new Node(mid, hi);
//     };

//     void update(int i, int d) {
//         if(lo == hi - 1) return void(val += d);
//         check();
//         int mid = (lo + hi) / 2;
//         if(i < mid) left->update(i, d);
//         else right->update(i, d);
//         val = left->val + right->val;
//     }

//     int walk(int k) {
//         if(lo == hi - 1) return lo;
//         check();
//         if(left->val < k) return right->walk(k - left->val);
//         else return left->walk(k);
//     }
// };

void solve() {
    int n; cin >> n;
    vector<int> a(n), p(n);
    for(int &x: a) cin >> x;
    for(int &x: p) cin >> x;

    Tree<pair<int, int>> t;
    for(int i = 0; i<n; i++) t.insert({a[i], i});
    // Node st(0, 1e9 + 5);
    // for(int x: a) st.update(x, 1);

    pair<ll, int> b = {0, 0};
    for(int i = 0; i<n; i++) {
        // int r = st.walk(n-i);
        int r = (*t.find_by_order(n - i - 1)).first;
        if((ll)r*(i+1) > b.first) b = {(ll)r*(i+1), i+1};
        t.erase({a[p[i]-1], p[i]-1});
        t.insert({0, i});
        // st.update(a[p[i]-1], -1);
        // st.update(0, 1);
    }

    cout << b.first << " " << b.second << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
