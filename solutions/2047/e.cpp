#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

struct Node {
    int lo, hi;
    int val = 0;
    Node *left = nullptr, *right = nullptr;

    Node(int l, int r): lo(l), hi(r) {
        if(l == r - 1) return;
        int mid = (lo + hi) / 2;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int i, int x) {
        if(lo == hi - 1) return void(val += x);
        int mid = (lo + hi) / 2;
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = left->val + right->val;
    }

    int query(int k) {
        if(lo == hi - 1) return lo;
        if(left->val >= k) return left->query(k);
        else return right->query(k - left->val);
    }

    int query(int l, int r) {
        if(l >= hi || r <= lo) return 0;
        if(r >= hi && l <= lo) return val;
        int res = 0;
        if(left != nullptr) res += left->query(l, r);
        if(right != nullptr) res += right->query(l, r);
        return res;
    }
};

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> ps(n);
    for(auto &[x, y]: ps) cin >> x >> y;
    vector<int> cpx, cpy;
    for(auto &[x, y]: ps) cpx.push_back(x), cpy.push_back(y);
    sort(cpx.begin(), cpx.end());
    cpx.erase(unique(cpx.begin(), cpx.end()), cpx.end());
    sort(cpy.begin(), cpy.end());
    cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());
    for(auto &[x, y]: ps) x = lower_bound(cpx.begin(), cpx.end(), x) - cpx.begin(), y = lower_bound(cpy.begin(), cpy.end(), y) - cpy.begin();

    sort(ps.begin(), ps.end());

    vector<int> xs;
    for(auto p: ps) xs.push_back(p.first);
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    xs.push_back(n+3);

    Node stb(0, n+5), ste(0, n + 5);
    for(auto [x, y]: ps) ste.update(y, 1);

    int cur = 0;
    int bef = 0, aft = n;
    int res = 0;
    pii cord;
    for(int x: xs) {
        while(cur < n && ps[cur].first < x) {
            stb.update(ps[cur].second, 1);
            ste.update(ps[cur].second, -1);
            bef++;
            aft--;
            cur++;
        }
        int lo = 0, hi = n/4 + 1;
        while(lo != hi) {
            int m = lo + (hi - lo + 1) / 2;
            if(m * 2 > bef || m * 2 > aft) {
                hi = m - 1;
                continue;
            }
            int lc = stb.query(m);
            int rc = ste.query(m);
            bool valid = true;
            int cut = max(lc, rc);

            int fq = stb.query(0, cut+1);
            int sq = ste.query(0, cut+1);
            valid = valid && fq >= m;
            valid = valid && bef - fq >= m;
            valid = valid && sq >= m;
            valid = valid && aft - sq >= m;

            if(valid) lo = m;
            else hi = m - 1;
        }
        if(res < lo) {
            res = lo;
            cord = {x, max(stb.query(lo), ste.query(lo))};
        }
    }
    if(res != 0) {
        cout << res << "\n";
        cout << cpx[cord.first] << " " << cpy[cord.second]+1 << "\n";
    } else {
        cout << "0\n0 0\n";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
