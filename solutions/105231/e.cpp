#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)(x).size()

mt19937 rng(time(NULL));

void solve() {
    int n; cin >> n;
    vector<int> ot(n);
    for(int &x: ot) cin >> x;

    vector<pair<int, int>> pa;
    int sz1 = 13, sz2 = 17;
    int tz = sz1 + sz2;
    shuffle(pa.begin(), pa.end(), rng);
    for(int i = 0; i<min(n, tz); i++) pa.push_back({i, ot[i]});
    vector<int> a(sz(pa)), idx(sz(pa));
    for(int i = 0; i<sz(pa); i++) idx[i] = pa[i].first, a[i] = pa[i].second;

    if(sz(a) < sz1) sz1 = sz(a);
    sz2 = sz(pa) - sz1;


    unordered_map<int, pair<int, int>> mp;

    auto tr = [&](int mask, int j, int mask2, int j2, int diff) -> bool {
        if((mask2 | j2 | mask | j) == 0) return false;

        vector<int> f, s;
        for(int i = 0; i<sz1; i++) {
            int type = ((mask2 & (1 << i)) != 0) + ((j2 & (1 << i)) != 0);
            if(type == 1) f.push_back(i);
            if(type == 2) s.push_back(i);
        }
        for(int i = 0; i<sz2; i++) {
            int type = ((mask & (1 << i)) != 0) + ((j & (1 << i)) != 0);
            if(type == 1) f.push_back(sz1+i);
            if(type == 2) s.push_back(sz1+i);
        }

        int diff2 = 0;
        for(int x: f) diff2 += a[x];
        for(int x: s) diff2 -= a[x];
        if(diff2 != 0) return false;

        cout << f.size() << " ";
        for(int x: f) cout << idx[x]+1 << " ";
        cout << '\n';
        cout << s.size() << " ";
        for(int x: s) cout << idx[x]+1 << " ";
        cout << '\n';
        return true;
    };

    
    for(int mask = 0; mask<(1 << sz1); mask++) {
        for(int j = mask; j > 0; j = (j - 1) & mask) {
            int inv = (~j) & mask;
            if (inv > mask) break;
            int diff = 0;
            for(int i = 0; i<sz1; i++) {
                int type = ((mask & (1 << i)) != 0) + ((j & (1 << i)) != 0);
                if(type == 1) diff -= a[i];
                if(type == 2) diff += a[i];
            }
            if(diff == 0) {
                tr( 0, 0, mask, j, diff);
                return;
            }
            mp[abs(diff)] = {mask, j};
        }
    }

    for(int mask = 0; mask<(1 << sz2); mask++) {
        for(int j = mask; j > 0; j = (j - 1) & mask) {
            int inv = (~j) & mask;
            if (inv > mask) break;
            int diff = 0;
            for(int i = 0; i<sz2; i++) {
                int type = ((mask & (1 << i)) != 0) + ((j & (1 << i)) != 0);
                if(type == 1) diff -= a[sz1+i];
                if(type == 2) diff += a[sz1+i];
            }
            diff = abs(diff);
            if(diff == 0) {
                tr(mask, j, 0, 0, diff);
                return;
            }
            if(mp.count(diff)) {
                auto [mask2, j2] = mp[diff];
                if(!tr(mask, j, mask2, j2, diff)) tr(mask, j, mask2, (~j2) & mask2, diff);
                return;
            }
        }
    }

    cout << "-1\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
