#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if(n == 1) {
        cout << "0\n";
        return 0;
    }
    vector<int> facts = {1};
    for(int i = 2; i<10; i++) facts.push_back(facts.back() * i);
    vector<int> res;
    while(n > 0) {
        auto it = upper_bound(facts.begin(), facts.end(), n) - facts.begin() - 1;
        res.push_back(it + 1);
        n -= facts[it];
    }
    sort(res.begin(), res.end());
    for(int i = 0; i<res.size(); i++) {
        if(i > 0 && res[i] == 1) cout << 0;
        else cout << res[i];
    }
    cout << '\n';
}
