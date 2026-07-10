#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n, r;
        cin >> n >> r;
        int res = 0;
        int rem = r, e = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            res += 2*(x/2);
            rem -= (x/2), e += (x&1);
        }
        while(e > rem) {
            e -= 2, rem--;
        }
        res += e;
        cout << res << '\n';
    }
}
