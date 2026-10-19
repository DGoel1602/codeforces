#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

int get_idx(char c) {
    if(c == 'I') return 0;
    if(c == 'C') return 1;
    return 2;
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    auto works = [&](int m) -> pair<vector<pair<int, int>>, vector<pair<int, int>>> {
        int i = 0, j = n-1, f = 0;
        queue<int> cur;
        vector<pair<int, int>> cs, ps;
        vector<int> used(n);
        for(; i<n; i++) {
            if(s[i] == 'I') cur.push(i);
            else if(s[i] == 'C' && cur.size()){
                cs.push_back({cur.front(), i});
                used[cur.front()] = used[i] = 1;
                cur.pop();
                f++;
            }
            if(f == m) break;
        }
        
        f = 0, cur = queue<int>();
        for(; j>=0; j--) if(!used[j]) {
            if(s[j] == 'C') cur.push(j);
            else if(s[j] == 'P' && cur.size()){
                ps.push_back({j, cur.front()});
                cur.pop();
                f++;
            }
            if(f == m) break;
        }
        reverse(ps.begin(), ps.end());
        if(i == n || j == -1 || cs.size() != ps.size()) {
            return {{}, {}};
        }
        for(int i = 0; i<cs.size(); i++) if(cs[i].second > ps[i].first) {
            return {{}, {}};
        }
        return {cs, ps};
    };

    int lo = 0, hi = s.size();
    while(lo != hi) {
        int m = lo + (hi - lo + 1) / 2;
        auto [cs, ps] = works(m);
        if(!cs.size()) hi = m - 1;
        else lo = m;
    }
    auto [cs, ps] = works(lo);
    cout << lo << '\n';
    for(int i = 0; i<cs.size(); i++) {
        cout << cs[i].first + 1 << " " << cs[i].second + 1 << " " << ps[i].first + 1 << " " << ps[i].second + 1 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
