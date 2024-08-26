#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

vector<vector<int>> g;
vector<bool> vis;
set_t comp;

ll dfs(int v){
    vis[v] = true;
    ll sum = comp.order_of_key(v);
    // cout << v << " -> " << sum  << endl;
    comp.insert(v);
    for(auto u: g[v]){
        if(!vis[u]){
            sum += dfs(u); 
        }
    }
    comp.erase(v);
    // cout << "SIZE: " << comp.size() << endl;
    return sum;
}

int main(){ _
    int n; cin >> n;
    g.assign(n, {}), vis.assign(n, false);

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << dfs(0) << endl;
    return 0;
} 
