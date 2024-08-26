#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"
vector<vector<int>> g;
vector<bool> vis;
vector<int> v_cnt;

int dfs(int v){

    vis[v] = true;
    int cnt = 0;
    for(auto u : g[v])
        if(!vis[u]) cnt += dfs(u);
    
    return v_cnt[v] = cnt + 1;
}

int main(){ _

    int n; cin >> n;
    g.assign(n, {});
    vis.assign(n, false);
    v_cnt.assign(n, 0);
    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n % 2) { cout << -1 << endl; return 0; }

    dfs(0);
    int cnt = 0;
    for(auto el: v_cnt) if(el%2 ==0) cnt ++;
    cout << cnt - 1 << endl;
    
    return 0;
} 
