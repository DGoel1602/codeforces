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
    int n; cin >> n;
    string s; cin >> s;
    vi dp(n, 0);
    dp[0] = (s[0] - '0') ^ 1;
    for(int i = 1; i<n; i++) {
        if(s[i] == '1') dp[i] = 0;
        else dp[i] = dp[i-1] + 1;
    }
    int ma = 0, ma2 = 0;
    for(int i = 0; i<n; i++) {
        if(dp[i] > ma) ma = dp[i];
        else break;
    }
    for(int i = n-1; i>=0; i--) {
        if(dp[i] > ma2) ma2 = dp[i];
        else break;
    }
    cout << max(*max_element(all(dp)), ma + ma2) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
