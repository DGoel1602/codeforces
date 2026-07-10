#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll k, x;
    cin >> k >> x;
    ll sum = (1LL << (k+1));
    
    ll cur = abs(2*x - sum);
    ll a = x, b = sum - x;

    vector<int> res;
    while(cur != 0) {
        ll dif = abs(2*cur - sum);
        if(b > a) {
            b -= a, a *= 2;
            res.push_back(1);
        } else {
            a -= b, b *= 2;
            res.push_back(2);
        }
        cur = dif;
    }

    cout << res.size() << '\n';
    reverse(res.begin(), res.end());
    for(int r : res) cout << r << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
