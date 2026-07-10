    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
     
    int main() {
        cin.tie(0)->sync_with_stdio(0);
        int t; cin >> t;
        while(t--) {
            ll n, k;
            cin >> n >> k;
            vector<ll> res;
            ll sum = 0, cur = 1;
            for(; sum + cur < k; cur *= 2) {
                sum += cur;
                res.push_back(cur);
            }
            if(sum != k-1) res.push_back(k-sum-1);
     
            cur = sum+2;
            while(__builtin_popcount(cur) != 1) cur++;
            if(cur+k <= n) res.push_back(cur+k);
            if(k+1 <= n) res.push_back(k+1);
            while(cur <= n) {
                res.push_back(cur);
                cur *= 2;
            }
     
            assert((int)(res.size()) <= 25);
            cout << (int)(res.size()) << '\n';
            for(ll x : res) cout << x << ' ';
            cout << '\n';
        }
    }
