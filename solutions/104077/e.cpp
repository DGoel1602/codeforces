#include <bits/stdc++.h>
using namespace std;
#define ll long long

string base3(ll x) {
    string res;
    for(; x; x /= 3) res += (char)('0' + (x % 3));
    return res;
}

bool compare(string &a, string &b) {
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    for(int i = a.size()-1; i >= 0; i--) {
        if(a[i] < b[i]) return true;
        if(a[i] > b[i]) return false;
    }
    return true;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    string ogr = base3(r);
    string ld = base3(l), rd = base3(r);
    
    for(int p = 0; p < rd.size(); p++) {
        if(rd[p] != '2') {
            bool good = false;
            for(int j = p+1; j < rd.size(); j++) {
                if(rd[j] != '0') good = true;
            }
            if(!good) break;
            string ns(rd);
            ns[p] = '2';
            for(int j = p+1; j<ns.size(); j++) {
                if(ns[j] != '0') {
                    ns[j]--;
                    break;
                } else ns[j] = '2';
            }
            if(!compare(ld, ns)) break;
            swap(ns, rd);
        }
    }
    
    ll res = 0;
    int nz = 0;
    for(int i = rd.size()-1; i >= 0; i--) {
        if(rd[i] != '0') nz = rd[i]-'0';
        if(nz) res++;
        res += rd[i]-'0';
    }

    if(nz == 2) {
        string ns(rd);
        for(int i = rd.size()-1; i >= 0; i--) {
            if(ns[i] != '0') {
                ns[i] = '1';
                if(i == rd.size()-1) ns += '1';
                else ns[i+1] = '1';
                break;
            }
        }
        if(compare(ns, ogr)) {
            swap(ns, rd);
            res = 0;
            for(int i = rd.size()-1; i >= 0; i--) {
                if(rd[i] != '0') nz = rd[i]-'0';
                if(nz) res++;
                res += rd[i]-'0';
            }
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
