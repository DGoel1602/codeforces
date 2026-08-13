#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	bool h1 = false, h2 = false;
	for(char c: s) h1 |= c == '<', h2 |= c == '>';
	if(!h1 || !h2) return void(cout << n << '\n');
	vi res(n);
	rep(i, 0, n)
		if(s[i] == '-') res[i] = res[(i+1)%n] = 1;
	cout << accumulate(all(res), 0) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
