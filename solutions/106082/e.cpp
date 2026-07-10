#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int n, c;
	vector<int> sz, p;
	DSU(int n): n(n), c(n), sz(n, 1), p(n) {
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		if(x != p[x]) p[x] = find(p[x]);
		return p[x];
	}
	bool join(int a, int b) {
		a = find(a); b = find(b);
		if(a == b) return false;
		if(sz[b] > sz[a]) swap(a, b);
		p[b] = a;
		c--;
		sz[a] += sz[b];
		return true;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<string> words(n);
	DSU dsu(n);
	for(string &x: words) cin >> x;
	vector<vector<int>> cost(n, vector(n, 0));
	vector<array<int, 3>> edges;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			for(int l = 0; l<k; l++) cost[i][j] += abs(words[i][l] - words[j][l]);
			edges.push_back({cost[i][j], i, j});
		}
	}
	sort(edges.begin(), edges.end());
	for(auto [c, a, b]: edges) {
		dsu.join(a, b);
		if(dsu.c == 1) {
			cout << c << "\n";
			return 0;
		}
	}
}
