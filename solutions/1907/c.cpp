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
	string s; cin >> s;
	vector<int> freq(26);
	for(char c: s) freq[c - 'a']++;
	sort(all(freq));
	int ma = *max_element(all(freq));
	int rest = accumulate(all(freq), 0) - ma;
	cout << max((int)s.size() - rest * 2, n % 2) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
