#include <bits/stdc++.h>
using namespace std;

int main() {
    int lo = 1, hi = 1e6;
    while(lo != hi) {
        int m = lo + (hi - lo + 1) / 2;
        cout << "? " << m << endl;
        int r; cin >> r;
        if(!r) hi = m - 1;
        else lo = m;
    }
    cout << "! " << lo << endl;
}
