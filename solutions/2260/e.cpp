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
	int n, q; cin >> n >> q;
	string s; cin >> s;
	
	auto conv = [&](int i, int j) {
		if(s[i] == '0' && s[j] == '0') return 0;
		if(s[i] == '0' && s[j] == '1') return 1;
		if(s[i] == '1' && s[j] == '0') return 2;
		return 3;
	};

	vvi pref(n+1, vi(4, 0));
	for(int i = 2; i<=n; i++) {
		pref[i] = vi(pref[i-1]);
		pref[i][conv(i-2, i-1)]++;
	}

	vvi pref_s(n+1, vi(2, 0));
	for(int i = 1; i<=n; i++) {
		pref_s[i][0] = pref_s[i-1][0] + (s[i-1] == '0');
		pref_s[i][1] = pref_s[i-1][1] + (s[i-1] == '1');
	}

	while(q--) {
		int l, r; cin >> l >> r;
		--l;
		vi cur = vi(pref[r]);
		for(int i = 0; i<4; i++) cur[i] -= pref[l+1][i];
		cur[conv(r-1, l)]++;

		//cout << cur[0] << " " << cur[1] << " " << cur[2] << " " << cur[3] << '\n';

		int o = pref_s[r][1] - pref_s[l][1];
		int z = pref_s[r][0] - pref_s[l][0];

		int res = 0;
		if(cur[0] == 0 && cur[3] && !z) cur[3]--, cur[1]++, cur[2]++, res += 1;
		if(cur[0] && cur[3] == 0 && !o) cur[0]--, cur[1]++, cur[2]++, res += 1;

		if(cur[0] < cur[1]) res += cur[1] - cur[0], cur[0] = cur[1];
		if(cur[3] < cur[1]) res += cur[1] - cur[3], cur[3] = cur[1];

		int mx = max(cur[3], cur[0]), mn = min(cur[3], cur[0]), cr = cur[1];
		int diff = min(mx - mn, mn - cr);
		res += diff, mx -= diff, cr += diff;

		if(mx == mn) {
			diff = (mx - cr) / 3;
			mx -= diff;
			mn -= diff;
			cr += diff * 2;
			res += diff * 2;
			res += (mn - cr) * 2;
		} else {
			diff = (mx - cr) / 2;
			res += diff;
			mx -= diff;
			cr += diff;
			if(cr != mx) res += 2;
			
			res += mx - mn;
		}

		cout << res << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}
