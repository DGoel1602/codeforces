#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, w; cin >> n >> w;
    vector<double> prob(n);
    vector<int> money(n);
    vector<string> strings(n);
    vector<double> probs(n);
    for(int i = 0; i<n; i++) {
        cin >> strings[i] >> probs[i] >> money[i];
    }

    int ls_safe = -1;
    vector<int> saves(n, -1);
    for(int i = 0; i<n; i++) {
        saves[i] = ls_safe;
        if(strings[i] == "safe") ls_safe = i;
    }

    double p = 1;
    map<double, double> mp;
    double ev = 0, best = 0;
    for(int i = 0; i<=n; i++) {
        double mo = (i == 0 ? 0 : money[i-1]);

        ev -= mp[mo] * log(1.0 + (double)mo / w);
        mp[mo] += p;
        ev += mp[mo] * log(1.0 + (double)mo / w);
        best = max(best, ev);
        ev -= mp[mo] * log(1.0 + (double)mo / w);
        mp[mo] -= p;
        ev += mp[mo] * log(1.0 + (double)mo / w);

        if(i < n) {
            mo = (saves[i] == -1 ? 0 : money[saves[i]]);
            ev -= mp[mo] * log(1.0 + (double)mo / w);
            double p_loss = p * (1 - probs[i]);
            mp[(saves[i] == -1 ? 0 : money[saves[i]])] += p_loss;
            ev += mp[mo] * log(1.0 + (double)mo / w);
            p *= probs[i];
        }
    }

    cout << "$" << setprecision(2) << fixed <<  w * (pow(std::numbers::e_v<double>, best) - 1) << '\n';
}
