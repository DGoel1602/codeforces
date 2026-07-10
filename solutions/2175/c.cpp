#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string a, b;
    cin >> a >> b;
    vector<int> freq(26, 0);
    for(char c : a) freq[c-'a']--;
    for(char c : b) freq[c-'a']++;
    for(int i = 0; i < 26; i++) {
        if(freq[i] < 0) {
            cout << "Impossible\n";
            return;
        }
    }
    
    int ap = 0, idx = 0;
    for(int i = 0; i < b.size(); i++) {
        while(idx < 26 && freq[idx] == 0) idx++;
        if(ap < a.size() && a[ap]-'a' <= idx) {
            cout << a[ap];
            ap++;
        } else {
            cout << (char)('a' + idx);
            freq[idx]--;
        }
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
