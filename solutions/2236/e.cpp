#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int &x: a) cin >> x;

	vector<int> idxsmi(n+5, -1), idxsma(n+5, -1);
	deque<int> mxdq, midq;
	vi freq(n+5);

	for(int len = n-1; len>=1; len--) {
		idxsmi.assign(n+5, -1);
		idxsma.assign(n+5, -1);
		freq.assign(n+5, 0);
		mxdq.clear(); midq.clear();

		int exels = 0;

		int l = 0, r = 0;
		for(; r<len;) {
			while(!mxdq.empty() && a[mxdq.back()] <= a[r]) mxdq.pop_back();
			mxdq.push_back(r);
			while(!midq.empty() && a[midq.back()] >= a[r]) midq.pop_back();
			midq.push_back(r);

			freq[a[r]]++;
			if(freq[a[r]] == 2) exels++;
			
			r++;
		}

		for(; l<(n-len);) {
			int mi = a[midq.front()], mx = a[mxdq.front()];
			int lsmi = idxsmi[mx+1], lsma = idxsma[mi-1];
			if(mx - mi + 1 == len && !exels) {
				if((lsmi != -1 && l - lsmi >= len) || (lsma != -1 && l - lsma >= len)) {
					return void(cout << len << '\n');
				}
				if(idxsmi[mi] == -1) idxsmi[mi] = l;
				if(idxsma[mx] == -1) idxsma[mx] = l;
			}

			if(mxdq.front() == l) mxdq.pop_front();
			if(midq.front() == l) midq.pop_front();

			freq[a[l]]--;
			if(freq[a[l]] == 1) exels--;

			while(!mxdq.empty() && a[mxdq.back()] <= a[l+len]) mxdq.pop_back();
			mxdq.push_back(l+len);
			while(!midq.empty() && a[midq.back()] >= a[l+len]) midq.pop_back();
			midq.push_back(l+len);

			freq[a[l + len]]++;
			if(freq[a[l + len]] == 2) exels++;

			l++;
		}

		int mi = a[midq.front()], mx = a[mxdq.front()];
		int lsmi = idxsmi[mx+1], lsma = idxsma[mi-1];
		if(mx - mi + 1 == len && !exels)
			if((lsmi != -1 && l - lsmi >= len) || (lsma != -1 && l - lsma >= len)) {
				return void(cout << len << '\n');
			}
	}

	cout << 0 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
