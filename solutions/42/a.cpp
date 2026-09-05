#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
	int n, v; cin >> n >> v;
	vector<double> a(n), b(n);
	for(double &x: a) cin >> x;
	for(double &x: b) cin >> x;
	int minidx = 0;
	for(int i = 1; i<n; i++) if(b[i] / a[i] < b[minidx] / a[minidx]) minidx = i;
	double prop = b[minidx]/a[minidx];
	double res = accumulate(all(a), 0.0) * prop;
	cout << min(res, (double)v) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
