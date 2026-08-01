#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    string cp(s);
    sort(cp.begin(), cp.end());
    vector<pair<int, int>> sw;
    for(int i = 0; i<s.size(); i++) {
        for(int k = 0; k<s.size(); k++) if(cp[k] != s[k]) {
            for(int j = k+1; j<s.size(); j++) {
                if(cp[k] == s[j]) {
                    sw.push_back({j+1, k+1});
                    swap(s[k], s[j]);
                    goto next;
                }
            }
        }
        break;
        next:;
    }
    reverse(sw.begin(), sw.end());
    for(auto x : sw) cout << x.first << ' ' << x.second << '\n';
}
