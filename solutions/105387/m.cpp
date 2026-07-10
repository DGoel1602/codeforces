#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
const ll INF = numeric_limits<ll>::max() / 4;

#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)
#define rep(i,a,b) for(int i = a; i<b; i++)


int main() {
    int n; cin >> n;
    map<int, pair<ll, ll>> m;

    vector<ll> seats(n);
    for(ll i = 0; i<n; i++) {
        ll d; cin >> d;
        seats[i] = d-1;
    }
    vector<ll> dis(n);
    for(ll &x: dis) cin >> x;

    for(ll i = 0; i<n; i++){
        if(m.count(seats[i])){
            if(m[seats[i]].second < dis[i]) m[seats[i]] = {i, dis[i]};
        } else {
            m[seats[i]] = {i, dis[i]};
        }
    }

    set<ll> placed_s;

    vector<ll> f_seats(n, -1);
    for(auto &it: m) {
        f_seats[it.second.first] = it.first;
        placed_s.insert(it.first);
    }
    //for(ll x: f_seats) cout << x+1 << " ";

    ll cur = 0;
    ll first_seat = 0;
    ll placed = m.size();
    ll cost = 0;
    while(placed < n) {
        while(placed_s.count(first_seat)) first_seat++;
        while(f_seats[cur] != -1) cur++;
        placed++;
        cost += dis[cur];
        f_seats[cur] = first_seat;
        placed_s.insert(first_seat);
    }
    cout << cost << "\n";
    for(ll x: f_seats) cout << x+1 << " ";
    return 0;
}
