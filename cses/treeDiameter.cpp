#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

vector<vector<int>> g;

pair<int, int> dfs(int p, int v, int dist){
    pair<int, int> maxd = {dist, v};
    for(int u: g[v]) if(u != p) {
        maxd = max(maxd, dfs(v, u, dist + 1));
    }
    return maxd;
}


int main(){ _
    int n; cin >> n;
    g.resize(n);
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }

    auto cur = dfs(-1, 0, 0);
    cur = dfs(-1, cur.second, 0);

    cout << cur.first << endl;
    return 0;
} 
