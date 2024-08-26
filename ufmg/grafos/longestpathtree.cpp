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

const int MAX = 1e4 +10;
vector<vector<int>> g(MAX);
vector<int> dis(MAX, -1);

void dfs(int v){
    for(auto w: g[v]) if(dis[w] == -1){
        dis[w] = dis[v] + 1;
        dfs(w);
    }
}

int main(){ _

    int n; cin >> n; // O numero de aresta eh o numero de vertices -1 
    for(int i=0; i<n-1; i++){

        int u,v; cin >> u >> v; u--, v --;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dis[0] = 0;
    dfs(0); // Define todas as distancias do vertice x ate o vertice 0

    // Encontrar o vertice mais distante
    int vertice = -1, dismax = -1;
    for(int i = 0; i < n; i++){
        if(dis[i] > dismax) {
            dismax = dis[i]; 
            vertice = i;
        }
    }

    for(auto& el: dis) el = -1;

    dis[vertice] = 0;
    dfs(vertice);

    int diametro = 0;
    for(auto v: dis) diametro = max(diametro, v);

    cout << diametro << endl;

    return 0;
} 
