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
	string s; cin >> s;
	vector<pair<char, int>> t;
	rep(i, 0, n) {
		if(i == 0 || s[i] != s[i-1]) t.push_back({s[i], 1});
		else t[t.size()-1].second++;
	}
	int best = t.size();
	rep(i, 1, t.size()-1) {
		if(t[i-1].first == t[i+1].first && t[i].second == 1) best = t.size() - 2;
		else if(t[i].second == 1) best = min(best, (int)t.size()-1);
	}
	cout << best << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
