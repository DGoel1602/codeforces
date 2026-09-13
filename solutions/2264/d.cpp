#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

int cnt(int i, int sz) {
		int cur = 0;
		vi gs;
		for(int j = 0; j<sz; j++) {
			if((i >> j) & 1) gs.push_back(cur), cur = 0;
			else cur++;
		}
		gs.push_back(cur);
		int res = 0;
		for(int x: gs) res += x*(x+1)/2;
		if(gs[1] % 2 == 0) res += (gs[0] + 1) * (gs[2] + 1);
		if(gs.size() == 4 && gs[2] % 2 == 0) res += (gs[1] + 1) * (gs[3] + 1);
		if(gs.size() == 4 && gs[1] % 2 == 1 && gs[2] % 2 == 1) res += (gs[0] + 1) * (gs[3] + 1);
		return res;
}

int cnt(string str, int sz) {
		int cur = 0;
		vi gs;
		for(int j = 0; j<sz; j++) {
			if(str[sz - 1 - j] == '1') gs.push_back(cur), cur = 0;
			else cur++;
		}
		gs.push_back(cur);
		int res = 0;
		for(int x: gs) res += x*(x+1)/2;
		if(gs[1] % 2 == 0) res += (gs[0] + 1) * (gs[2] + 1);
		if(gs.size() == 4 && gs[2] % 2 == 0) res += (gs[1] + 1) * (gs[3] + 1);
		if(gs.size() == 4 && gs[1] % 2 == 1 && gs[2] % 2 == 1) res += (gs[0] + 1) * (gs[3] + 1);
		return res;
}

void solve() {
	//int best = 1e9, idx = 0;
	int n; cin >> n;
	//for(int i = 0; i<(1 << n); i++) if(__builtin_popcount(i) <= 3 && __builtin_popcount(i) >= 2) {
	//	int res = cnt(i, n);
	//	if(res < best) {
	//		best = res;
	//		idx = i;
	//	}
	//}
	//cout << idx << " " << bitset<32>(idx).to_string().substr(32 - n) << " " << best << '\n';

	if(n == 1) return void(cout << "1\n");
	if(n == 2) return void(cout << "11\n");
	int gap = n/3;
	int f = gap, s = f + gap;
	if(f == s) s++;
	if((s - f) % 2) s++;
	string ret = "";
	int count = 1e16;
	int around = 3;
	for(int ff = f-around; ff<f+around+1; ff++) {
		for(int ss = s-around; ss<s+around+1; ss++) {
			if(ff < 0 || ff >= n || ss < 0 || ss >= n || ff >= ss) continue;
			string res = "";
			rep(i, 0, n) res += (i == ff || i == ss ? '1' : '0');
			int returning = cnt(res, n);
			if(returning < count) {
				ret = string(res);
				count = returning;
			}
			string ot(res);
			ot.back() = '1';
			returning = cnt(ot, n);
			if(returning < count) {
				ret = string(ot);
				count = returning;
			}
		}
	}
	//int num = bitset<32>(ret).to_ulong();
	//cout << num << " " << cnt(ret, n) << '\n';
	cout << ret << '\n';
}

// a*(a+1)/2 + b*(b+1)/2 + c(c+1)/2 + d(d+1)/2

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
