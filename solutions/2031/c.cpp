#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    if(n % 2 && n < 26) return void(cout << "-1\n");
    int cur = 1;
    if(n%2) {
        a[0] = a[9] = a[25] = 1;
        a[22] = a[26] = 2;
        cur = 3;
    }
    for(int i = 0; i<n; i++) {
        if(a[i]) continue;
        a[i] = a[i+1] = cur++;
    }
    for(int x: a) cout << x << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
