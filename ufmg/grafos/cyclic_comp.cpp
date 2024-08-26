#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g(1e6);
vector<bool> vis(1e6, false);

set<int> comp;

void dfs(int v){
    vis[v] = true;
    comp.insert(v);
    for(auto w:g[v])
        if(!vis[w]) dfs(w);      
}

int main(){ _
    int v, a; cin >> v >> a;
    for(int i = 0; i < a; i++){
        int j, k; cin >> j >> k;
        g[j].push_back(k);
        g[k].push_back(j);
    }
    
    int cont = 0;
    for(int i = 0; i < v; i++){
        
        if(!vis[i]){
            comp.clear();
            dfs(i);
            cont ++;
            for(auto el: comp){
                if(g[el].size() != 2){
                    cont --;
                    break;
                }
            }
        }
    }
    cout << cont << endl;

    return 0;
} 
