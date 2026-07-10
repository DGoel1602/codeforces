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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vi a(n); 
    for(int &x: a) cin >> x;
    
    int mx = 0, cur = 0;
    bool hz = false;
    int zidx = 0;
    rep(i, 0, n) {
        if(s[i] == '0') hz = true, zidx = i;
        cur += a[i];
        cur = max(cur, 0LL);
        mx = max(cur, mx);
    }
    if(mx != k && !hz) return void(cout << "NO\n");

    rep(i, 0, n) if(s[i] == '0') a[i] = -1e12;

    mx = 0, cur = 0;
    rep(i, 0, n) {
        cur += a[i];
        cur = max(cur, 0LL);
        mx = max(cur, mx);
    }
    if(mx > k) return void(cout << "NO\n");
    if(mx == k) {
        cout << "Yes\n";
        for(int x: a) cout << x << " ";
        cout << '\n';
        return;
    }
 
    vi pref(n+1);
    for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + a[i-1];
    int mipref = 1e18, mxsuf = -1e18;
    vi mxprefs(n);
    for(int i = n-1; i>=0; i--) {
        mxsuf = max(mxsuf, pref[i+1]);
        mxprefs[i] = mxsuf;
    }
    rep(i, 0, n) {
        mipref = min(mipref, pref[i]);
        if(s[i] == '0') {
            int mxpref = pref[i] - mipref;
            int mxsuff = mxprefs[i] - pref[i+1];
            // cout << mxpref << " " << mxprefs[i] << " " << pref[3] << endl;
            if(mxpref <= k && mxsuff <= k) {
                a[i] = k - (mxpref + mxsuff);
                cout << "Yes\n";
                for(int x: a) cout << x << " ";
                cout << '\n';
                return;
            }
        }
    }
    cout << "No\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
