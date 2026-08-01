#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)
#define int long long

string name(int bal) {
   if(bal > 0) return "desks";
   if(bal < 0) return "monitors";
   return "same";
}

signed main() {
   int n, m, q;
   cin >> n >> m >> q;
   vector<long long> bal(n);
   forr(i, n) {
      cin >> bal[i];
   }
   forr(i, n) {
      int e;
      cin >> e;
      bal[i] -= e;
   }
   vector<vector<int>> g(n), h(n);
   vector<bool> hv(n, 0);
   forr(i, m) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   forr(i, n) {
      hv[i] = g[i].size() > 5; //TODO:
   }
   vector<int> cal(n, 0);
   forr(i, n) {
      if(hv[i]) for(int v : g[i]) {
         cal[i] += bal[v];
      }
   }
   forr(i, n) {
      for(int v : g[i]) {
         if(hv[v]) h[i].push_back(v);
      }
   }

   forr(qi, q) {
      string s;
      cin >> s;
      if(s[0] == 'c') {
         int u;
         cin >> u;
         --u;
         if(hv[u]) {
            cout << name(bal[u]+cal[u]) << "\n";
         }
         else {
            long long s = bal[u];
            for(int v : g[u]) {
               s += bal[v];
            }
            cout << name(s) << "\n";
         }
      }
      else {
         int am, u;
         cin >> am >> s >> u;
         --u;
         if(s[0] == 'm') am *= -1;
         bal[u] += am;
         for(int v : h[u]) {
            cal[v] += am;
         }
      }
   }
}
