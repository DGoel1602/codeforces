// 1 7
// 7 2
// 2 6
// 6 3
// 3 5
// 5 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if(n % 2 == 0) {
        cout << (n - 1) / 2 << '\n';
    } else {
        cout << (n - 1 + 1) / 2 << '\n';
    }
}
