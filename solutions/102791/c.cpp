#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)
#define fors(i,s,n) for(int i=s;i<n;++i)
#define ends(v) v.begin(),v.end()

int main() {
    long long n;
    cin >> n;
    if(n < 7) {
        if(n == 3) {cout << "1 0 0\n";}
        else if(n == 5) {cout << "0 1 0\n";}
        else if(n == 6) cout << "2 0 0\n";
        else {
            cout << "-1\n";
        }
    }
    else {
        int m = n%3;
        n = n/3-2;
        if(m == 0) {cout << n+2 << " 0 0\n";}
        else if(m == 1) {cout << n << " 0 1\n";}
        else if(m == 2) {cout << n+1 << " 1 0\n";}
    }
}
