#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using ll = long long;

struct FT {
    ll n;
    vector<ll> a;
    FT(int n): a(n) {}
    int query(int r) {
        int sum = 0;
        for(; r > 0; r &= r - 1) sum += a[r-1];
        return sum;
    }
    void add(int i, int x) {
        for(; i < a.size(); i |= i + 1) a[i] += x;
    }
};

int main() {
    int n; cin >> n;
    FT ft(n);
    int res = 0;
    for(int i =0 ; i<n; i++) {
        int x; cin >> x;
        res += i - ft.query(x);
        ft.add(x, 1);
    }
    cout << (res % 2 ? "Smokin Joe!" : "Oh No!") << '\n';
}

// 3 4 1 2
//
