#include <bits/stdc++.h>
using namespace std;

class Compare{
public:
	bool operator()(pair<double, int> a, pair<double, int> b){
		return a.first < b.first;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int P, n;
	cin >> P >> n;
	vector<pair<double, int>> stocks(n, {0, 0});
	for(int i = 0; i<n; i++){
		double a;
		int b;
		cin >> a >> b;
		stocks[i] = {a, b};
	}

	sort(stocks.begin(), stocks.end(), Compare());

	double price = 0;
	for(int i = 0; i<n; i++){
		if(stocks[i].second >= P){
			price += P * stocks[i].first;
			P = 0;
		} else {
			P -= stocks[i].second;
			price += stocks[i].second * stocks[i].first;
		}
		if(P == 0){
			cout << price << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}
