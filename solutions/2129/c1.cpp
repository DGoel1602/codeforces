#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int qr(int l, int r) {
    cout << "? " << r - l + 1 << " ";
    for(int i = l; i<=r; i++) cout << i << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}

int ffe(int n) {
    int full = qr(1, n);
    if (!full) return 0;
    int lo = 0, hi = n - 1;
    while(lo != hi) {
        int mid = lo + (hi - lo) / 2;
        int r = qr(1, mid + 1);
        if(!r) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void solve() {
    int n; cin >> n;
    int fe = ffe(n);
    string s;
    for(int i = 0; i<n; i++) s.push_back(')');
    for(int i = 0; i<n; i += 2) {
        int a = i, b = i + 1;
        if(b == n) b = 0;

        cout << "? " << 6 << " " << a + 1 << " " << fe + 1 << " " << b + 1 << " " << b + 1 << " " << fe + 1 << " " << fe + 1 << endl;
        int res; cin >> res;
        if(res == 4) {
            s[a] = '(';
            s[b] = '(';
        } else if(res == 1) {
            s[a] = '(';
            s[b] = ')';
        } else if(res == 2) {
            s[a] = ')';
            s[b] = '(';
        } else {
            assert(res == 0);
            s[a] = ')';
            s[b] = ')';
        }
    }
    cout << "! " << s << endl;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// _)__))

// ()(()) - 4
// ())))) - 1
// ))(()) - 2
// )))))) - 0


// 0000 - (((( - 0
// 0001 - ((() - 1
// 0010 - (()( - 1
// 0011 - (()) - 2
// 0100 - ()(( - 1
// 0101 - ()() - 3
// 0110 - ())( - 1
// 0111 - ())) - 1
// 1000 - )((( - 0
// 1001 - )(() - 1
// 1010 - )()( - 1
// 1011 - )()) - 1
// 1100 - ))(( - 0
// 1101 - ))() - 1
// 1110 - )))( - 0
// 1111 - )))) - 0

// (())()
// _)__))

// () - 1
// (( - 0
// ))
// )(
