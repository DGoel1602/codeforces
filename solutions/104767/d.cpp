#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int n,m; cin >> n >> m;
   int odds = 0;
   vector<int> ev_cnt;
   string last_op = "";
   vector<int> idxs(n);
   vector<int> vals(n);
   for(int i = 0; i<n; i++) {
      int num; cin >> num;
      vals[i] = num;
      string op; 
      if(i < n-1)
         cin >> op;
      if(op == "*" && last_op != "*") {
         ev_cnt.push_back(num % 2 == 0);
         idxs[i] = ev_cnt.size()-1;
      } else if(last_op == "*") {
         ev_cnt[ev_cnt.size()-1] += num % 2 == 0;
         idxs[i] = ev_cnt.size()-1;
      } else {
         odds += num % 2;
         idxs[i] = -1;
      }
      last_op = op;
   }
   for(int x: ev_cnt) odds += x == 0;
   cout << (odds % 2 ? "odd\n" : "even\n");
   for(int _ = 0; _<m; _++) {
      int i, x; cin >> i >> x;
      --i;
      if(idxs[i] == -1) {
         odds -= vals[i] % 2;
         odds += x % 2;
      } else {
         int idx = idxs[i];
         odds -= ev_cnt[idx] == 0;
         ev_cnt[idx] -= vals[i] % 2 == 0;
         ev_cnt[idx] += x % 2 == 0;
         odds += ev_cnt[idx] == 0;
      }
      vals[i] = x;
      cout << (odds % 2 ? "odd\n" : "even\n");
   }
}
