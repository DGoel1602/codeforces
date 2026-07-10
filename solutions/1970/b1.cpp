#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    cout << "YES\n";
    for(int i = 0; i<n; i++) cout << i + 1 << " " << i + 1 << '\n';
    for(int i = 0; i<n; i++) {
        int x = a[i];
        if(i + 1 + x / 2 <= n) cout << i + 1 + x / 2 << ' ';
        else cout << i + 1 - x / 2 << ' ';
    }
}
