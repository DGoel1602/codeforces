#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> freq(26, 0);
    string s; cin >> s;
    for(char c : s) freq[c-'a']++;
    int odd = 0;
    for(int i = 0; i < 26; i++) if(freq[i] % 2) odd++;
    if(k < odd-1) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
