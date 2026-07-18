#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	bool operator<(H o) const { return x < o.x; }
};
static const H C = (ll)1e11+3;

void solve() {
	int n, m; cin >> n >> m;
	vector<string> nums(n);
	for(string &x: nums) cin >> x;
	string ph; cin >> ph;

	map<H, array<int, 3>> mp;
	rep(i, 0, n) {
		rep(j, 0, m) {
			H hash = nums[i][j];
			for(int siz = 2; siz<=3; siz++) {
				if(j+siz-1 >= m) break;
				hash = hash * C + nums[i][j+siz-1];
				mp[hash] = {j + 1, j + 1 + siz - 1, i + 1};
			}
		}
	}

	vi dp(m+1, 0);
	dp[m] = 1;
	for(int i = m-2; i>=0; i--) {
		H th = (H)ph[i] * C + ph[i+1];
		if(mp.count(th) && dp[i+2]) dp[i] = 2;
		if(i == m-2) continue;
		H thh = th * C + ph[i+2];
		if(mp.count(thh) && dp[i+3]) dp[i] = 3;
	}
	if(!dp[0]) return void(cout << "-1\n");
	int cur = 0;
	int cnt = 0;
	vector<H> ret;
	while(cur < m) {
		int sz = dp[cur];
		H th = (H)ph[cur] * C + ph[cur+1];
		if(sz == 3) th = th * C + ph[cur+2];
		ret.push_back(th);
		cur += sz;
		cnt++;
	}
	cout << cnt << '\n';
	for(H h: ret) 
		cout << mp[h][0] << " " << mp[h][1] << " " << mp[h][2] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
