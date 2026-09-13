#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

vector<int> d, res;
bool verify(int pos) {
    int tot = 0, lp = 0, rp = pos;
    while(lp <= pos) {
        int a = (lp >= sz(res) ? 0 : res[lp]);
        int b = (rp >= sz(res) ? 0 : res[rp]);
        tot += a*b;
        lp++, rp--;
    }
    return (tot % 10 == d[pos]);
}

vector<ll> sol;

bool solve(int x) {
    if(x == sz(res)) {
        for(int i = x; i < sz(d); i++) {
            if(!verify(i)) return false;
        }
        return true;
    }

    for(int i = 0; i < 10; i++) {
        res[x] = i;
        if(verify(x) && solve(x+1)) return true;
    }
    return false;
}

int main() {
    string s; cin >> s;
    if(sz(s) % 2 == 0) return (cout << -1 << endl, 0);

    d = vector<int>(sz(s));
    res = vector<int>((sz(s)+1)/2);
    for(int i = 0; i < sz(s); i++) d[i] = s[i]-'0';

    if(!solve(0)) return (cout << -1 << endl, 0);
    for(int x : res) cout << x;
    cout << endl;
}
