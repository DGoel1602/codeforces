#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

vi sieve(1e7+1, 1);
vi primes;

void solve() {
	int n; cin >> n;

	int res = 0;
	for(int i = 1; i<=n; i++) {
		for(int p: primes) {
			if(i * p <= n) res++;
			else break;
		}
	}
	cout << res << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	for(int i = 2; i*i<=1e7; i++) {
		if(!sieve[i]) continue;
		for(int j = i*i; j<=1e7; j+=i) sieve[j] = 0;
	}
	rep(i, 2, 1e7+1) if(sieve[i]) primes.push_back(i);

	int t; cin >> t;
	while(t--) solve();
}
