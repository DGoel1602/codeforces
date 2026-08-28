#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)
#define fors(i,s,n) for(int i=s;i<n;++i)
#define ends(v) v.begin(),v.end()

int main() {
    int n;
    cin >> n;
    vector<bool> left(n);
    vector<int> pl(n), sr(n);
    forr(i, n) {
        char c;
        cin >> c;
        left[i] = c=='L';
    }
    fors(i, 1, n) {
        pl[i] = pl[i-1]+left[i-1];
    }
    reverse(ends(left));
    fors(i, 1, n) {
        sr[i] = sr[i-1]+!left[i-1];
    }
    reverse(ends(sr));
    int best = n;
    forr(i, n) {
        best = min(best, pl[i]+sr[i]);
    }
    cout << best << "\n";
}
