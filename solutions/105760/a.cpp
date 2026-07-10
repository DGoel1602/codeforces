#include <iostream>
using namespace std;

int main(){
	int g, p, t;
	cin >> g >> p >> t;

	int a = g * p;
	int b = g + p * t;

	if(a > b){
		cout << 2 << endl;
	} else if(b > a){
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
}
