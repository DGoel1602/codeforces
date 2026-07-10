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
	int n, k; cin >> n >> k;
	vi a(n);
	for(int &x: a) cin >> x;

	map<int, int> freq;
	for(int x: a) freq[x]++;
	for(auto [el, cnt]: freq) {
		auto ab = freq.upper_bound(el);
		if(ab != freq.end() && ab->first <= el + k) continue;

		if(cnt % 2)
			if(freq.lower_bound(el-k)->first == el) continue;

		return void(cout << "YES\n");
	}
	cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
