#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    if(a > 2)
    {
        cout << "+" << endl;
    }
    else if(a == 2)
    {
        if(b == 30 && c == 0)
            cout << "=" << endl;
        else if(b == 30 && c > 0)
        {
            cout << "+" << endl;
        } 
        else if (b > 30)
            cout << "+" << endl;
        else
            cout << "-" << endl;
    }
    else
        cout << "-" << endl;
}
