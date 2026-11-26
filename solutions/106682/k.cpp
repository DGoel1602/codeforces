#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i<=8; i++) {
        mp[(i*2)%9] = i;
    }
    for(int i =0; i<n; i++) {
        int x; cin >> x;
        cout << mp[x] << " ";
    }
    cout << '\n';
}
