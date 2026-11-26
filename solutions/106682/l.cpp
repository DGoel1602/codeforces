#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<set<int>> idxs(m+1);
    for(int i =0 ; i<n; i++) idxs[a[i]].insert(i);
    vector<int> taken(m+1);

    vector<int> cp(a);
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());

    int cur = 0, r = 0;
    while(cur < cp.size()) {
        int cp_cur = cur;
        int cur_idx = 0;
        for(; cp_cur<cp.size(); cp_cur++) {
            auto idx_p = idxs[cp[cp_cur]].lower_bound(cur_idx);
            if(idx_p == idxs[cp[cp_cur]].end()) break;
            cur_idx = *idx_p + 1;
        }

        int o_cp_cur = cur;
        cur_idx = n;
        for(; o_cp_cur<cp.size(); o_cp_cur++) {
            auto idx_p = idxs[cp[o_cp_cur]].upper_bound(cur_idx);
            if(idx_p == idxs[cp[o_cp_cur]].begin()) break;
            --idx_p;
            cur_idx = *idx_p - 1;
        }

        cur = max(o_cp_cur, cp_cur);
        r++;
    }
    cout << cp.size() << " " << r << '\n';
}
