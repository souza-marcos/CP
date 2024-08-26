#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()
vector<vector<int>> g;
vector<bool> vis;

int n, m;

void dfs(int v){
    vis[v] = true;
    for(auto el: g[v]) if(!vis[el]) dfs(el);
}

int main(){ _
    cin >> n >> m;

    g.resize(n + m + 3);
    vis.assign(n + m + 3, false);

    bool edgecase = true;
    for(int i = 0; i < n; i++){
        int a; cin >> a; if(a > 0) edgecase = false;
        while(a --){
            int b; cin >> b;
            g[i].push_back(n + b + 1);
            g[n+b + 1].push_back(i);
        }
    }
    if(edgecase) { cout << n << endl; return 0;}

    int cont = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]) { dfs(i); cont ++;};
    }

    cout << cont - 1 << endl;

    // for(auto el: vis) cout << el << " ";
    // cout << endl;

    return 0;
} 
