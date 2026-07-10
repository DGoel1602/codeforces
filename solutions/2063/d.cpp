#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

int n, m;
vi a2, b2;
vi apref, bpref;
int siz = 0;

int f(int i) {
	int j = siz - i;
	if(i*2 + j > n) return -1e9;
	if(j*2 + i > m) return -1e9 + i;
	return apref[i] + bpref[j];
}

template<class F>
int ternSearch(int a, int b, F f) {
	assert(a <= b);
	while (b - a >= 5) {
		int mid = (a + b) / 2;
		if (f(mid) < f(mid+1)) a = mid; // (A)
		else b = mid+1;
	}
	rep(i,a+1,b+1) if (f(a) < f(i)) a = i; // (B)
	return a;
}

void solve() {
	cin >> n >> m;
	vi a(n), b(m);
	for(int &x: a) cin >> x;
	for(int &x: b) cin >> x;

	sort(all(a));
	sort(all(b));
	if(n > m) swap(n, m), swap(a, b);

	int i = 0, j = n-1;
	a2.clear(); b2.clear();
	for(; i < j; i++, j--)
		a2.push_back(a[j] - a[i]);
	i = 0, j = m-1;
	for(; i < j; i++, j--)
		b2.push_back(b[j] - b[i]);

	apref.assign(a2.size() + 1, 0);
	bpref.assign(b2.size() + 1, 0);
	for(int i = 1; i<apref.size(); i++) apref[i] = apref[i-1] + a2[i-1];
	for(int i = 1; i<bpref.size(); i++) bpref[i] = bpref[i-1] + b2[i-1];

	int kmax = min(min(n, m), (n+m)/3);
	cout << kmax << '\n';
	for(int i = 1; i<=kmax; i++) {
		siz = i;
		cout << f(ternSearch(0, siz, f)) << ' ';
	}
	cout << '\n';
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
//  9  8 7 6 5
// 11 10 9 2 1
