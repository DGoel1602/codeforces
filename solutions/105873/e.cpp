#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    for(int i = 0; i < n; i++){
        if(arr[i] >= m){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";

    return 0;
}
