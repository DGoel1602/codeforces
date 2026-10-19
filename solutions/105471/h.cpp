#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x), end(x)
using vi = vector<int>;

struct ST{
    int vl;
    int lo, md, hi;
    ST * left, * right;
    ST(int l, int r) {
        lo=l, hi=r;
        md = l + (r-l)/2;
        vl = 0;
        if (l==r) return;
        left = new ST(l,md);
        right = new ST(md+1,r);
    }
    int query(int i, int k, int v) {
        if (lo==hi) return 0;
        int ans = ((i>md) ? right : left)->query(i, k, v);
        ans += (vl <= k && hi-lo < v);
        return ans;
    }
    void update(int i) {
        if (lo==hi) return void(vl++);
        ((i>md) ? right : left)->update(i);
        vl = left->vl+right->vl;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    ST st(0, (1<<n)-1);

    vector<pair<int, int>> vs;
    for (int i = 0; i < (1 << n); i++) {
        int v; cin >> v; vs.emplace_back(v,i);
    }
    sort(all(vs));
    reverse(all(vs));

    vi ans((1 << n));
    for (auto [v, i] : vs) {
        ans[i] = st.query(i, k, v);
        st.update(i);
    }

    for (auto v : ans) cout << v << ' ';
}
