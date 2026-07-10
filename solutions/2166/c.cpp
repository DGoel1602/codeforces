#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    set<pii> s;
    map<int, vi> ids;
    rep(i, 0, n) {
        int x; cin >> x;
        s.insert({i, x});
        ids[x].push_back(i);
    }
    ll c = 0, siz = n;
    vector<bool> vis(n);
    for(auto [el, idxs]: ids) {
        for(int i: idxs) {
            auto it = s.lower_bound({i, 0});
            if(it == s.end() || it->first != i) continue;

            vector<pii> rem;
            while(siz > 1) {
                if(it == s.begin()) it = s.end();
                --it;
                if(vis[it->first] || it->second > el) break;
                c += (ll)el;
                rem.push_back(*it);
                siz--;
                vis[it->first] = true;
                // cerr << i << " " << it->first << " " << it->second << endl;
            }
            for(auto r: rem) {
                s.erase(r);
            }

            rem.clear();
            it = s.lower_bound({i, 0});
            ++it;
            if(it == s.end()) it = s.begin();

            while(siz > 1) {
                if(vis[it->first] || it->second > el) break;
                c += (ll)el;
                rem.push_back(*it);
                vis[it->first] = true;
                siz--;
                //cerr << el << " " << i << " " << it->first << " " << it->second << endl;
                ++it;
                if(it == s.end()) it = s.begin();
            }
            for(auto r: rem) {
                s.erase(r);
            }
        }
    }
    cout << c << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
