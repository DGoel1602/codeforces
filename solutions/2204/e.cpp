#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

map<int, vector<pair<vi, string>>> m;
void solve() {
    string s; cin >> s;
    if(sz(s) == 1) return void(cout << s << "\n");
    vi freq(10, 0);
    int su = 0;
    for(char c: s) freq[c - '0']++, su += c - '0';
    auto res = m[su];
    for(auto [hf, str]: res) {
        bool works = true;
        bool oz = true;
        rep(i, 0, 10) {
            if(hf[i] > freq[i]) {
                works = false;
                break;
            }
            if(i > 0 && freq[i] > hf[i]) oz = false;
        }
        if(!works || oz) continue;
        rep(i, 0, 10) freq[i] -= hf[i];
        for(int i = 9; i>=0; i--) {
            for(int j = 0; j<freq[i]; j++) cout << i;
        }
        cout << str << "\n";
        break;
    }
}

int sum(int x) {
    int s = 0;
    while(x > 0) s += x % 10, x /= 10;
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int siz = 9 * 1e5 + 1;
    rep(i, 0, siz) {
        int x = i;
        int su = x;
        string str = "";
        vi freq(10);

        while(x) {
            int xx = x;
            while(xx > 0) freq[xx % 10]++, xx /= 10;
            su += sum(x);
            str += to_string(x);
            if(x < 10) break;
            x = sum(x);
        }

        m[su].push_back({freq, str});
    }

    int t; cin >> t;
    while(t--) solve();
}
