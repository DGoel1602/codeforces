
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
    vector<int> nums(n);
    for(int &x: nums) cin >> x;
    int c = 0;
    for(int i = 0; i<n-1; i++) {
        if(abs(nums[i] - nums[i+1]) == __gcd(nums[i], nums[i+1])) c++;
    }
    cout << c << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
