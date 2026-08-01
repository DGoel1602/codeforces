#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n; ++i)

int main() {
    int n;
    cin >> n;
    double t = 0;
    forr(i, n) {
        int a;
        cin >> a;
        t += a==0?2:1./a;
    }
    cout << fixed << setprecision(7) << t << "\n";
}
