#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)

int main() {
   int r, k;
   cin >> r >> k;
   string str;
   cin >> str;
   vector<bool> s;
   for(char c : str) {
      s.push_back(c=='X');
   }
   int n = s.size();
   forr(i, k) {
      vector<bool> z(n);
      forr(i, n) {
         int b = (i>0?s[i-1]:0)*4+s[i]*2+(i<n-1?s[i+1]:0);
         z[i] = (r>>b)&1;
         cout << (z[i]?'X':'.');
      }
      cout << "\n";
      swap(s, z);
   }
}
