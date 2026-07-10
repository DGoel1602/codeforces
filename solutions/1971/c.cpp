#include <bits/stdc++.h>
using namespace std;

bool in(int a, int b, int c) {
    return c >= min(a, b) && c <= max(a, b);
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if((in(a, b, c) && !in(a, b, d)) || (!in(a, b, c) && in(a, b, d))) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
