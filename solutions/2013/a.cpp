#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << (n + min(x, y) - 1) / min(x, y) << '\n';
    }
}
