// https://codeforces.com/contest/161/problem/D
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MAX = 5e4 + 10;
vector<vector<ll>> f;
vector<vector<int>> g;
bool vis[MAX];
ll res = 0;

int n, k; 

ll dfs(int p, int v){

    ll sum = 0;
    auto& curdist = f[v];
    curdist[0] = 1;

    for(int u: g[v]){
        if(u != p) {
            sum += dfs(v, u); // caminhos inteiramente contidos na subtree S(u)
            for(int i = 1; i <= k; i ++){
                curdist[i] += f[u][i-1]; // Caminhos que terminam em u dentro de S(u) 
            }
        }
    }
    
    // caminhos dentro de S(v) de tamanho k que passam por v
    ll passam = 0;
    if(k > 1){
        for(int u : g[v]){
            if(u != p)
            for(int i = 1; i < k; i ++){
                // cout << v << " " << i << " " << k - i - 1 << endl;
                passam += f[u][i-1] * (f[v][k-i]-f[u][k-i-1]); 
            }
        }
        passam /= 2;
    }
    return passam + sum + curdist[k];
}

int main(){ _ 

    cin >> n >> k;
    f = vector<vector<ll>>(n, vector<ll>(k + 1, 0));
    g.resize(n);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b), g[b].push_back(a);
    }

    ll res = dfs(-1, 0);

    cout << res << endl;
}