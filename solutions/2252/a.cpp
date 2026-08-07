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
	vi a(n);
	for(int &x: a) cin >> x;
	map<int, int> freq;
	for(int x: a) freq[x]++;
	int res = 0;
	int others = 0;
	int o_cnt = 0;
	for(auto [el, cnt]: freq) if(cnt <= n/2) o_cnt += cnt;
	for(auto [el, cnt]: freq) {
		if(cnt <= n/2) others += el * cnt;
		else {
			res += el * min(o_cnt + 2, cnt);
		}
	}
	cout << res + others << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
