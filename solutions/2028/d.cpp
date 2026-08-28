#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n; cin >> n;
    vvi vals(3, vi(n));
    for(int i = 0; i<3; i++) for (int &x: vals[i]) cin >> x;
    set<int> cur = {n-1};
    vector<pair<int, int>> mns(3, {(int)1e9, -1});
    vector<pair<int, int>> res(n);
    for(int i = n-1; i>=0; i--) {
        rep(j, 0, 3) if(vals[j][i] > mns[j].first) {
            cur.insert(i);
            res[i] = {j, mns[j].second};
        }
        if(cur.count(i)) {
            rep(j, 0, 3) {
                if(vals[j][i] < mns[j].first) {
                    mns[j] = {vals[j][i], i};
                }
            }
        }
    }
    if(!cur.count(0)) return void(cout << "NO\n");
    cout << "YES\n";
    int c = 0;
    vector<pair<char, int>> ret;
    while(c != n - 1) {
        ret.push_back({"qkj"[res[c].first], res[c].second + 1});
        c = res[c].second;
    }
    cout << ret.size() << '\n';
    for(auto [a, b]: ret) cout << a << " " << b << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
