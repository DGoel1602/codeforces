#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)

int main() {
   int n;
   cin >> n;
   if(n == 2) {
      cout << "1\n";
      return 0;
   }
   long long p = n;
   n -= 3;
   long long a = 2;
   while(n) {
      if(n&1) {
         p *= a;
         p %= 1000000007;
      }
      a *= a;
      a %= 1000000007;
      n >>= 1;
   }
   cout << p << "\n";
}
