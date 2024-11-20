#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    int n, m; cin >> n >> m;
    set<pair<int, int>> vis;

    vector<pair<int, int>> mvs = {
        {-1, 2}, {-1, -2}, {1, 2}, {1, -2},
        {-2, 1}, {-2, -1}, {2, 1}, {2, -1}
    };

    auto valid = [n](int i, int j){
        if(max(i, j) < n and min(i, j) >= 0) return true;
        return false;
    };

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a--, b--;
        vis.insert({a, b}); 
        for(auto [newi, newj]: mvs){
            newi += a, newj += b;
            if(valid(newi, newj)) vis.insert({newi, newj});
        }
    }
    cout << (1LL * n * n) - sz(vis) << endl;

    return 0;
} 
