#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i< b; ++i)

void solve() {
    string s; cin >> s;
    int n = s.size();
    pair<int, int> best = {0, 0};
    int str = 0;
    for(int end = n-1; end>=0; end--) {
        int cur = 0;
        for(int start = end; start >= 0; start--) {
            int len = end - start + 1;
            if(s[start] != s[n-len]) cur++;
            else cur = 0;
            if(cur) {
                if(len > best.second - best.first + 1) best = {start, end}, str = cur;
                else if(len == best.second - best.first + 1 && cur > str) best = {start, end}, str = cur;
            }
        }
    }
    cout << 1 << " " << n << " " << best.first + 1 << " " << best.second + 1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
