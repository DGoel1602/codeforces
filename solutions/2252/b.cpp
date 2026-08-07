#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int cur = 0;
	vector<pair<char, int>> gs;
	rep(i, 0, n) {
		if(i != 0 && s[i] != s[i-1]) {
			gs.push_back({s[i-1], cur-1});
			cur = 1;
		} else cur += 1;
	}
	if(cur) gs.push_back({s.back(), cur-1});
	int o_type = 0, z_type = 0;
	for(auto [t, cnt]: gs) {
		if(t == '0') z_type += cnt;
		else o_type += cnt;
	}

	if(s[0] == '0' && z_type <= o_type - 2) z_type++;
	if(s.back() == '0' && z_type <= o_type - 2) z_type++;
	if(s[0] == '1' && o_type <= z_type - 2) o_type++;
	if(s.back() == '1' && o_type <= z_type - 2) o_type++;

	int mx = max(z_type, o_type);
	if(abs(z_type - o_type) >= 2) return void(cout << "-1\n");
	if(z_type == o_type) return void(cout << 2 * o_type << '\n');
	cout << mx * 2 - 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
