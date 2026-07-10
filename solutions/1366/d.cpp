#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int sz = 1e7;
vector<int> sieve(sz + 1, 1);
vector<int> sp(sz + 1, 0);

pair<int, int> solve() {
    int n; cin >> n;
    if(sieve[n]) return {-1, -1};

    int on = n;
    int a1 = 1, a2 = 1;
    int spp = sp[n];
    while(n % spp == 0) a1 *= spp, n /= spp;
    a2 = on / a1;
    if(a1 == 1 || a2 == 1) return {-1, -1};
    return {a1, a2};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i = 2; i * i <= sz; i++) {
        if(!sieve[i]) continue;
        for(int j = i * i; j <= sz; j += i) sieve[j] = 0, sp[j] = i;
    }

    int t; cin >> t;
    vector<int> a, b;
    while(t--) {
        pair<int, int> res = solve();
        a.push_back(res.first);
        b.push_back(res.second);
    }
    for(int x: a) cout << x << " ";
    cout << "\n";
    for(int x: b) cout << x << " ";
    cout << "\n";
}
