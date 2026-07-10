#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> freq(26, 0);
    for(char c: s) freq[c - 'a']++;
    vector<pair<int, int>> vec;
    for(int i = 0; i<26; i++) if(freq[i]) vec.push_back({freq[i], i});
    sort(vec.begin(), vec.end());
    pair<char, char> rep;
    rep.first = vec[0].second + 'a';
    rep.second = vec.back().second + 'a';
    for(int i = 0; i<n; i++) {
        if(s[i] == rep.first) {
            s[i] = rep.second;
            break;
        }
    }
    cout << s << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
