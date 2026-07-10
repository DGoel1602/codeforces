#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a, b, k; cin >> a >> b >> k;

	string s, t;
	b--;
	s += '1', t += '1';

	if(k) {
		if(a + b <= k) {
			cout << "No\n";
			return 0;
		}

		if(!a || !b) {
			cout << "No\n";
			return 0;
		}

		s += '1'; t += '0';
		b -= 1; a -= 1;
		for(int i = 0; i<k-1; i++) {
			if(a) a--, s += '0', t += '0';
			else if(b) b--, s += '1', t += '1';
			else {
				cout << "No\n";
				return 0;
			}
		}
		t += '1'; s += '0';
	}

	for(int i = 0; i<a; i++) s += '0', t += '0';
	for(int i = 0; i<b; i++) s += '1', t += '1';
	cout << "Yes\n" << s << "\n" << t << '\n';
}
