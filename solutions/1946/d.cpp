#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

#define SIZ 100005

void solve() {
    int n, x; cin >> n >> x;
    vi a(n);
    for(int &x: a) cin >> x;

    vector<bitset<SIZ>> cps(32, 0);
    vector<int> freq(32, 0);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=30; j++) {
            if((a[i] >> j) & 1) freq[j]++;
            if(freq[j] % 2 == 0) cps[j][i] = 1;
        }
    }

    for(int i = 0; i<=30; i++) {
        if(freq[i] % 2 == 1) cps[i] = 0;
    }

    int be = -1;
    bitset<SIZ> cur;
    cur.set();

    for(int i = 30; i>=0; i--) {
        if((x >> i) & 1) {
            be = max(be, (int)(cps[i] & cur).count());
        } else {
            cur = cur & cps[i];
        }
    }
    be = max(be, (int)cur.count());

    cout << (be == 0 ? -1 : be) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
