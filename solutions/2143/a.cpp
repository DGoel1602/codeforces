#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int lb, rb;
    for(int i = 0; i < n; i++) {
        if(p[i] == n) lb = rb = i;
    }
    
    for(int k = n-1; k >= 1; k--) {
        int idx;
        for(int i = 0; i < n; i++) {
            if(p[i] == k) idx = i;
        }
        if(idx == lb-1) lb--;
        else if(idx == rb+1) rb++;
        else return void(cout << "NO\n"); 
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
