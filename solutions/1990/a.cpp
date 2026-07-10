#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> freq(n+1, 0);
    for(int i = 0; i<n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for(int i = n; i>=1; i--) {
        if(freq[i] % 2) return void(cout << "YES\n");
    }
    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
