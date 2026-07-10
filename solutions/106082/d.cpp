#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	int res = 1 << n;
	for(int i = 0; i<(1 << n); i++) {
		int cur = 0, streak = 0;
		for(int j = 0; j<n; j++) {
			if(((i >> j) & 1) == cur) streak++;
			else {
				streak = 1; cur = (i >> j) & 1;
			}
			if(streak > k) {
				res--;
				break;
			}
		}
	}
	cout << res << "\n";
}
