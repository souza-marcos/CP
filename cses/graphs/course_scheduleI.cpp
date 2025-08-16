#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int n, m; 
vector<vector<int>> g;
vector<int> color, order;

void dfs(int v){
    color[v] = 1;

    for(int u: g[v]){
        if(color[u] == 0) dfs(u);
        else if(color[u] == 1){
            // Achei um ciclo!
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }

    order.push_back(v);
    color[v] = 2;
}

void toposort(){
    for(int v = 0; v < n; v ++){
        if(color[v] == 0){
            dfs(v);
        }
    }
    reverse(order.begin(), order.end());
}


int32_t main(){ _ 

    cin >> n >> m;

    g.resize(n, {}), color.resize(n, 0);    
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
    }

    toposort();

    for(int el : order){
        cout << el + 1 << " ";
    }
    cout << endl;
}
