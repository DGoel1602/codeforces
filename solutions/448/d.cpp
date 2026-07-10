#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

ll amount(ll n, ll m, ll mid) {
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        res += min(mid / i, m);
    return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, k; cin >> n >> m >> k;

    ll lo = 1, hi = n * m;
	while(lo != hi) {
		ll mid = lo + (hi - lo + 0) / 2;
		ll res = amount(n, m, mid);
		if(res < k) lo = mid + 1;
		else hi = mid;
	}
    cout << lo << "\n";
}
