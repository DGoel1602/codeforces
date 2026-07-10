#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    int cur = 0;
    int res = 0;
    set<int> sqs;
    for(int i = 1; i<100; i+=2) sqs.insert(i * i);
    for(int i = 0; i<n; i++) {
        int x; cin >> x;
        cur += x;
        if(sqs.count(cur)) {
            res++;
        }
    }
    cout << res << "\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
