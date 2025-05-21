#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ //_
    int n, q; cin >> n >> q;

    vector<int> depth(n);
    vector<vector<int>> up(n, vector<int> (ceil(log2(n)) + 1, -1));
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        up[v][0] = p;
        for(int h = 1; h < sz(up[0]); h ++){
            if(up[v][h-1] == -1) break;
            up[v][h] = up[up[v][h-1]][h-1];
        }
        for(auto u : g[v])
            if(u != p) depth[u] = depth[v] + 1, dfs(dfs, u, v);
    };
    depth[0]=0;
    dfs(dfs, 0, -1);

    // Achar o highest que é ancestor de b e não é ancestor de a
    auto dist = [&](int a, int b) -> int {
        if(depth[a] < depth[b]) 
            swap(a, b);

        int k = depth[a] - depth[b];
        int res = depth[a] + depth[b], l = ceil(log(depth[a]));
        int i = 0;
        while(k > 0){
            if(k&1) a = up[a][i];
            i ++, k >>= 1;
        }


        if(a != b){
            while(l > 0){
                if(up[a][l]!=up[b][l]){
                    a = up[a][l], b = up[b][l];
                }
                l--;
            }
            a = up[a][0];
        }
        res -= 2 * depth[a];

        return res;
    };


    while(q --){
        int a, b; cin >> a >> b;
        a --, b--;
        cout << dist(a, b) << endl;
    }
    return 0;
} 
