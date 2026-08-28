#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
	int n, m; cin >> n >> m;
	set<char> al;
	rep(i, 0, n) {
		string x; cin >> x;
		al.insert(x[0]);
	}
	vector<string> ms;
	rep(i, 0, m) {
		string x; cin >> x;
		ms.push_back(x);
	}
	for(string x: ms) for(char c: x) if(!al.count(c + 32)) return void(cout << "NO\n");
	cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
