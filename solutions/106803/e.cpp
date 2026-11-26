#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)

struct TwoSat {
	int N;
	vector<basic_string<int>> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	vi v, comp, z; int time = 0;
	int dfs(int i) {
		int low = v[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, v[e] ?: dfs(e));
		if (low == v[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return v[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		v.assign(2*N, 0); comp = v;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}
};

void solve() {
    int n; cin >> n;
    vector<string> g(n);
    for(string &x: g)cin >> x;


    TwoSat ts(2 * n);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(g[i][j] == 'B') {
                ts.either(i, ~(n+j));
                ts.either(~i, (n+j));
            } else if(g[i][j] == 'W') {
                ts.either(~i, ~(n+j));
                ts.either(i, (n+j));
            }
        }
    }

    cout << (ts.solve() ? "POSSIBLE\n" : "IMPOSSIBLE\n");

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
