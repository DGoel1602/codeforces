#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <queue>
using namespace std;

class Compare{
public:
	bool operator()(pair<double, int> a, pair<double, int> b){
		return a.first > b.first;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> visited(n, 0);
	priority_queue<pair<double, int>> q;
	q.push({1, 0});
	vector<vector<pair<double, int>>> cons(n);
	for(int i = 0; i<n; i++) cons[i] = {};
	for(int i = 0; i<m; i++){
		int a, b;
		double c;
		cin >> a >> b >> c;
		a--; b--;
		cons[a].push_back({c, b});
	}

	cout << fixed << setprecision(6);
	while(!q.empty()){
		auto t = q.top();
		q.pop();

		if(t.second == n-1){
			cout << t.first << endl;
			return 0;
		}
		
		if(visited[t.second]) continue;
		visited[t.second] = 1;

		for(auto con: cons[t.second]){
			q.push({con.first * t.first, con.second});
		}
	}

	cout << 0.0 << endl;
	return 0;
}
