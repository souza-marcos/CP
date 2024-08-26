#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<vector<int>> g;
vector<int> dist;
int max_dist, n;
vector<bool> pontas;

void dfs(int v, int p){
    for(int u: g[v]) if(u != p){
        dist[u] = dist[v] + 1;
        if(dist[u] > max_dist) max_dist = dist[u];
        dfs(u, v);
    }
}

int main(){ _
    int a, b;
    cin >> n;
    g.resize(n), dist.resize(n), pontas.resize(n, false);
    for(int i = 1; i < n; i ++){
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(0, 0);
    int next_ini = 0;
    for(int i = 0; i < n; i ++)
        if(dist[i] == max_dist) pontas[i] = true, next_ini = i;
    
    dist.assign(n, 0), max_dist = 0;
    dfs(next_ini, next_ini);
    
    for(int i = 0; i < n; i ++)
        if(dist[i] == max_dist) pontas[i] = true;
    
    for(int i = 0; i < n; i++)
        cout << max_dist + pontas[i] << endl;

    return 0;
} 
