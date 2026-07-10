#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

// mt19937 rng(time(NULL));
int c = 0, mo = 0;

int query(string s) {
    int n = s.size();
    /*
    int cur = 0, m = 0;
    for(int i = 0; i<n; i++) {
        if(s[i] == '1') cur++;
        else {
            m = max(m, cur);
            cur = 0;
        }
    }
    m = max(m, cur);
    if(m > mo) return 0;
    */

    if(mp.count(s)) return mp[s];
    cout << "? " << s << endl;
    int res; cin >> res;
    assert(res != -1);
    c++;
    return mp[s] = res;
}

int query2(char c, int n) {
    string str;
    for(int i = 0; i<n; i++) str += c;
    cout << "? " << str << endl;
    int res; cin >> res;
    assert(res != -1);
    return mp[str] = res;
}

void solve() {
    int n; cin >> n;
    string str;
    mp.clear();

    mo = 0;
    for(int i = 1; i<=n; i++) {
        if(query2('1', i)) mo++;
        else break;
    }

    for(int i = 0; i<mo; i++) str += '1';

    while(str.size() < n) {
        int q = 0;
        int res = query(str + (char)('0' + q));
        if(res) str += (char)('0' + q);
        else {
            int res = query(str + (char)('0' + (q ^ 1)));
            if(res) str += (char)('0' + (q ^ 1));
            else break;
        }
    }

    string bs;
    while(bs.size() + str.size() < n) {
        int q = 0;
        int res = query((char)('0' + q) + bs + str);
        if(res) bs = (char)('0' + q) + bs;
        else {
            int res = query((char)('0' + (q ^ 1)) + bs + str);
            if(res) bs = (char)('0' + (q ^ 1)) + bs;
            else break;
        }
    }
    // reverse(bs.begin(), bs.end());
    cout << "! " << bs << str << endl;
    //cout << c << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
