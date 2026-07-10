#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct op {
    int t, idx, v;
};

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) {
        for(; pos < s.size(); pos |= pos+1) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for(; pos > 0; pos &= pos-1) res += s[pos-1];
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<op> ops(n);
    for(int i = 0; i < n; i++) {
        cin >> ops[i].t;
        if(ops[i].t == 1) cin >> ops[i].v;
        else if(ops[i].t == 2) cin >> ops[i].idx;
        else if(ops[i].t == 3) cin >> ops[i].idx >> ops[i].v;
        else cin >> ops[i].idx;
    }
    
    vector<ll> curv, dist;
    vector<int> ind;

    for(int i = 0; i < n; i++) {
        if(ops[i].t == 1) {
            dist.push_back(ops[i].v);
            curv.push_back(ops[i].v);
            ind.push_back(i+1);
        } else if(ops[i].t == 3) {
            int idx = lower_bound(ind.begin(), ind.end(), ops[i].idx) - ind.begin();
            dist.push_back(curv[idx] + ops[i].v);
            curv[idx] += ops[i].v;
        }
    }

    sort(dist.begin(), dist.end());
    dist.erase(unique(dist.begin(), dist.end()), dist.end());

    FT bit(dist.size());
    curv.clear(), ind.clear();
    for(int i = 0; i < n; i++) {
        if(ops[i].t == 1) {
            curv.push_back(ops[i].v);
            ind.push_back(i+1);
            int idx = lower_bound(dist.begin(), dist.end(), curv.back()) - dist.begin();
            bit.update(idx, 1);
        } else if(ops[i].t == 2) {
            ll v = curv[lower_bound(ind.begin(), ind.end(), ops[i].idx) - ind.begin()];
            int idx = lower_bound(dist.begin(), dist.end(), v) - dist.begin();
            bit.update(idx, -1);
        } else if(ops[i].t == 3) {
            int vidx = lower_bound(ind.begin(), ind.end(), ops[i].idx) - ind.begin();
            int pidx = lower_bound(dist.begin(), dist.end(), curv[vidx]) - dist.begin();
            int nidx = lower_bound(dist.begin(), dist.end(), curv[vidx] + ops[i].v) - dist.begin();
            bit.update(pidx, -1);
            bit.update(nidx, 1);
            curv[vidx] += ops[i].v;
        } else {
            int idx = lower_bound(ind.begin(), ind.end(), ops[i].idx) - ind.begin();
            ll v = curv[idx];
            int di = lower_bound(dist.begin(), dist.end(), v) - dist.begin();
            cout << bit.query(di) << '\n';
        }
    }
}
