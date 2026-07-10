#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int f1[26] = {0}, f2[26] = {0};
    for(int i = 0; i<n; i++) {
        f1[s[i]-'a']++;
        f2[t[i]-'a']++;
    }
    int m1 = 0, m2 = 0;
    for(int i = 0; i<26; i++) {
        m1 = max(m1, f1[i]);
        m2 = max(m2, f2[i]);
    }
    double p1 = ((double)m1) / n, p2 = ((double)m2) / n;
    const double ideal = 1.0/26; 
    double d1 = abs(p1 - ideal), d2 = abs(p2 - ideal);
    cout << (d1 > d2 ? "Corrupted Odyssey" : "Random Gibberish") << "\n";
    cout << (d1 <= d2 ? "Corrupted Odyssey" : "Random Gibberish") << "\n";
}
