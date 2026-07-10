#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
		string s, t;
		cin >> s >> t;
    int n = s.size(), m = t.size();
		vvi dp(n+1, vi(m+1, 0));
		vi prefs(n+1), preft(m+1);

    for(int i = 1; i<=n; i++) prefs[i] = (prefs[i-1] + s[i-1] - '0') % 10;
    for(int i = 1; i<=m; i++) preft[i] = (preft[i-1] + t[i-1] - '0') % 10;

		for(int i = 1; i<=n; i++)
			for(int j = 1; j<=m; j++) {
				if(prefs[i] == preft[j]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}

    int be = dp[n][m];
    cout << (be < 1 || prefs[n] != preft[m] ? -1 : be) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
