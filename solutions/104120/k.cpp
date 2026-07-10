#include <bits/stdc++.h>
using namespace std;

const vector<int> mp = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    map<string, int> mapping;
    for(int i = 0; i<n; i++) {
        string r = "";
        string s; cin >> s;
        for(char c: s) r += '0' + mp[c - 'a'];
        mapping[r]++;
    }
    for(int i = 0; i<m; i++) {
        string s; cin >> s;
        cout << mapping[s] << '\n';
    }
}
