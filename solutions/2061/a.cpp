#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int odds = 0, evens = 0;
    for(int x: a) odds += x % 2, evens += (x % 2) ^ 1;
    if(evens) cout << odds + 1 << '\n';
    else cout << odds - 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
