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
	int n, l; cin >> n >> l;
	vi a(n);
	for(int &x: a) cin >> x;

	auto eval = [&](int i, int j) -> array<int, 3> {
			vi b(a);
			swap(b[i], b[j]);
			vector<int> mxs;
			int cmk = 0;
			vector<int> seen(n+5);
			rep(k,0,n) {
				seen[b[k]] = 1;
				while(seen[cmk]) cmk++;
				mxs.push_back(cmk);
			}
			sort(all(mxs));
			return {mxs[n-l], i, j};
	};

	array<int, 3> best = eval(0, 0);
	for(int i = 0; i<n; i++) {
		rep(j, i+1, n) {
			best = max(best, eval(i, j));
		}
	}
	if(best[1] == best[2]) cout << "-1\n";
	else cout << best[1] + 1 << " " << best[2] + 1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
