#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;

    vector<int> runs;
    char c = s[0]; int r = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] == c) r++;
        else runs.push_back(r), c = s[i], r = 1;
    }
    runs.push_back(r);

    bool q = false;
    int exc = n-runs.size(), used = 0, res = 0;
    for(int i = 0; i < runs.size(); i++) {
        if(q) q = false;
        else {
            res++;
            if(used < exc) used++;
            else q = true;
        }
        used = max(0, used-(runs[i]-1));
        exc -= runs[i]-1;
    }
    cout << res << endl;
}
