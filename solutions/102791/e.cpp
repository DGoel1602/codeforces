#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    cout << 2 << endl;
    if(n == 2) {
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }

    vector<int> st;
    for(int i = 1; i <= n-3; i++) st.push_back(i);
    st.push_back(n-1);
    st.push_back(n-1);
    cout << n-2 << ' ' << n << endl;

    while(st.size() > 1) {
        int a = st.back(); st.pop_back();
        int b = st.back(); st.pop_back();
        cout << b << ' ' << a << endl;
        st.push_back((a+b+1)/2);
    }
}
