#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void odd(int n, string s) {
	vvi bef(2, vi(26, 0)), aft(2, vi(26, 0));
	rep(i, 0, n) aft[i%2][s[i]-'a']++;

	int res = 1e9;
	for(int i = 0; i<n; i++) {
		aft[i%2][s[i]-'a']--;
		
		int be = 1e9, bo = 1e9;
		for(int j = 0; j<26; j++) {
			be = min(be, ((n-1)/2) - (bef[0][j] + aft[1][j]));
			bo = min(bo, ((n-1)/2) - (bef[1][j] + aft[0][j]));
		}
		res = min(res, be + bo);

		bef[i%2][s[i]-'a']++;
	}
	cout << res + 1 << "\n";
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	if(n % 2) odd(n, s);
	else {
		vvi freq(2, vector(26, 0));
		rep(i, 0, n) freq[i%2][s[i]-'a']++;
		cout << n - (*max_element(all(freq[0])) + *max_element(all(freq[1]))) << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
