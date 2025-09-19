#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, p; cin >> n >> p;
    vector<int> cost(n); 
    for(int& el : cost) cin >> el;
    for(int i = 0; i < p; i ++){
        int a; cin >>a;
        a --;
        cost[a] = 0;
    }

    vector<vector<int>> g(n);

    for(int i = 0; i < n; i ++){
        int m; cin >> m;
        while(m -- ){
            int a; cin >> a;
            a --;
            g[i].push_back(a);
        }
    }

    vector<bool> vis(n);
    auto dfs = [&](auto&& self, int v) -> int{
        if(vis[v]) return cost[v];
        vis[v] = true;

        if(sz(g[v]) > 0){
            int sum = 0;
            for(int u : g[v]) sum += self(self, u);
            cost[v] = min(cost[v], sum); 
        }
        return cost[v];
    };

    for(int i = 0; i < n; i ++){
        dfs(dfs, i);
        cout << cost[i] << " ";
    }
    cout << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
