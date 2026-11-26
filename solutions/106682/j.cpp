#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    
    vector<bitset<1000>> a (3);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') a[0][i] = 1;
        if (s[i] == 'P') a[1][i] = 1;
        if (s[i] == 'T') a[2][i] = 1;
    }
    vector<bitset<1000>> bl (n+1);
    vector<bitset<1000>> br (n+1);
    for (int t = 0; t <= n; t += 3) {
        for (int l = 0; l <= n-t; l++) {
            int r = l+t;
            bool g = 0;
            if (t == 0) g = 1;
            else {
                if ((bl[l] & br[r]).any()) g = 1;
                if (s[l] != s[r-1]) {
                    int ind;
                    for (int i = 0; i < 3; i++) {
                        if (s[l] != "APT"[i] && s[r-1] != "APT"[i]) ind = i;
                    }
                    if (((bl[l+1]) & a[ind] & (br[r-1]>>1)).any()) g = 1;
                }
            }
            if (g) {
                bl[l][r] = 1;
                br[r][l] = 1;
            }
        }
    }
    if (bl[0][n]) cout << "S\n";
    else cout << "N\n";

}
