#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> vis;


set<int> cycle; 

void dfs(int v){
    vis[v] = true;
    for(auto el: g[v])
        if(!vis[el]) dfs(el);
}

bool val(int edges){
    
    for(int i = 0; i < vis.size(); i++){
        if(!vis[i]) {
            return false; // unconnected
        }
    }

    // Have n tree
    if(edges != vis.size()) return false;

    return true;
    
}

int main(){ _

    int v, e; cin >> v >> e;
    g.resize(v);
    vis.resize(v, false);

    for(int i = 0; i < e ; i++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    cout << (val(e)?"FHTAGN!": "NO") << endl;

    return 0;
} 
