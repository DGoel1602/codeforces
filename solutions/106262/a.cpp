#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    if(s.size() % 2) cout << s[s.size()/2] << '\n';
    else cout << ":)\n";
}
