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
    vi a(n);
    for(int &x: a) cin >> x;
    vi freq(n+1, 0);
    for(int x: a) freq[x]++;

    vi freqs;
    rep(i, 0, n+1)
        if(freq[i]) freqs.push_back(freq[i]);
    sort(all(freqs));

    int siz = freqs.size();
    vi suf(siz+1);
    for(int i = siz-1; i>=0; i--) suf[i] = suf[i+1] + freqs[i];

    set<int> works;
    for(int i = 0; i<n+1; i++) {
        auto it = upper_bound(all(freqs), i) - freqs.begin();
        int cnt = siz - it;
        int tot = suf[it];
        tot -= cnt * i;
        if(!cnt) continue;
        
        int more = k - tot;
        if(more < 0) continue;
        if(!more || more % cnt == 0) works.insert(cnt);
    }
    cout << works.size() << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
