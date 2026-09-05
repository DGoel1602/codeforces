#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int xo = 0;
        for(int i = 0; i<n; i++) {
            int x; cin >> x;
            xo ^= x;
        }
        if(xo == 0) cout << "1\n";
        else cout << "0\n";
    }
}
