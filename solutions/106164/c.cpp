#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a.size())

void solve() {
    int x; cin >> x;
    x--;
    
    int sum = 0, n = 1;
    for(;;) {
        if(sum >= abs(x) && (((n-1)/2) % 2 == abs(x) % 2) && abs(x) != sum-2) break;
        n++;
        sum += n;
    }

    cout << n << endl;
    int tar = x+n*(n+1)/2-1;
    vector<int> res;
    for(int i = n; i >= 2; i--) {
        if((2*i == tar) || (2*i < tar && tar-2*i >= 4)) res.push_back(i), tar -= 2*i;
        else res.push_back(-i);
    }
    reverse(res.begin(), res.end());

    cout << 1;
    for(int x : res) {
        cout << ((x < 0) ? '-' : '+') << abs(x);
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
