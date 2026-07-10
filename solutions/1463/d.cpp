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
	vi used(2*n, -1);
	for(int &x: a) --x, used[x] = 1;

	vi suf(2*n, 0);
	suf[2*n-1] = used[2*n-1];

	int mi = 0;
	set<int> nec;
	set<int> ex;

	for(int i = 2*n-2; i>=0; i--)
		suf[i] = suf[i+1] + used[i];
	for(int i = 2*n-1; i>=0; i--) if(suf[i] < mi) {
			mi = suf[i];
			nec.insert(i);
		}

	set<int> pos;
	rep(i, 0, 2*n) if(used[i] == 1) pos.insert(i);
	int res = 0;
	int req = nec.size();

	for(int i = 2*n-1; i>=0; i--) if(used[i] == -1) {
		while(pos.size() && *prev(pos.end()) > i) pos.erase(prev(pos.end()));
		if(pos.size()) {
			pos.erase(prev(pos.end()));
			res++;
			if(nec.size()) {
					if(*prev(nec.end()) <= i) nec.erase(prev(nec.end()));
					else return void(cout << "0\n");
			}
		}
	}
	cout << res - req + 1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) solve();
}
