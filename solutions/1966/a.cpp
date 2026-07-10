#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> freq(101, 0);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
        }
        bool good = false;
        for(int i = 0; i <= 100; i++) {
            if(freq[i] >= k) good = true;
        }
        if(good) cout << k-1 << '\n';
        else cout << n << '\n';
    }
}
