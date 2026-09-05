#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define int ll

vector<int> primes;

void solve() {
    unordered_map<int, int> m;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for(int p: primes) {
            if(p * p > a) break;
            if(a % p == 0) m[p]++;
            while(a % p == 0) a /= p;
        }
        if(a != 1) m[a]++;
    }

    ll s = 0;
    for(auto x : m) {
        s += (x.second + 2) / 3;
    }

    cout << s << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<bool> isprime(1000001, true);
    isprime[0] = isprime[1] = false;
    for(ll i = 2; i <= 1000000; i++) {
        if(!isprime[i]) continue;
        for(int p = i*i; p <= 1000000; p+=i) isprime[p] = false;
        primes.push_back(i);
    }

    int t; cin >> t;
    while(t--) solve();
}
