#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isprime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    vector<int> primes;
    int d; cin >> d;
    for(int i = 2; i <= d; i++) {
        if(isprime(i)) primes.push_back(i);
    }
    int n = primes.size();
    vector<ll> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        ll res = 0;
        for(int j = 0; j < i; j++) {
            if(primes[i] - primes[j] > 14) continue;
            res += dp[j];
        }
        dp[i] = res;
    }
    cout << dp[n-1] << '\n';
}
