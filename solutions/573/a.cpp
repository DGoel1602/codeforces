#include <algorithm>
#include <bits/stdc++.h>
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
	vi a(n);
	for(int &x: a) {
		cin >> x;
		while(x % 2 == 0) x /= 2;
		while(x % 3 == 0) x /= 3;
	}
	cout << (*min_element(all(a)) == *max_element(all(a)) ? "Yes\n" : "No\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}
