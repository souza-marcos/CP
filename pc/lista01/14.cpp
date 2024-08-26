#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> sizecy, rep;




void solve(){
    g.resize(n);
    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w; a--, b--;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }
    int q; cin >> q;

}

int main(){_
    while(cin >> n >> m) solve();


    return 0;
}