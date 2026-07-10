#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vi freq(4, 0);
    int state = 0;
    for(int i = 0; i<(n-1); i++) {
        freq[a[i]]++;
        if(state == 0 && freq[1] >= (i+1+1)/2) {
            if(a[i+1] == 3 && freq[2] + freq[3] < freq[1]) continue; 
            state = 1;
            freq = vector<int>(4, 0);
        }
        else if(state == 1 && freq[1] + freq[2] >= freq[3]) return void(cout << "YES\n");
    }
    cout << "NO\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
