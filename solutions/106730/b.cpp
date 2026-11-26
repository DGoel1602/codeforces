#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if(x+y > 9 || abs(x-y) > 1) return (cout << "impossible\n", 0);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(3*i + j >= x+y) cout << '.';
            else {
                char c = ((((3*i + j) % 2) ^ (y < x)) ? 'X' : 'O');
                cout << c;
            }
        }
        cout << '\n';
    }
}
