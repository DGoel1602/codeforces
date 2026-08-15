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
	deque<deque<int>> res;
	res.push_front({});
	res.front().push_front(1);
	for(int i = 2; i <= n; i++) {
		int ls = (i-1) * (i-1);
		int cur = ++ls;
		if(i % 2 == 0) {
			for(auto &q: res) q.push_back(cur++);
			deque<int> n;
			for(; cur <= i * i; cur++) n.push_back(cur);
			res.push_back(n);
		} else {
			deque<int> n;
			n.push_back(i * i);
			for(int j = 0; j<i-1; j++) n.push_back(cur++);
			for(auto &q: res) q.push_front(cur++);
			res.push_front(n);
		}
	}
	for(auto &q: res) {
		for(auto x: q) cout << --x << ' ';
		cout << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
