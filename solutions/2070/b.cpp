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
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    ll cur = x;
    int l = -1;
    int c = 0;
    int cs = 0;
    for(ll i = 0; i<n; i++) {
        int d = s[i] == 'L' ? -1 : 1;
        cur += d;
        cs++;
        if(cur == 0) c++;
        if(cs >= k) break;
        if(cur == 0) {
            i = -1;
            if(c == 2) {
                ll rep = cs - l;
                return void(cout << 2 + (k - cs)/(rep) << "\n");
            }
            l = cs;
        }
    }
    cout << c << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
