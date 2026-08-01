#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
   int lo, hi, mid;
   int val = 0;
   Node* left = nullptr, *right = nullptr;
   Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {}
   void check() {
      if(lo == hi - 1) return;
      if(left == nullptr) left = new Node(lo, mid);
      if(right == nullptr) right = new Node(mid, hi);
   }
   void update(int i, int x) {
      if(lo == hi - 1) return void(val += x);
      check();
      if(i < mid) left->update(i, x);
      else right->update(i, x);
      val = left->val + right->val;
   }
   int query(int l, int r) {
      if(l >= hi || r <= lo) return 0;
      if(r >= hi && l <= lo) return val;
      int res = 0;
      if(left != nullptr) res += left->query(l, r);
      if(right != nullptr) res += right->query(l, r);
      return res;
   }
};

signed main() {
   cin.tie(0)->sync_with_stdio(0);
   vector<int> sieve(1e6+1, 1);
   vector<int> primes;
   for(int i = 2; i*i<=1e6; i++) {
      if(!sieve[i]) continue;
      for(int j = i * i; j<=1e6; j += i) sieve[j] = 0;
   }
   for(int i = 2; i<=1e6; i++) if(sieve[i]) primes.push_back(i);
   int n; cin >> n;
   vector<Node> sts;
   for(int i = 0; i<=1e6; i++) sts.push_back(Node(0, n));
   vector<int> a(n);
   for(int &x: a) cin >> x;
   for(int i = 0; i<n; i++) {
      int x = a[i];
      for(int p: primes) {
         if(p * p > x) break;
         int cnt = 0;
         while(x % p == 0) x /= p, cnt++;
         if(cnt) sts[p].update(i, cnt);
      }
      if(x > 1) sts[x].update(i, 1);
   }
   int q; cin >> q;
   while(q--) {
      int l, r, k; cin >> l >> r >> k;
      --l;
      for(int p: primes) {
         if(p * p > k) break;
         int cnt = 0;
         while(k % p == 0) k /= p, cnt++;
         if(cnt) if(sts[p].query(l, r) < cnt) goto next;
      }
      if(k > 1) if(sts[k].query(l, r) < 1) goto next;
      cout << "Yes\n";
      continue;
      next:;
      cout << "No\n";
   }
}
