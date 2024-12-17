#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(auto& el: grid){
        for(auto& it: el) cin >> it;
    }

    set<int> diffs;
    auto sorted = grid;

    auto calc = [&](){
        diffs.clear();
        int j = 0;
        for(auto& el: grid){
            auto &copy = sorted[j];
            sort(copy.begin(), copy.end());
            for(int i = 0; i < m; i ++){
                if(copy[i] != el[i]) diffs.insert(i);
            }
            j ++;
        }
    };
    calc();

    if(sz(diffs) == 0) { cout << "1 1\n"; return; }
    if(sz(diffs) > 2) { cout << -1 << endl; return; }
    if(sz(diffs) == 2) {
        vector<int> pos;
        for(auto el: diffs) pos.push_back(el);
        for(int i = 0; i < n; i ++){
            int aux = grid[i][pos[1]];
            grid[i][pos[1]] = grid[i][pos[0]];
            grid[i][pos[0]] = aux;
        }

        diffs.clear();
        for(int i = 0 ; i < n; i ++){
            auto &copy = sorted[i];
            for(int j = 0; j < m; j ++){
                if(copy[j] != grid[i][j]) diffs.insert(j);
            }
        }

        if(sz(diffs) == 0) { cout << pos[0] + 1 << " " << pos[1] + 1 << endl; }
        else cout << -1 << endl;

        return;
    }
    assert(false);
}   


int main(){ // _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
