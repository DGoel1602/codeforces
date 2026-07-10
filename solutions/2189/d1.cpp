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

const ll mod = 1e9 + 7;

void solve() {
    int n, c; cin >> n >> c;
    string s; cin >> s;
    ll cur = 1;

    if(s[n-1] == '0' || s[0] == '0' || c == 1) {
        cout << "-1\n";
        return;
    }

    for(int i = 0; i<n-1; i++) {
        if(s[i] == '1') {
            cur *= 2;
            if(c % 2 == 0) c /= 2;
        } else {
            c /= __gcd(i, c);
            cur *= i;
            if(i == 0) break;
        }
        cur = cur % mod;
        if(c == 1) break;
    }

    cout << (cur == 0 || c == 1 ? -1 : cur) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();
}

//210 102 201 012
//021 120
