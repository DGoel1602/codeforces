#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n, a, k, p; cin >> n >> a >> k >> p;
    ll elem = a;
    priority_queue<ll, vector<ll>, greater<ll>> res;
    elem = a;
    for(ll i = 0; i<n; i++){
        res.push(elem);
        if(res.size() > 5) res.pop();
        elem = (elem * k) % p;
    }
    vector<int> r;
    for(int i = 0 ; i<5; i++){
        int t = res.top(); res.pop();
        cout << t << " ";
    }
    return 0;
}
