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
	int mul = 1;
	rep(i, 2, 1e5) {
		if(i * i > n) break;
		if(n % i == 0) mul *= i;
		while(n % i == 0) n /= i;
	}
	if(n > 1) mul *= n;
	cout << mul << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
