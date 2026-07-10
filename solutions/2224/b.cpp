#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    vi a(n); 
    for(int &x: a) cin >> x;
    sort(all(a));
    int ma = *max_element(all(a));
    vector<ll> ans; 
    ans.push_back(ma);
    map<int, int> freq;
    for(int x: a) freq[x]++;
    freq[ma]--;
    for(int cur = 0; cur<n+1; cur++) {
        if(freq[cur]) {
            freq[cur]--;
            ans.push_back(cur);
        } else break;
    }
    for(auto [el, c]: freq) for(int i = 0; i<c; i++) ans.push_back(el);

    set<int> s; 
    for(int i = 0; i<n+1; i++) s.insert(i);
    ll to = 0, m = 0;
    for(ll x: ans) {
        m = max(m, x);
        s.erase(x);
        to += m + *s.begin();
    }
    cout << to << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
