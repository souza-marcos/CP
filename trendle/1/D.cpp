#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(3*n);
    map<pair<int, int>, int > edges;
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b), g[b].push_back(a);
        edges[make_pair(min(a, b), max(a, b))] = i + 1;
    }

    // tentar fazer matching

        
    vector<bool> vis(3 * n), used_matching(3 * n);
    vector<pair<int, int>> matching;        
    

    auto dfs = [&](auto&& self, int v) -> void{
        vis[v] = true;
        for(auto u : g[v]){
            if(vis[u]) continue;
            if(!used_matching[v]){
                matching.push_back({v, u});
                used_matching[v] = used_matching[u] = true;
            }
            self(self, u);
        }
    };

    for(int i = 0; i < n; i ++) if(!vis[i])
        dfs(dfs, i);

    if(sz(matching) >= n){
        cout << "Matching\n";
        for(int i = 0; i < n; i ++){
            auto [a, b] = matching[i];            
            cout << edges[make_pair(min(a, b), max(a, b))] << " ";
        }
        cout << endl;
        return ;
    } 

    // Make ind Set
    cout << "IndSet\n";
    vector<int> indset;
    for(int i = 0; i < 3 * n; i ++){
        if(!used_matching[i]) indset.push_back(i);
    }

    assert(sz(indset) >= n);

    for(int i = 0; i < n; i ++) cout << indset[i] + 1 << " ";
    cout << endl;
}

int main(){ _ 

    int t; 
    cin >> t;
    while(t --) { solve();    }


} 
