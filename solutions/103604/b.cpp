#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define VSIZE(v) ((int) v.size())

struct State {
	pair<int,int> location;
	ll power_required;
	State(pair<int, int> l, ll pr) {
		location = l;
		power_required = pr;
	}

};
struct StateCompare {
	bool operator()(State me, State you) {
		return me.power_required > you.power_required;
	}
};
pair<pair<int, int>, ll> solveLevel(vector<vector<ll>>& grid, pair<int,int> start, ll* power) {
	vector<vector<bool>> visited(VSIZE(grid), vector<bool>(VSIZE(grid[0]), 0));
	ll cost_to_advance = 99999999999999999;
	pair<int,int> exit_square = {0, 0};
	priority_queue<State, vector<State>, StateCompare> dij;
	dij.push(State(start, grid[start.first][start.second]));
	while(dij.size() && dij.top().power_required <= (*power)) {
		State last = dij.top();
		dij.pop();
		if(visited[last.location.first][last.location.second]) {
			continue;
		}
		visited[last.location.first][last.location.second] = 1;
		if(grid[last.location.first][last.location.second] >= 0) {
			*power += grid[last.location.first][last.location.second];
		}
		if(grid[last.location.first][last.location.second] == -1) {
			cost_to_advance = last.power_required;
			exit_square = last.location;
		}
		for(int dx = -1 ; dx <= 1; dx++) {
			for(int dy = -1 ; dy <= 1 ; dy++) {
				if((dx == 0) ^ (dy == 0)) {
					pair<int, int> kid = {last.location.first + dx, last.location.second + dy};
					if(kid.first >= 0 && kid.first < VSIZE(grid) && kid.second >= 0 && kid.second < VSIZE(grid[0]) && grid[kid.first][kid.second] != -9) {
						dij.push(State(kid, max(grid[kid.first][kid.second], last.power_required)));
					}
				}
			}
		}
	}
	return {exit_square, cost_to_advance};
	
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int l, m, n;
	cin >> l >> n >> m;
	ll power = 1;
	pair<int, int> start = {0, 0}; // possibly not set by exit?
	for(int lr = 0 ; lr < l ; lr++) {
		vector<vector<ll>> grid;
		for(int nr = 0 ; nr < n ; nr++) {
			grid.push_back(vector<ll>());
			for(int mr = 0 ; mr < m ; mr++) {
				ll buffer;
				cin >> buffer;
				grid[nr].push_back(buffer);
			}
		}
		start = solveLevel(grid, start, &power).first;
	}
	cout << power << '\n';
	return 0;

	
}
