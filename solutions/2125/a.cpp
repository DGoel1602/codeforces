#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> freq(26, 0);
    for(int i = 0; i<n; i++) freq[s[i]-'A']++;
    string res;
    while(freq[19]) res += "T", freq[19]--;
    for(int i = 0; i<26; i++) {
        for(int j = 0; j<freq[i]; j++) res += 'A' + i;
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
