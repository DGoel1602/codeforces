#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<array<int, 2>> pos(n);
	for(auto &[a, b]: pos) cin >> a >> b;

	vector<double> dp(n, 1e18);
	dp[0] = 0;
	for(int i = 0; i<n; i++) {
		for(int j = i - 1; j>=max(0, i - k); j--) {
			double dist = ((double)pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]);
			dist += ((double)pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1]);
			dist = sqrt(dist);
			dp[i] = min(dp[i], dp[j] + dist);
		}
	}
	cout << fixed << setprecision(10) << dp[n-1] << endl;
}
