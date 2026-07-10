#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if(n < 6) {
        cout << 1 + n / 2 << '\n';
        cout << "1 ";
        for(int i = 2; i<=n; i++) cout << (i < 4 ? "2 " : "3 ");
        cout << '\n';
        return;
    }
    cout << "4\n";
    for(int i = 1; i <= n; i++)
        cout << ((i % 2) * 2) + 1 + ((i / 2) % 2) << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
