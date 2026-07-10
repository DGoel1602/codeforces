#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> divs = divisors(n);
        sort(divs.begin(), divs.end());
        int d = divs.size();
        ll maxv = 1;
        for(int i = 1; i < d; i++) {
            if(divs[i] > maxv+1) break;
            maxv += divs[i];
        }
        cout << ((maxv >= n) ? "Yes\n" : "No\n");
    }
}
