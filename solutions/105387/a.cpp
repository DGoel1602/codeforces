#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char c; cin >> c;
            if(c == '#') {
                grid[i][j] = 1;
                res[i][j] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(res[i][j] == 1){
                bool nei = false;
                for(int dx = -1; dx<=1; dx++)
                for(int dy = -1; dy<=1; dy++){
                    if(dx*dx + dy*dy >= 1 && i+dx >= 0 && i+dx < n && j+dy >= 0 && j+dy < m){
                        if(grid[i+dx][j+dy] == 0){
                            nei = true;
                            break;
                        }
                    }
                }
                if(nei){
                    res[i][j] = 0;                                        
                }
            }
        }
    }

    vector<vector<int>> grid3(n, vector<int>(m, 0));
    for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++){
        if(res[i][j] == 1){
            for(int dx = -1; dx<=1; dx++)
            for(int dy = -1; dy<=1; dy++){
                if(i+dx >= 0 && i+dx < n && j+dy >= 0 && j+dy < m){
                    grid3[i+dx][j+dy] = 1;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid3[i][j] != grid[i][j]) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    cout << "Possible\n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << (res[i][j] == 1 ? '#' : '.');
        }
        cout << endl;
    }



    return 0;
}
