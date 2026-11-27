#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	cout << "o-----------------------o" << '\n';
	for(int i = 0; i<13; i++) {
		cout << "|";
		int sz = 23;
		int on = n;
		for(int j = 0; j<min(on, 5); j++) {
			cout << "<>< ";
			sz -= 4;
			n--;
		}
		for(int j = 0; j<sz; j++) {
			cout << " ";
		}
		cout << "|\n";
	}
	cout << "o-----------------------o" << '\n';
}
