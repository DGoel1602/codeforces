#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

signed main() {
    int n; cin >> n;
    
    vector<int> prime(4e5, 1);
    prime[1] = 0;
    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(!prime[i]) continue;
        for(int j = i * i; j<=n; j+=i) prime[j] = 0;
        primes.push_back(i);
    }
    cout << primes.size() << " ";
    for(int x: primes) cout << x << " ";
    cout << '\n';

    cout << "2 1 4\n";
    for(int i = 5; i<n; i+=2) {
        vector<int> nums;
        if(n % 2 == 1 && i == n - 2) {
            nums = {i, i+1, i+2};
        } else nums = {i, i+1};
        int sz = 0;
        for(int x: nums) sz += prime[x] == 0;
        if(sz) {
            cout << sz << " ";
            for (int x : nums)
                if (prime[x] == 0)
                    cout << x << " ";
            cout << '\n';
        }
    }
}
