#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)
#define ends(v) v.begin(),v.end()

void solve() {
    int s, n; cin >> s >> n;
    int pw = 1;
    vector<int> vals;
    while(s) {
        forr(i, s%10) vals.push_back(pw);
        pw *= 10;
        s /= 10;
    }
    while(vals.size() > n) {
        reverse(vals.begin(), vals.end());
        int a = vals.back(), b = vals[vals.size()-2];
        vals.pop_back();
        vals.pop_back();
        vals.push_back(a+b);
    }
    while(vals.size() < n) {
        forr(i, vals.size()) {
            if(vals[i] > 1) {
                int v = vals[i];
                vals.erase(vals.begin()+i);
                forr(i, 10) {
                    vals.push_back(v/10);
                }
                break;
            }
        } 
        sort(ends(vals));
    }
    while(vals.size() > n) {
        reverse(vals.begin(), vals.end());
        int a = vals.back(), b = vals[vals.size()-2];
        vals.pop_back();
        vals.pop_back();
        vals.push_back(a+b);
    }
    for(int x: vals) cout << x << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
