#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

vector<vector<int>> g(1e3 + 10);
vector<bool> vis(1e3 + 10, false);

void dfs(int node){
    vis[node] = true;
    for(auto adj: g[node]) if(!vis[adj]) dfs(adj);
}

int main(){ _

    int n, m; cin >> n >> m;
    while(m --){
        int i, j; cin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);  
    }

    int cont = 0;
    for(int i = 1; i <= n; i ++){
        if(!vis[i]){
            cont ++;
            dfs(i);
        }
    }

    cout << cont << endl;

    return 0;
} 
