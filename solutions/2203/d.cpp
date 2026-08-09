#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

vector<int> sieve(3e6+1, 1);
vector<int> primes;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	vector<bool> reach(n+m+1);
	sort(a.begin(), a.end());
	for(int x: a) {
		if(reach[x]) continue;
		for(int j = x; j<=n+m; j+=x) reach[j] = true;
	}

	map<int, int> pfs;
	int lcm = 1;
	for(int x: a) {
		if(lcm % x == 0) continue;
		if(!sieve[x]) {
			for(int p: primes) {
				if(p * p > x) break;
				int cnt = 1;
				while(x % p == 0) x /= p, cnt *= p;
				if(cnt > 1 && cnt > pfs[p]) pfs[p] = cnt;
			}
		}
		if(x > 1 && !pfs[x]) pfs[x] = x;
		if(pfs.size() > 20) break;
	}

	int a_cnt = 0, b_cnt = 0, bo_cnt = 0;
	for(int i = 0; i<m; i++) {
		bool a_reach = reach[b[i]];
		bool b_reach = pfs.size() > 20;
		if(!b_reach) for(auto [el, cnt]: pfs) b_reach |= b[i] % cnt != 0;
		if(b_reach && a_reach) bo_cnt++;
		else if(b_reach) b_cnt++;
		else if(a_reach) a_cnt++;
	}

	while(true) {
		if(bo_cnt) bo_cnt--;
		else if(a_cnt) a_cnt--;
		else return void(cout << "Bob\n");
		if(bo_cnt) bo_cnt--;
		else if(b_cnt) b_cnt--;
		else return void(cout << "Alice\n");
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 2; i <= 3e6; i ++) {
		if(!sieve[i]) continue;
		for(int j = i * i; j<=3e6; j+=i) sieve[j] = 0;
		primes.push_back(i);
	}
	int t; cin >> t;
	while(t--) solve();
}
