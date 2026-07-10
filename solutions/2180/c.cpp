#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> res(k, 0);
    for(int i = 31-__builtin_clz(n); i>=0; i--) {
        int c = 0, l = -1;
        for(int j = 0; j<k; j++) {
            if(res[j] + (1 << i) <= n) {
                res[j] += (1 << i);
                c ^= 1; 
                if(l == -1 || res[l] < res[j]) l = j;
            }
        }
        if(c != ((n >> i) & 1)) {
            res[l] -= (1 << i);
        }
    }
    for(int x: res) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
