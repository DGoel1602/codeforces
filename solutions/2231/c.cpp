#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i< b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    sort(all(a));

    unordered_map<int, pii> res;

    rep(i, 0, n) {
        int cur = a[i];
        if(cur == 1) res[2] = {res[2].first + 1, res[2].second + 1};

        int mv = 0;
        if(i == 0 || res.count(cur)) res[cur] = {res[cur].first + 0, res[cur].second+1};
        while(cur != 1) {
            if(cur % 2 == 0) cur /= 2;
            else {
                mv++;
                if(i == 0 || res.count(cur+1)) res[cur+1] = {res[cur+1].first + mv, res[cur+1].second + 1};

                cur = (cur + 1) / 2;
            }
            mv++;
            if(i == 0 || res.count(cur)) res[cur] = {res[cur].first + mv, res[cur].second + 1};
        }
    }

    int be = 1e9;
    for(auto [el, c]: res) {
        if(c.second != n) continue;
        be = min(be, c.first);
    }
    cout << be << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
