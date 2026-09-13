#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<char>> res(n, vector<char>(n, '#'));
    int ci = n / 2, cj = n / 2;
    int dir = 0;
    int done = 0;
    int dist = 0;
    for(int i = 0; i<s.size(); i++) {
        auto [dx, dy] = dirs[dir];
        if(i % 2 == 0) dist++;
        for(int j = 0; j<dist && done < s.size(); j++) {
            res[ci][cj] = s[done];
            done++;
            ci += dx, cj += dy;
        }
        if(i + dist >= s.size()) break;
        dir = (dir + 1) % 4;;
    }
    // for(auto vec: res) {
    //     for(char c: vec) cout << c << " ";
    // cout << '\n';
    // }
    for(auto vec: res) {
        for(char c: vec) if(c != '#') cout << c;
    }
    cout << '\n';
}
