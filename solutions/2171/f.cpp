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
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	int t = a[0];
	set<int> unt;
	vector<pii> edges;
	int mn = t;
	rep(i, 1, n) {
		int x = a[i];
		if(mn == n - i + 1) return void(cout << "NO\n");
		mn = min(mn, x);
		if(unt.size()) {
			if(*unt.begin() > x) {
				unt.insert(x);
			} else {
				edges.push_back({*unt.begin(), x});
				auto it = ++unt.begin();
				vi rem;
				while(it != unt.end() && *it < x) {
					edges.push_back({*it, x});
					rem.push_back(*it);
					it++;
				}
				for(int _: rem) unt.erase(_);

				if(t < x) {
					edges.push_back({t, x});
					t = min(t, *unt.begin());
					unt.erase(unt.begin());
				}
			}
		} else {
			if(t > x) unt.insert(x);
			else edges.push_back({t, x});
		}
	}
	cout << "YES\n";
	assert(!unt.size());
	assert(edges.size() == n - 1);
	for(auto [a, b]: edges) cout << a << " " << b << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
