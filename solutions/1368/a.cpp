#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int cnt = 0;
    int oa = a, ob = b;
    while(a <= c && b <= c) {
        if(cnt % 2) b += a;
        else a += b;
        cnt++;
    }
    a = oa, b = ob;
    int cnt2 = 0;
     while(a <= c && b <= c) {
        if(cnt2 % 2 == 0) b += a;
        else a += b;
        cnt2++;
    }
    cout << min(cnt, cnt2) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
