#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int blah = (1<<26)+5;
//bitset<blah> bs;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;

    vector<int> m((1<<26)+5,-2);
 //   m.reserve(1<<22);
    m[0] = -1;
    int res = 0;
    int last = 0;

    for (int x = 0; x < n; x++) {
        last ^= (1 << (s[x]-'a'));
        //cout << "last: " << last << "\n";
        for (int i = -1; i < 26; i++) {
            int check = last;
            if (i >= 0)
                check ^= (1<<i);
            if (m[check] != -2) {
                //cout << "found " << check << " at index " << m[check] << "\n";
                res = max(res, x - m[check]);
                //break;
            }
        }
        if (m[last] == -2) {
            m[last] = x;
            //cout << "inserted " << last << " with index " << x << "\n";
        }
    }

    cout << res;
}
