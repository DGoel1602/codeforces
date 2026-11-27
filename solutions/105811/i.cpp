#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	if(n == 1) return (cout << "0\n", 0);

	map<int, int> freq;
	int ts = 0;
	for(int i = 0; i<n; i++) {
		int x; cin >> x;
		ts += x;
		freq[x]++;
	}
	int mex = 0;
	while(freq.count(mex)) mex++;

	if(!ts) return (cout << "0\n", 0);

	int res = mex;
	while((--freq.end())->first > mex) {
		auto it = freq.lower_bound(mex);
		res += mex * (it->first - mex - 1);

		it->second--;
		if(!it->second) freq.erase(it->first);

		freq[mex]++;
		while(freq.count(mex)) mex++;

		res += mex;
	}

	//cout << res << '\n';
	//for(auto [el, cnt]: freq) cout << el << " " << cnt << '\n';

	for(auto &[el, cnt]: freq) {
		res += (cnt - 1) * el * mex;
		freq[el] = 1;
	}

	//cout << res << '\n';
	//for(auto [el, cnt]: freq) cout << el << " " << cnt << '\n';

	for(auto [el, _]: freq) {
		if(el == 1) continue;
		res += el * el;
	}

	cout << res << '\n';
	//for(auto [el, cnt]: freq) cout << el << " " << cnt << '\n';
}

// 0 1 3 - 2
// 0 1 2 - 3
// 0 1 1 - 2
// 0 1 0 - 2
// 0 0 0 - 1

// 0 1 3 4 - 2
// 0 1 2 4 - 3
// 0 1 2 3 - 4
// 0 1 2 2 - 3
// 0 1 2 1 - 3
// 0 1 2 0 - 3
// 0 1 1 0 - 2
// 0 1 0 0 - 2
// 0 0 0 0 - 1
