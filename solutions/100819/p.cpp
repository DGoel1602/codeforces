#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> freq(27);
    for(char c: s) freq[c-'a']++;
    sort(freq.begin(), freq.end());
    cout << s.size() - freq[26] - freq[25] << '\n';
}
