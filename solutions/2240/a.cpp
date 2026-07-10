#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 0, res = 0;
    for(int b = 1; b <= n; b *= 2) {
        for(int i = 0; i < k; i++) {
            if(sum+b <= n) {
                res++;
                sum += b;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
