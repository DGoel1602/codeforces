#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vector<pii> segs(n);
	for(auto &[a, b]: segs) cin >> a >> b;
	sort(all(segs), [&](pii a, pii b) -> bool { return a.first + a.second < b.first + b.second; });

	ll res = 0;
	for(auto [a, b]: segs) res += b - a;
	if(n % 2 == 0) {
		for(int i = 0; i<n/2; i++) res -= segs[i].first;
		for(int i = n-1; i>=n-(n/2); i--) res += segs[i].second;
		cout << res << '\n';
		return;
	}
	
	vector<int> prefl(n+1), prefr(n+1);
	for(int i = 1; i<=n; i++) prefl[i] = prefl[i-1] + segs[i-1].first;
	for(int i = 1; i<=n; i++) prefr[i] = prefr[i-1] + segs[i-1].second;
	ll be = -1;
	for(int i = 0; i<n; i++) {
		int lb = n/2;
		int contri = 0;
		if(i < n/2) lb++, contri = -segs[i].first;
		int rb = n-(n/2);
		if(i >= n-(n/2)) rb--, contri = segs[i].second;
		be = max(be, - prefl[lb] + prefr[n] - prefr[rb] + res - contri);
	}
	cout << be << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
