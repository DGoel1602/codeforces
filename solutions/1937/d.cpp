#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi pref_l(n+1), pref_r(n+1);
    rep(i, 1, n+1) {
        pref_l[i] = pref_l[i-1];
        pref_r[i] = pref_r[i-1];
        if(s[i-1] == '>') pref_l[i] += 2 * (-(i));
        else pref_r[i] += 2 * (i);
    }
    vi lefts, rights;
    rep(i, 0, n) {
        if(s[i] == '>') lefts.push_back(i);
        else rights.push_back(i);
    }
    rep(i, 0, n) {
        // if(i != 4) continue;
        int lc = upper_bound(all(lefts), i) - lefts.begin();
        int rc = rights.size() - (lower_bound(all(rights), i) - rights.begin());
        int diff = lc == rc;
        if(lc == rc) {
            if(s[i] == '>') lc--;
            else rc--;
        }
        int res = 0;
        if(lc < rc) {
            int smt = *(lower_bound(all(rights), i) + diff + lc - 1 + (s[i] == '<'));
            res = pref_r[smt+1] - pref_r[i] + pref_l[i + 1];
        } else if(rc < lc) {
            int smt = *(upper_bound(all(lefts), i) - rc - diff - (s[i] == '>'));
            res = pref_l[i+1] - pref_l[smt] + pref_r[n] - pref_r[i];
            res += n + 1;
        } 
        res -= (s[i] == '>' ? -(i+1) : (i+1));
        cout << res << ' ';
    }
    cout << '\n';
}
// 5 + 5 - 2 - 2 + 7

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
