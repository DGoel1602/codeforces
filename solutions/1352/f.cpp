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

int dp[101][101][101][2];

int go(int a, int b, int c, int ls) {
	if(a == 0 && b == 0 && c == 0) return 1;
	auto &ref = dp[a][b][c][ls];
	if(ref != -1) return ref;
	ref = 0;
	if(ls == 0 && a) ref |= go(a-1, b, c, 0);
	if(ls == 1 && b) ref |= go(a, b-1, c, 0);
	if(ls == 0 && b) ref |= go(a, b-1, c, 1);
	if(ls == 1 && c) ref |= go(a, b, c-1, 1);
	return ref;
}

bool tw(int a, int b, int c, int t) {
	if(!go(a, b, c, t)) return false;
	int ls = t;
	cout << t;
	while(a || b || c) {
		if(ls == 0 && a && go(a-1, b, c, 0)) {
			ls = 0;
			--a;
		} else if(ls == 1 && b && go(a, b-1, c, 0)) {
			ls = 0;
			--b;
		} else if(ls == 0 && b && go(a, b-1, c, 1)) {
			ls = 1;
			--b;
		} else if(ls == 1 && c && go(a, b, c-1, 1)) {
			ls = 1;
			--c;
		}
		cout << ls;
	}
	cout << '\n';
	return true;
}

void solve() {
	int a, b, c; cin >> a >> b >> c;
	if(!tw(a, b, c, 0)) tw(a, b, c, 1);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int t; cin >> t;
	while(t--) solve();
}
