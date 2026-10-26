#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    ll cur = 1;
    for(int i = 0; i < n-1; i++) cur = (2*cur) % 998244353;
    cout << cur << '\n';
}
