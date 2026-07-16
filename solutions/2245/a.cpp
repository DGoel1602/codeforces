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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	if(k > n/2) return void(cout << "-1\n");
	int res = 0;
	for(int i = 0; i<k; i++) if(s[i] == 'L') res++;
	for(int i = n-1; i>=n-k; i--) if(s[i] == 'R') res++;
	cout << res << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
