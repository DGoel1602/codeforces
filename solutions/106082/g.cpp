#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll n, k; cin >> n >> k;
	vector<ll> primes(k);
	for(ll &x: primes) cin >> x;
	ll l = 0, r = 8e18;
	while(l <= r) {
		ll mid = (l + r) / 2;
		ll removed = 0;
		bool skip = false;
		for(int i = 1; i<(1 << k); i++) {
			ll total = 1;
			for(int j = 0; j<k; j++) {
				if((i >> j) & 1) total *= primes[j];
			}
			ll under = mid / total;
			if(total > 0 && mid % total == 0) skip = true;
			if(__builtin_popcount(i) % 2 == 1) removed += under;
			else removed -= under;
		}
		ll nth = mid - removed;

		if(nth == n) {
			if(skip) {
				r = mid - 1;
				continue;
			}
			cout << mid << "\n";
			return 0;
		}
		if(nth < n) l = mid + 1;
		else r = mid - 1;
	}
}
