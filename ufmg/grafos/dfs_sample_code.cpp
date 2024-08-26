#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<bool> vis;
vector<vector<int>> grafo;

void dfs(int v){
    cout << v << " ";
    vis[v] = true;
    for(auto w: grafo[v]) if(!vis[w]) dfs(w);
}

int main(){ _
    grafo = {{1}, {0, 3}, {3, 7}, {1, 2, 4, 5}, {3, 5}, {3, 4, 6}, {5, 7}, {2, 6}, {}};
  

    vis.resize(grafo.size(), false);
    dfs(0);

    for(int i = 0; i < grafo.size(); i++){
        if(!vis[i]) dfs(i);
    }


    return 0;
} 
