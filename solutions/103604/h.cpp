#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int &x: a) cin >> x;
	long long sum = 0;
	for(int x: a) sum += x;
	double ret = 0;
	for(int step = 0; step<n-1; step++) {
		double probA = 1.0 / (n - step);
		double probB = (1 - (1.0 / (n - step))) * (1.0 / (n - step - 1));
		ret += (probA + probB) * sum;		
	}
	cout << setprecision(10) << fixed << ret << '\n';
}
