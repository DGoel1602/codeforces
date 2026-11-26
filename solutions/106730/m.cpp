#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll x, y;
    cin >> x >> y;

    ll cur = y-1;
    for(ll k = 1; k <= x; k++) {
        if(cur % (x-1) == 0) return (cout << (cur/(x-1) + k*y) << '\n', 0);
        cur += y-1;
    }
}
