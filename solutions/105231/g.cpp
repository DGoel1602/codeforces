#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll ones = 0;
        for(ll i = 0; i<n; i++) {
            ll cnt; cin >> cnt;
            char c; cin >> c;
            if(c != 'A') {
                ones = (ones + (c - '0') * cnt) % 10;
            }
        }
        cout << (ones % 5 == 0 ? "Yes\n" : "No\n"); 
    }
}
