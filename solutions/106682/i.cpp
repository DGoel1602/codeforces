#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if(k == 1) cout << "S\n";
    else {
        if(n == 2) {
            if(k % 2) cout << "S\n";
            else cout << "N\n";
        } else  cout << "N\n";
    }
}
