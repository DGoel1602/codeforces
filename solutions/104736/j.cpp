#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

using vi = vector<int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b);
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    LCA lca(adj);
    vector<int> depth(n);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        depth[u] = d;
        for(int v: adj[u]) if(v != p) dfs(v, u, d+1, dfs);
    };
    dfs(0, -1, 0, dfs);

    auto d = [&](int u, int v) -> int {
        return depth[u] + depth[v] - 2*depth[lca.lca(u, v)];
    };

    int sq = sqrt(n);
    vector<pair<int, int>> res(n, {1e7, 1e7});
    for(int b = 0; b<n; b+=sq) {
        for(int i = b; i<min(n, b+sq); i++) {
            // cout << b << ": " << i << endl;
            for(int j = i+1; j<min(n, b+sq); j++) {
                res[i] = min(res[i], {d(i, j), j});
            }
        }

        vector<int> dist(n, -1);
        queue<pair<int, int>> q;
        for(int i = b+sq; i<n; i++) dist[i] = 0, q.push({i, i});
        while(q.size()) {
            auto [u, rep] = q.front(); q.pop();
            for(int v: adj[u]) if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                res[v] = min(res[v], {dist[v], rep});
                q.push({v, rep});
            }
        }
    }

    for(auto [_, x]: res) cout << min(n, x + 1) << '\n';
}
