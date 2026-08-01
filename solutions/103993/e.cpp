#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int d; cin >> d;
    vector<vector<int>> nums(d);
    for(int i = 0; i<n; i++) {
        int x; cin >> x;
        nums[i % d].push_back(x);
    }
    for(auto &v: nums) sort(v.begin(), v.end());
    vector<int> a;
    for(int i = 0; i<(n+d-1)/d; i++) {
        for(auto &v: nums) 
            if(v.size() > i) a.push_back(v[i]);
    }
    vector<int> cp(a);
    sort(cp.begin(), cp.end());
    cout << (a == cp ? "YES\n" : "NO\n");
}
