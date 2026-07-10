#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

struct info {
    bool zeros = false, one = false, twos = false;
};

int at(int x, int i) {
    return (x >> i) & 1;
}

void solve() {
    int query = 0;
    for(int i = 0; i<15; i++) query |= (1 << (i * 2 + 1));
    vector<info> ans(32);

    cout << query << endl;
    int res; cin >> res;
    if(at(res, 0)) ans[0].one = true;
    if(!ans[0].one) {
        if (at(res, 1)) ans[0].twos = true;
        else ans[0].zeros = true;
    }

    for(int i = 2; i<31; i+=2) {
        if(!at(res, i)) ans[i].one = true;
        else {
            if(at(res, i+1)) ans[i].twos = true;
            else ans[0].zeros = true;
        }
    }

    query >>= 1;
    cout << query << endl;
    res; cin >> res;
    if(!at(res, 1)) ans[1].one = true;
    else {
        if (at(res, 2)) ans[1].twos = true;
        else ans[1].zeros = true;
    }

    for(int i = 1; i<31; i+=2) {
        if(!at(res, i)) ans[i].one = true;
        else {
            if(at(res, i+1)) ans[i].twos = true;
            else ans[0].zeros = true;
        }
    }

    cout << "!" << endl;
    int m; cin >> m;
    int first = 0, second = 0;
    for(int i = 0; i<31; i++) {
        if(at(m, i) || ans[i].one || ans[i].twos) first |= (1 << i);
        if(at(m, i) || ans[i].twos) second |= (1 << i);
    }
    cout << first + second << endl;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
