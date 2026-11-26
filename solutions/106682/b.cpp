#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

signed main() {
    string s; cin >> s;
    set<string> pos;
    for(int i = 0; i<((int)s.size())-4; i++) {
        if(s.substr(i+1, 3) == "GAS" && isVowel(s[i]) && s[i] == s[i+4]) {
            pos.insert(s.substr(0, i+1) + s.substr(i + 5));
        }
    }
    if(pos.size() > 1) cout << "+\n";
    else if(pos.empty()) cout << "-\n";
    else cout << *pos.begin() << '\n';
}
