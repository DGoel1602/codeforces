#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using B = bitset<5000>;

mt19937 rng(time(NULL));

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<B> a(n);
    for(int i = 0; i<n; i++) {
        string s; cin >> s;
        s[i] = '1';
        reverse(s.begin(), s.end());
        a[i] = B(s);
    }
    vector<int> res;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    shuffle(ord.begin(), ord.end(), rng);
    for(int i : ord) {
        B b = a[i];
        for(int j = 0; j<n; j++) if(i != j && a[i][j]) {
            b |= a[j];
        }
        if(b.count() == n) res.push_back(i + 1);
        if(res.size() >= 3) break;
    }    
    if(res.size() < 3) return (cout << "NOT FOUND\n", 0);
    for(int x: res) cout << x << " ";
    cout << '\n';
}
