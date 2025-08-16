#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

vector<vector<int>> g, up;
int n, h; 

vector<int> tin, tout, depth, szo;
int timer = 0;

int dfs(int v, int p){
    tin[v] = timer ++;

    up[v][0] = p;

    for(int i = 1; i < h; i ++){
        up[v][i] = up[up[v][i-1]][i-1];
    }

    int cnt = 1;
    for(int u : g[v]) if(u != p){
        depth[u] = depth[v] + 1;
        cnt += dfs(u, v);
    }

    szo[v] = cnt;
    tout[v] = timer ++;
    return cnt;
}

bool isAncestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

int lca(int a, int b){
    if(isAncestor(a, b)) return a;
    if(isAncestor(b, a)) return b;

    for(int i = h-1; i >= 0; i --){
        if(not isAncestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}

int main(){ _
    int q;
    cin >> n >> q;    
    h = log2(n) + 1;

    g.resize(n, {});
    up.resize(n, vector<int>(h));

    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    tin.resize(n), tout.resize(n), depth.resize(n), szo.resize(n);
    dfs(0, 0);

    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;

        int low = lca(a, b);
        int da = depth[a] - depth[low], db = depth[b] - depth[low];
        int dist = depth[a] + depth[b] - 2*depth[low];
        if(dist % 2 == 1) { // numero de arestas impar -> vertices par
            cout << 0 << endl;
            continue;
        }

        // tenho que achar o carinha do meio

        if(da == db){ // meio eh low
            for(int i = h-1; i >= 0; i--){
                if(not isAncestor(up[a][i], low)) a = up[a][i];
                if(not isAncestor(up[b][i], low)) b = up[b][i];
            }

            cout << n - szo[a] - szo[b] << endl;
            continue;
        }

        int mid = dist / 2; // tenho que subir mid carinhas
        if(da < db){
            swap(da, db);
            swap(a, b);
        }

        int k = mid;
        for(int i = h-1; i >= 0; i--){
            if((1LL << i) < k){
                a = up[a][i];
                k -= (1LL << i);
            }
        }

        int pai = up[a][0];
        cout << szo[pai] - szo[a] << endl;
    }

    return 0;
} 
