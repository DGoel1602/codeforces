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
	int k; cin >> k;

	pii unl = {-1, -1};
	vi leaves(k);
	rep(j, 0, k) {
		int n; cin >> n;
		vvi adj(n);
		rep(i, 0, n-1) {
			int u, v; cin >> u >> v;
			adj[--u].push_back(--v);
			adj[v].push_back(u);
		}
		rep(i, 0, n) {
			if(adj[i].size() == 1) {
				unl = {j + 1, adj[i][0] + 1};
				leaves[j] = i;
				break;
			}
		}
	}

	if(unl.first == -1) {
		rep(i, 2, k+1)
			cout << "1 1 " << i << " " << 1 << '\n';
		return;
	}

	rep(j, 1, k+1) if(j != unl.first) {
		cout << j << " " << leaves[j-1] + 1 << " " << unl.first << " " << unl.second << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
