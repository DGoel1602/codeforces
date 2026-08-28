#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) {
        for(; pos < sz(s); pos |= pos+1) s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for(; pos > 0; pos &= pos-1) res += s[pos-1];
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    string cp(s);
    reverse(cp.begin(), cp.end());
    vector<set<int>> idxs(26);
    for(int i = 0; i<n; i++) idxs[cp[i]-'a'].insert(i);
    vector<int> a(n);
    for(int i = 0; i<n; i++) {
        a[i] = *(idxs[s[i]-'a'].begin());
        idxs[s[i]-'a'].erase(idxs[s[i]-'a'].begin());
    }

    FT ft(n);
    ll res = 0;
    for(int i = 0; i<n;i++) {
        res += i - ft.query(a[i]);
        ft.update(a[i], 1);
    }
    cout << res << '\n';
}
