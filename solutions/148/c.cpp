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
	int n, a, b; cin >> n >> a >> b;

	if(!b && a) {
		if(a > n - 2) return void(cout << "-1\n");
		cout << "200 1 ";
		int ls = 201;
		a--;
		cout << ls << " ";
		rep(i, 3, n) {
			if(a) ls++, a--;
			else ls = 1;
			cout << ls << " ";
		}
		cout << '\n';
		return;
	}

	int ls = 1;
	cout << ls << " ";
	rep(i, 1, n) {
		if(b) ls *= 2, b--;
		else if(a) ls++, a--;
		else ls = 1;
		cout << ls << " ";
	}
	cout << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}
