#include <bits/stdc++.h>
using namespace std;
#define int long long
int dirR[4] = {1,0,-1,0};
int dirC[4] = {0,1,0,-1}; 
//down right, up left
typedef long long ll;
vector<vector<int>> rotateGrid(vector<vector<int>> grid){
    vector<vector<int>> newGrid = grid;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            newGrid[i][j] = grid[j][i];
        }
    }
    for(int i = 0; i < newGrid.size(); i++){
        reverse(newGrid[i].begin(),newGrid[i].end());
    }

    return newGrid;
}

ll solve(vector<vector<int>> order, vector<vector<int>> grid){
    vector<int> arr(grid.size()*grid[0].size());
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            arr[order[i][j]] = grid[i][j];
        }
    }

    ll ans = 0;
    ll pref = 0;
    for(int i = 0; i < arr.size(); i++){
        pref = max(0ll,pref+arr[i]);
        ans = max(ans,pref);
    }
    return ans;
}

ll solve2(vector<vector<int>> order, vector<vector<int>> grid){

    ll ans = solve(order,grid);
    for(int i = 0; i < 4; i++){
        order = rotateGrid(order);
        ans = max(ans,solve(order,grid));
    }

    for(int i = 0; i < grid.size(); i++){
        reverse(grid[i].begin(),grid[i].end());
    }

    for(int i = 0; i < 4; i++){
        order = rotateGrid(order);
        ans = max(ans,solve(order,grid));
    }


    return ans;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> order(n,vector<int>(n,-1));
    int dir = 0;
    int r = 0;
    int c = 0;
    int filled = 0;

    while(true){
        // cout << "-------\n";

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << order[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        order[r][c] = filled++;
        if(filled == n*n) break;
        int newR = r+dirR[dir];
        int newC = c+dirC[dir];
        if(newR>= 0 && newR < n && newC >= 0 && newC < n && order[newR][newC] == -1){
            r = newR;
            c = newC;
        }else{
            dir = (dir+1)%4;
            int newR = r+dirR[dir];
            int newC = c+dirC[dir];
            r = newR;
            c = newC;
        }
    }

    ll ans = 0;
    
    ans = max(ans,solve2(order,grid));
    cout << ans << "\n";





    return 0;
}
