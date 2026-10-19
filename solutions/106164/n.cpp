#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ap = a+1;
    int bp = n-b;

    cout << abs(ap-bp)-1 << '\n';
}
