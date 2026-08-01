#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3), b(3);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a == b && a[0] * a[0] + a[1] * a[1] == a[2] * a[2] ? "YES\n" : "NO\n");
}
