#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int time = 0;
    for(int i = 0; i<n; i++) {
        int _, s, t, p; cin >> _ >> s >> t >> p;
        if(s + p < time) continue;
        time = max(time + t, s + t);
        cout << _ << '\n';
    }
}
