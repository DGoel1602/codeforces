#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int b, int e) {
    int res = 1;
    for(; e; b = (b * b), e /= 2)
        if(e & 1) res = (res * b);
    return res;
}

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> primes;
    vector<int> sieve(1e6, 1);
    for(int i = 2; i<1e6; i++) {
        if(!sieve[i]) continue;
        for(int j = i * i; j<1e6; j += i) sieve[j] = 0;
        primes.push_back(i);
    }

    vector<map<int, int>> pfs(n);
    for(int i = 0; i<n; i++) {
        int x = a[i];
        for(int p: primes) {
            if(p * p > x) break;
            while(x % p == 0) x /= p, pfs[i][p]++;
        }
        if(x > 1) pfs[i][x]++;
    }
    pair<int, int> res;
    for(int i = 0; i<n; i++) {
        int lcm = 1;
        map<int, int> mp;
        for(int j = i; j<n; j++) {
            for(auto [p, cnt]: pfs[j]) {
                if(!mp.count(p)) mp[p] = 1;
                if(mp[p] < modpow(p, cnt)) {
                    lcm = (lcm / mp[p]) * modpow(p, cnt);
                    mp[p] = modpow(p, cnt);
                    if(lcm > k) goto next;
                }
            }
            if(lcm <= k) {
                res.first++;
                res.second += (j - i + 1);
            }
        }
        next:;
    }
    cout << res.first << " " << res.second << '\n';
}
