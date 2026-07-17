#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int lo = 1, hi = n-1;
	while(lo != hi) {
		int tier = lo / n;
		int sz = hi - lo + 1;
		int hii = (tier + 1) * n + sz / 2 - 1;
		int loo = hii - sz + 1;
		int diff = hii - hi;
		cout << "+ " << diff << endl;
		int res; cin >> res;

		hi = hii; lo = loo;
		if(res > tier) lo = (tier + 1) * n;
		else hi = (tier + 1) * n - 1;
	}
	cout << "! " << lo << endl;
}
