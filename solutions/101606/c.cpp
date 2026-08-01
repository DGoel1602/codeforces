#include <bits/stdc++.h>
using namespace std;

int conv(string s) {
    if(s == "red") return 0;  
    if(s == "yellow") return 2;  
    if(s == "green") return 3;  
    if(s == "brown") return 4;  
    if(s == "blue") return 5;  
    if(s == "pink") return 6;  
    if(s == "black") return 7;  
    return 0;
}

int main() {
    int n; cin >> n;
    int su = 0, h = 0, r = 0;
    for(int i = 0; i<n; i++) {
        string s; cin >> s;
        su += conv(s);
        h = max(h, conv(s));
        r += s == "red";
    }
    if(h == 0) cout << 1 << '\n';
    else cout << (h + 1) * r + su << '\n';
}
