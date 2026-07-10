    #include <bits/stdc++.h>
    using namespace std;

    using ll = long long;

    int main(){
        ll n; cin >> n;
        ll le = 0;
        for(ll i = 1; i<=n; i++){
            string c; cin >> c;
            if(c == "?") continue;
            ll m = stoll(c);
            ll l = ((m - 0.5) * i) + 1 - 1e-5;
            le = max(le, l);
        }
        cout << le << endl;
    }
