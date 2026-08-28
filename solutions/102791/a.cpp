#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)
#define ends(v) v.begin(),v.end()

int main() {
    int n;
    vector<int> p(3);
    cin >> n;
    forr(i, 3) cin >> p[i];
    sort(ends(p));
    int c = 3*(n/(p[0]+p[1]+p[2]));
    if(c/3*(p[0]+p[1]+p[2])+p[0] <= n) ++c;
    if(c/3*(p[0]+p[1]+p[2])+p[0]+p[1] <= n) ++c;
    cout << c << "\n";
}
