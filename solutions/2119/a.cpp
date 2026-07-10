#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if(a == b) return void(cout << "0\n");
    if(a > b) {
        if(a == b + 1 && (a & 1)) return void(cout << y << "\n");
        else return void(cout << "-1\n");
    }
    int mv = 0;
    while(a < b) {
        if(a & 1) a++, mv += x;
        else a++, mv += min(x, y);
    }
    cout << mv << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
