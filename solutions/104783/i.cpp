#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        ll mst; ll lst; ll msp; ll lsp;
        cin >> mst >> lst >> msp >> lsp;
        if(lsp >= msp) {
            cout << (mst * msp) << '\n';
            continue ;
        }
        if(lst >= mst) {
            cout << min(mst * msp, lst * lsp) << '\n';
            continue;
        } else {
            cout << min(abs(mst - lst) * msp + lst * lsp, abs(lst - mst) * lsp * 2 + lst * lsp) << '\n';
            continue;
        }
        ll walk_best = mst;
        ll low;
        if(lst < mst) {
            low = lst;
        } else {
            low = 0;
        }
        ll high = walk_best;
        while(low <= high) {
            ll mid = (low + high) / 2;
            ll my_time = abs(mst - mid) * msp;
            ll ele_time = abs(lst - mid) * lsp;
            //cout << my_time << '|' << ele_time << '|' << low << '|' << high << '\n';
            if(my_time < ele_time) {
                high = mid - 1;
                walk_best = mid;
            } else {
                low = mid + 1;
            }
        }
        cerr << walk_best << '\n';
        ll best_time = msp * mst;
        for(ll candidate = max(walk_best - 50, (ll) 0) ; candidate <= (walk_best + 50) ; candidate++) {
            ll ele_time = abs(lst - candidate) * lsp;
            ll me_time = abs(mst - candidate) * msp;
            best_time = min(best_time, max(ele_time, me_time) + candidate * lsp);
        }
        cout << best_time << '\n';
    
    }
    return 0;
}
