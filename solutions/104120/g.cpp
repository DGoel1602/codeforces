#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> enc(ll n, ll x, ll y) {
    ll c = n/2;
    if(n % 2) {
        return {c-x, y-c};
    } else {
        return {c-x-(x>=c), y-c+(y>=c)};
    }
}

pair<ll, ll> dec(ll n, ll x, ll y) {
    ll c = n/2;
    if(n % 2) {
        return {c-x, c+y};
    } else {
        return {c-x-(x < 0), c+y-(y > 0)};
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    pair<pair<ll, ll>, pair<ll, ll>> xy = {{1, 0}, {0, 1}};

    while(q--) {
        string t; cin >> t;
        if(t == "r") {
            string l; cin >> l;
            if(l == "a") {
                swap(xy.first, xy.second);
                xy.first = {-xy.first.first, -xy.first.second};
                xy.second = {-xy.second.first, -xy.second.second};
            } else if(l == "d") {
                xy.first = {-xy.first.first, -xy.first.second};
            } else if(l == "c") {
                swap(xy.first, xy.second);
            } else {
                xy.second = {-xy.second.first, -xy.second.second};
            }
        } else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            pair<ll, ll> cur = enc(n, a, b);
            //cout << cur.first << ' ' << cur.second << '\n';
            int d = xy.first.first * xy.second.second - xy.first.second * xy.second.first;
            pair<pair<ll, ll>, pair<ll, ll>> apple = {{d*xy.second.second, d*-xy.first.second}, {d*-xy.second.first, d*xy.first.first}};
            pair<ll, ll> nv = {apple.first.first * cur.first + apple.first.second * cur.second, apple.second.first * cur.first + apple.second.second * cur.second};
            //cout << nv.first << ' ' << nv.second << '\n';
            cur = dec(n, nv.first, nv.second);
            //cout << cur.first << ' ' << cur.second << '\n';
            cout << cur.first*n + cur.second + 1 << '\n';
        }
    }
}
