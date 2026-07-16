#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n, m; cin >> n >> m;
	vvi mp(n, vi(n, 0));
	rep(_, 0, m) {
		int o, i, j; cin >> o >> i >> j;
		--i; --j;
		mp[i][j] = o;
	}
	vi neg(n);
	rep(i, 0, n)
		if(mp[i][i] == 2) neg[i] = 1;

	vvi adj(n);
	vi ind(n);
	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			if(mp[i][j] == 1) {
				if(neg[i] && neg[j]) return void(cout << "NO\n");
				if(!neg[i] && neg[j]) adj[j].push_back(i), ind[i]++;
				if(neg[i] && !neg[j]) adj[i].push_back(j), ind[j]++;
			} else {
				if(!neg[i] && !neg[j]) return void(cout << "NO\n");
				if(neg[i] && !neg[j]) adj[j].push_back(i), ind[i]++;
				if(!neg[i] && neg[j]) adj[i].push_back(j), ind[j]++;
			}
		}
	}
	queue<int> q;
	for(int i = 0; i<n; i++) if(!ind[i]) q.push(i);
	vi tops;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		tops.push_back(u);
		for(int v: adj[u]) {
			ind[v]--;
			if(!ind[v]) q.push(v);
		}
	}
	if(tops.size() != n) return void(cout << "NO\n");
	vi a(n);
	int cur = 1;
	for(int i: tops) {
		a[i] = (cur++) * (neg[i] ? -1 : 1);
	}
	cout << "YES\n";
	for(int x: a) cout << x << " ";
	cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
