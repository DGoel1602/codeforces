#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;
	sort(all(a));

	int evs = 0;
	map<int, int> freq;
	for(int x: a) freq[x]++;
	vi odds;
	int ans = 0;
	for(auto [el, cnt]: freq) {
		if((evs && cnt > 1) || cnt > 2) ans = max(ans, evs + 2 * el * (cnt/2));
		evs += 2 * el * (cnt / 2);
		if(cnt % 2) odds.push_back(el);
	}
	if(!evs) return void(cout << "0\n");
	sort(all(odds));
	for(int x: odds) {
		if(evs > x) ans = max(ans, evs + x);
	}
	for(int i = 1; i<odds.size(); i++) {
		if(evs + odds[i-1] > odds[i]) ans = max(ans, odds[i-1] + evs + odds[i]);
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
