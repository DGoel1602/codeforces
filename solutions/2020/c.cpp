#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

ll at(ll x, ll i) {
    return (x >> i) & 1LL;
}

void solve() {
    ll b, c, d; cin >> b >> c >> d;
    ll a = 0;
    rep(i, 0, 63) {
        if(at(d, i) && !at(c, i) && !at(b, i)) a |= (1LL << i);
        if(!at(d, i)) {
            if(at(b, i) && at(c, i)) a |= (1LL << i);
            if(at(b,i) && !at(c, i)) return void(cout << "-1\n");
        }

        if(at(d, i) && !at(b, i) && at(c, i)) return void(cout << "-1\n");
    }
    cout << a << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


// 100|1010 = 1110
// 100&010 = 0
// 1110


// d = 1111000101
// c = 1001010101
// b = 0101010000
// a = 

// b = 01 -> 1
// c = 10 -> 2
// d = 10 -> 2


// if in d: in a|b and not in a&c, 
    // if in both b and c simply make it not be in a
    // if in b and not in c, make it not in a
    // if not in b but in c, idk
    // if in neither, make it be in a

// if not in d: in both or neither
    // if in both b and c: make it in a
    // if in b and not in c: idk
    // if not in b and in c: make it not in a
    // if in neither, make it not in a


// case 1.3: 
    // d = 1
    // c = 1
    // b = 0
    // a = ?
    // (?|0) - (?&1) = 1
