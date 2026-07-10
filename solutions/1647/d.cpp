#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

int isPrime(int n) {
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}

map<int, int> pf(int n) {
	map<int, int> res;
	for(int i = 2; i * i <= n; i++)
		while(n % i == 0) res[i]++, n /= i;
	if(n > 1) res[n]++;
	return res;
}

void solve() {
	int x, d; cin >> x >> d;
	int cnt = 0;
	int ox = x;
	while(ox % d == 0) cnt++, ox /= d;
	if(cnt == 1) return void(cout << "NO\n");
	if(isPrime(ox)) {
		if(cnt == 2) return void(cout << "NO\n");

		map<int, int> prf = pf(d);
		if(prf.size() == 1) {
			map<int, int> prf2 = pf(ox);
			int ex = cnt - 1;
			int pcnt = prf.begin()->second + prf2[prf.begin()->first];
			int dcnt = prf.begin()->second;
			int mx = (pcnt+ex-1)/ex;
			if(mx >= dcnt) return void(cout << "NO\n");
		}

	}
	cout << "YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
