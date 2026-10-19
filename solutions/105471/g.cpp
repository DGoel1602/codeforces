#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> primes;
vector<int> sieve(1e7, 1);

void solve() {
    ll n; cin >> n;
    ll tmp = n, res = 1;

    for(ll i: primes) {
        if(i*i > tmp) break;
        if(tmp % i == 0) {
            int cnt = 0;
            while(tmp % i == 0) cnt++, tmp /= i;
            res *= (2*cnt+1);
        }
    }
    if(tmp > 1) res *= 3;
    cout << (res+1)/2 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 2; i * i<1e7; i++) {
        if(sieve[i] == 0) continue;
        for(int j = i*i; j<1e7; j+=i) sieve[j] = 0;
    }
    for(int i = 2; i<1e7; i++) if(sieve[i]) primes.push_back(i);

    int t; cin >> t;
    while(t--) solve();
}
