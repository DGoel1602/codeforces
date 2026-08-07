#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void RunAlice() {
	ll x; cin >> x;
	--x;
	vector<int> s;
	vector<int> l4(4);
	for(int i = 0; i<15; i++) if(x & (1 << i)) {
		s.push_back(i + 1);
		for(int j = 0; j<4; j++) l4[j] ^= ((i+1) & (1 << j)) != 0;
	}
	int fx = 0;
	for(int i = 0; i<4; i++) if(l4[i]) {
		s.push_back(16 + i);
		fx ^= 1;
	}
	if(fx) s.push_back(20);
	cout << s.size() << '\n';
	for(int x: s) cout << x << " ";
	cout << '\n';
}

void RunBob() {
	int n; cin >> n;
	vector<int> f(20);
	for(int i = 0; i<n; i++) {
		int x; cin >> x;
		--x;
		f[x] = 1;
	}
	vector<int> l4(4);
	int x = 0;
	for(int i = 0; i<15; i++) if(f[i]) {
		x |= (1 << i);
		for(int j = 0; j<4; j++) l4[j] ^= ((i+1) & (1 << j)) != 0;
	}
	int fx = 0;
	for(int i = 0; i<4; i++) fx ^= f[15 + i];
	if(fx != f[19]) return void(cout << x + 1 << '\n');
	int diff = 0;
	for(int i = 0; i<4; i++) if(l4[i] != f[15 + i]) diff |= (1 << i);
	if(diff) x ^= (1 << (--diff));
	cout << x + 1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string run; cin >> run;
	int t; cin >> t;
	while(t--) {
		if(run == "first") RunAlice();
		else RunBob();
	}
}
