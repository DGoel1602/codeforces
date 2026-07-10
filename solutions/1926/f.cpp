#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

#define SIZ 17
int dp[7][7][1<<SIZ];
pii transitions[7][7];
string grid[7];

const vi idxs = {0, 2, 8, 14, 16};
const int bbs = 1 | (1 << 2) | (1 << 8) | (1 << 14) | (1 << 16);

pii fx(int i, int j) {
		if(j == 5) return {i+1, 1};
		else return {i, j+1};
}

int go(int i, int j, int bs) {
		if(i == 6) return 0;
		auto &ref = dp[i][j][bs];
		if(ref != -1) return ref;
		ref = 1e9;

		auto [ni, nj] = fx(i, j);
		auto [tr, diff] = transitions[i][j];
		if((bs & bbs) == bbs) {
			for(int idx: idxs) if(idx != 16 && idx != 14)
					ref = min(ref, 1 + go(ni, nj, (((bs ^ (1 << idx)) << diff) | tr) & ((1 << SIZ) - 1)));					
		} else ref = go(ni, nj, ((bs << diff) | tr) & ((1 << SIZ) - 1));
		return ref;
}

void solve() {
	for(string &x: grid) cin >> x;
	memset(dp, -1, sizeof(dp));
	memset(transitions, 0, sizeof(transitions));

	for(int i = 1; i<=5; i++) for(int j = 1; j <= 5; j++) {
		auto [ni, nj] = fx(i, j);
		int curls = (i+1)*7 + j+1;
		int wanls = (ni+1)*7 + nj+1;
		auto &ref = transitions[i][j];
		int bs = 0;
		int diff = 0;
		for(int idx = curls+1; idx<=min(wanls, 48); idx++)
			ref.first = (ref.first << 1) | (grid[idx/7][idx%7] == 'B'), ref.second++;
	}

	int bs = 0;
	for(int i = 0; i<SIZ; i++) bs = (bs << 1) | (grid[i/7][i%7] == 'B');
	cout << go(1, 1, bs) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
