#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll

int32_t main(){ _

    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // I have to block the queries and before I process
    // each block I run an BFS with the current red nodes. 
    // Then I need to compare with the all nodes inside the query block
    // that become a red node and get the min distance with it and the previous dist.


    // the node 1 is a red node initially.

    vector<pair<int, int>> queries(q);
    for(auto& [a, b] : queries) cin >> a >> b, b--;

    int block = sqrt(q) + 1;

    vector<int> become_red = {0}, reds;
    vector<int> dist(n, INF);

    auto bfs = [&](){
        queue<int> q;
        dist.assign(n, -1);
        for(int el : reds) {
            q.push(el);
            dist[el] = 0;
        }

        while(sz(q)){
            int v = q.front();
            q.pop();
            for(int u : g[v]) if(dist[u] == -1){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    };

    int timer = 0;
    vector<int> depth(n), tin(n), tout(n);
    int h = log2(n)+1;
    vector<vector<int>> up(h, vector<int>(n));

    auto dfs = [&](auto&& self, int v, int p) -> void {
        tin[v] = timer ++;
        up[0][v] = p;
        for(int i = 1; i < h; i ++)
            up[i][v] = up[i-1][up[i-1][v]];

        for(int u : g[v]) if(u != p){
            depth[u] = depth[v] + 1;
            self(self, u, v);
        }
        tout[v] = timer ++;
    };
    
    depth[0] = 0;
    dfs(dfs, 0, 0);

    auto isAncestor = [&](int a, int b) -> bool {
        return tin[a] <= tin[b] and tout[a] >= tout[b];
    };

    auto lca = [&](int a, int b) -> int {
        if(isAncestor(a, b)) return a;
        if(isAncestor(b, a)) return b;

        for(int i = h-1; i >= 0; i--){
            if(not isAncestor(up[i][a], b)){
                a = up[i][a];
            }
        }
        return up[0][a];
    };

    auto distlca = [&](int a, int b) -> int{
        return depth[a] + depth[b] - 2*depth[lca(a, b)];
    };

    for(int i = 0; i < q; i ++){
        if(i % block == 0){ // Init of a block 
            while(sz(become_red)) {
                reds.push_back(become_red.back());
                become_red.pop_back();
            }

            bfs();
        }

        auto [t, a] = queries[i];
        if(t == 1){ // new red
            become_red.push_back(a);
        }
        else {

            int mydist = dist[a];
            for(int el : become_red){
                mydist = min(mydist, distlca(el, a));
            }

            cout << mydist << endl;
        }
    }
    return 0;
} 