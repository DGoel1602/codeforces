#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<int> costs(n, 0);
	for(int &x: costs) cin >> x;
	vector<int> gifts(m, 0);
	for(int &x: gifts) cin >> x;
	sort(costs.begin(), costs.end());
	long long res = 0;
	for(int x: gifts) {
		auto it = upper_bound(costs.begin(), costs.end(), x);
		if(it != costs.begin()) {
			it--;
			res += *it;
		}
	}
	cout << res << endl;
}
