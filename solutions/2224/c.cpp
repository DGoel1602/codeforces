#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int c1 = 0, c2 = 0, sw = 0;
    for(int i = 0; i<n; i++) {
        int ch1 = s[i] == ')' ? -1 : 1;
        int ch2 = t[i] == ')' ? -1 : 1;
        sw += s[i] != t[i];
        c1 += ch1, c2 += ch2;
        if(c1 < 0 && c2 < 0) return void(cout << "NO\n");
        if(c1 < 0) {
            int req = (abs(c1)+1)/2;
            if(c2 - 2 * req < 0 || req > sw) return void(cout << "NO\n");
        }
        if(c2 < 0) {
            int req = (abs(c2)+1)/2;
            if(c1 - 2 * req < 0 || req > sw) return void(cout << "NO\n");
        }
    }
    if(c1 != -c2) return void(cout << "NO\n");
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
