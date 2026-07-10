#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

ll a, n;
vi arr;

int dp[2][2][17];

int go(bool tight, bool zeros, int x, string &s) {
    if(x == s.size()) return 1;
    if(dp[tight][zeros][x] != -1) return dp[tight][zeros][x];

    int res = 0;
    if(arr[0] != 0 && zeros) {
        res += go(false, true, x+1, s);
    }

    for(int d: arr) {
        if(tight && d > s[x] - '0') break;
        res += go(tight & d == s[x] - '0', zeros && d == 0, x + 1, s);
    }

    return dp[tight][zeros][x] = res;
}

int gogo(int s) {
    memset(dp, -1, sizeof(dp));
    string s1 = to_string(s);
    return go(true, true, 0, s1);
}

void solve() {
    cin >> a >> n;
    arr.resize(n);
    for(int &x: arr) cin >> x;
    
    ll lo = 0, hi = 1e17;
    while(lo != hi) {
        int m = lo + (hi - lo + 0) / 2;
        bool works = false;

        int lf = max(0LL,a-m);

        int c = gogo(a+m);
        if (lf > 0) c -= gogo(lf - 1);
        else if (arr[0] != 0) c--;
        if (c) works = true;

        //cout << lo << " " << hi << " " << m << " " << works << " " << c << " " << a << " " << n << endl;
        if(!works) lo = m + 1;
        else hi = m;
    }
    cout << lo << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
