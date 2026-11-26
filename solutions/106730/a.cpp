#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    map<string, string> mp;
    for(int i = 0; i<n; i++) {
        string w; cin >> w;
        string w2(w);
        for(char &c: w) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = 'a';
        }
        vector<int> idxs;
        for(int j = 0; j<sz(w); j++) if(w[j] == 'y') idxs.push_back(j);
        for(int m = 0; m<(1 << sz(idxs)); m++) {
            string cp(w);
            for(int j = 0; j<sz(idxs); j++) if(m & (1 << j)) cp[idxs[j]] = 'a';
            if(mp.count(cp)) mp[cp] = "-1";
            else mp[cp] = w2;
        }
    }
    for(int i = 0; i<m; i++) {
        int k; cin >> k;
        vector<string> a(k);
        for(string &x: a) cin >> x;
        vector<string> res;

        bool imp = false, amb = false;
        for(string x: a) {
            if(!mp.count(x)) imp = true;
            else if(mp[x] == "-1") amb = true;
            else res.push_back(mp[x]);
        }

        if(imp) cout << "impossible\n";
        else if(amb) cout << "ambiguous\n";
        else {
            cout << "possible ";
            for(string x: res) cout << x << " ";
            cout << '\n';
        }
    }
}
