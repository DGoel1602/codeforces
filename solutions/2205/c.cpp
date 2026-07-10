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
	vvi blogs(n);
	rep(i, 0, n) {
		int s; cin >> s;
		vi tb;
		rep(j, 0, s) {
			int x; cin >> x;
			tb.push_back(x);
		}
		set<int> se;
		for(int j = s-1; j>=0; j--) {
			if(se.count(tb[j])) continue;
			blogs[i].push_back(tb[j]);
			se.insert(tb[j]);
		}
	}
	vvi ord;

	while(!blogs.empty()) {
		sort(all(blogs), greater<>());
		vi best = blogs.back();

		vi cp(best);
		ord.push_back(cp);

		set<int> tbr(all(best));

		for(int i = 0; i<blogs.size()-1; i++) {
			vi rem;
			for(int j = 0; j<blogs[i].size(); j++)
				if(tbr.count(blogs[i][j])) rem.push_back(j);

			for(int j = rem.size()-1; j>=0; j--) blogs[i].erase(blogs[i].begin() + rem[j]);
		}
		blogs.pop_back();
	}

	reverse(all(ord));
	rep(i, 0, n) reverse(all(ord[i]));

	//cout << "SIZE: " << ord.size() << "\n";

	vi res;
	rep(i, 0, n) {
		rep(j, 0, sz(ord[i])) {
			//cerr << ord[i][j] << " ";
			res.push_back(ord[i][j]);
		}
		//cerr << endl;
	}

	set<int> se;
	for(int i = sz(res)-1; i>=0; i--) {
		if(!se.count(res[i])) cout << res[i] << " ";
		se.insert(res[i]);
	}
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}

// 1 3 4
// 1 3 4 2
