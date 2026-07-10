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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int par = 0;
    for(int i = 0; i < n; i++) cin >> a[i], par ^= (a[i] % 2);
    sort(a.begin(), a.end());
    a.back()--;
    sort(a.begin(), a.end());
    if(a.back() - a[0] > k) return void(cout << "Jerry\n");
    else cout << (par ? "Tom\n" : "Jerry\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
