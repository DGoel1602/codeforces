#include <bits/stdc++.h>
using namespace std;
#define ll long long

double eval(double x, double c1, double c2, double k) {
    double res = log(c2+x)*(c1-k*c2) + k*(x+c2);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    
    vector<pair<double, double>> v(n);
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v[i].second = x;
    }
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        v[i].first = (double)(a) / v[i].second;
    }
    sort(v.begin(), v.end());

    double ca = v[0].first*v[0].second;
    ll cv = v[0].second;
    double res = -ca;
    for(int i = 1; i < n; i++) {
        double area = eval(v[i].second, ca, cv, v[i].first) - eval(0, ca, cv, v[i].first);
        res -= area;
        ca += v[i].first*v[i].second, cv += v[i].second;
    }
    
    reverse(v.begin(), v.end());
    ca = v[0].first*v[0].second, cv = v[0].second;
    res += ca;
    for(int i = 1; i < n; i++) {
        double area = eval(v[i].second, ca, cv, v[i].first) - eval(0, ca, cv, v[i].first);
        res += area;
        ca += v[i].first*v[i].second, cv += v[i].second;
    }

    cout << setprecision(15) << fixed << (res/cv) << '\n';
}
