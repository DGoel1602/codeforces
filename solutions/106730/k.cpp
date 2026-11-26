#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    vi vm(1);
    for (int i = 0; i < 26; i++) vm.push_back(1 << i);

    vi g1, g2;
    vector<string> s1, s2;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int msk = 0;
        for (auto c : s) msk ^= (1 << (c - 'a'));
        if (i < 16) {
            g2.push_back(msk);
            s2.push_back(s);
        } else {
            g1.push_back(msk);
            s1.push_back(s);
        }
    }
    
    auto len1 = [&](int mask) -> int {
        int tl = 0;
        for (int i = 0; i < sz(g1); i++) {
            if (mask & (1 << i)) tl += sz(s1[i]);
        }
        return tl;
    };
    auto len2 = [&](int mask) -> int {
        int tl = 0;
        for (int i = 0; i < sz(g2); i++) {
            if (mask & (1 << i)) tl += sz(s2[i]);
        }
        return tl;
    };

    map<int, int> m;
    for (int i = 1; i < (1 << sz(g1)); i++) {
        int cmsk = 0;
        for (int j = 0; j < sz(g1); j++) {
            if (i & (1 << j)) cmsk ^= g1[j];
        }
        if (len1(i) > len1(m[cmsk])) m[cmsk] = i;
    }
    tuple<int, int, int> best = {-1, -1, -1};
    for (int i = 0; i < (1 << sz(g2)); i++) {
        if (i==1 && !m.count(0)) m[0] = 0;
        int cmsk = 0;
        for (int j = 0; j < sz(g2); j++) {
            if (i & (1 << j)) cmsk ^= g2[j];
        }
        for (int j = 0; j < sz(vm); j++) {
            if (m.count(cmsk ^ vm[j])) {
                best = max(best, {len1(m[cmsk ^ vm[j]]) + len2(i), i, m[cmsk ^ vm[j]]});
            }
        }
    }
    auto [l, m2, m1] = best;
    if (l < 0) cout << "impossible\n";
    else {
        cout << "possible" << '\n';
        for (int i = 0; i < sz(g1); i++) {
            if (m1 & (1 << i)) cout << s1[i];
        }
        for (int i = 0; i < sz(g2); i++) {
            if (m2 & (1 << i)) cout << s2[i];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    while (T--) solve();
}
