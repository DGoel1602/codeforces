#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define sz(x) (int)((x).size())

const vector<string> o13 = {"1z","2z","3z","4z","5z","6z","7z","1p","9p","1s","9s","1m","9m"};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        map<string, int> cards;
        for (int i = 0; i < 28; i += 2) {
            string c = "";
            c += s[i];
            c += s[i+1];
            cards[c]++;
        }
        bool f = (sz(cards) == 13);
        for (auto c : o13) {
            f &= (cards.count(c));
        }

        if (f) {cout << "Thirteen Orphans\n"; continue;}
        f = (sz(cards)==7);
        for (auto [c, n] : cards) f &= (n==2);
        if (f) cout << "7 Pairs\n";
        else cout << "Otherwise\n";
    }
}
