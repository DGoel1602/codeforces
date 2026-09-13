#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s = to_string(n);
    bool has7 = false;
    for(char c: s) has7 |= (c == '7');
    if(!has7 && n % 7) cout << "0\n";
    else if(!has7 && n % 7 == 0) cout << "1\n";
    else if(has7 && n % 7) cout << "2\n";
    else cout << "3\n";
}
