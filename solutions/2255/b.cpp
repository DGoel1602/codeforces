#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

const ll mod = 998244353;

ll modpow(ll b, ll e) {
	ll res = 1;
	for(; e; b = (b * b) % mod, e /= 2)
		if(e & 1) res = (res * b) % mod;
	return res;
}

vector<ll> facts(2e6, 1);

ll choose(ll n, ll d) {
	if(n < 0 || n - d < 0) return 1;
	return (facts[n] * modpow((facts[d] * facts[n - d]) % mod, mod - 2)) % mod;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0, cnt2 = 0;
	for(char c: s) cnt += c - '0', cnt2 += (c - '0') ^ 1;
	int gs = 0, gs2 = 0;
	for(int i = 0; i<n; i++) if(s[i] == '1') {
		if(i == 0 || s[i] != s[i-1]) gs++;
	}
	for(int i = 0; i<n; i++) if(s[i] == '0') {
		if(i == 0 || s[i] != s[i-1]) gs2++;
	}
	cout << (choose(cnt - 1, gs - 1) * choose(cnt2 - 1, gs2 - 1)) % mod << '\n';
	
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 2; i<2e6; i++) facts[i] = (facts[i-1] * i) % mod;
    int t; cin >> t;
    while(t--) solve();
}
