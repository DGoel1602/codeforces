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
    int n, m; cin >> n >> m;
    vi freqs(m,0);
    vvi sets;
    rep(i, 0, n) {
        int s; cin >> s;
        vi set;
        rep(j, 0, s) {
            int x; cin >> x;
            --x;
            set.push_back(x);
            freqs[x]++;
        }
        sets.push_back(set);
    }
    rep(i, 0, m) if(freqs[i] == 0) return void(cout << "NO\n");
    int c = 0;
    for(auto set: sets) {
        bool works = true;
        for(int x: set) if(freqs[x] == 1) {
            works = false;
            break;
        };
        if(works) c++;
    }
    if(c >= 2) cout << "YES\n";
    else cout << "NO\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
