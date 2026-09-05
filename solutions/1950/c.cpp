#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
	string s; cin >> s;
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(3, 2));
	int oa = a;
	a = a % 12;
	if(a == 0) a = 12;
	cout << (a < 10 ? "0" : "") << a << ":" << (b < 10 ? "0" : "") << b << " " << (oa >= 12 ? "PM" : "AM") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
