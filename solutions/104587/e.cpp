#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for(auto &vec: mat) for(auto &x: vec) cin >> x;
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<int> plain;
    for(char c: s) {
        if(c == ' ') plain.push_back(36);
        else if(c >= '0' && c <= '9') plain.push_back(c - '0' + 26);
        else plain.push_back(c - 'A');
    }
    while(plain.size() % n) plain.push_back(36);
    vector<int> cipher;
    for(int i = 0; i<(int)plain.size(); i+=n) {
        vector<int> col;
        for(int j = i; j<i+n; j++) col.push_back(plain[j]);
        vector<int> res(n);
        for(int j = 0; j<n; j++) {
            for(int k = 0; k<n; k++) {
                res[j] = (res[j] + col[k] * mat[j][k]) % 37;
            }
        }
        for(int x: res) cipher.push_back(x);
    }
    for(int x: cipher) {
        char c = ('A') + x;
        if(x >= 26 && x < 36) c = '0' + x - 26;
        else if(x == 36) c = ' ';
        cout << c;
    }
    cout << '\n';
}
