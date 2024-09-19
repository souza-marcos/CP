#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int n, m;
vector<vector<int>> g;
vector<int> order;
vector<bool> vis;

void dfs(int v){
    vis[v] = true;
    for(int u: g[v]) if(!vis[u]) dfs(u);
    order.push_back(v);
}
const int MAX = 1e5 + 1;
int memo[MAX];

int main(){ _
    cin >> n >> m;
    g.resize(n), vis.resize(n);

    int x, y;
    while(m --){
        cin >> x >> y; x--, y--;
        g[x].push_back(y);
    }

    for(int i = 0; i < n; i ++) if(!vis[i]) dfs(i);

    int maxv=0;
    for(int v: order) for(int u: g[v]){
        memo[v] = max(memo[v], memo[u] + 1);
        if(maxv < memo[v]) maxv = memo[v];
    }
    cout << maxv << endl;
    return 0;
} 
