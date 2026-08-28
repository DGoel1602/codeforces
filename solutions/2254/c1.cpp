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
	int n; cin >> n;
	string a, b; cin >> a >> b;
	vi cnt(2), cnt_b(2);
	rep(i, 0, n) cnt[i%2] += a[i] - '0', cnt_b[i%2] += b[i] - '0';
	cout << (cnt[0] == cnt_b[0] && cnt[1] == cnt_b[1] ? "YES\n" : "NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
