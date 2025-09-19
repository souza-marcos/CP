#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    //  DP on the condesed graph

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n), g_reversed(n);

    vector<ll> coin(n);
    for(ll& el : coin) cin >> el;

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g_reversed[b].push_back(a);
    }

    vector<int> color(n, 0), order;
    auto dfs1 = [&](auto&& self, int v) -> void {
        color[v] = 1;   
        for(int u : g[v]){
            if(color[u] == 0) 
                self(self, u);
        }

        order.push_back(v);
        color[v] = 2;
    };

    for(int i = 0; i < n; i ++){
        if(color[i] == 0) dfs1(dfs1, i);
    }

    reverse(order.begin(), order.end());

    vector<ll> comp(n, -1), coin_condensed;
    int cnt = 0;

    auto dfs2 = [&](auto&& self, int v) -> ll {
        color[v] = 1;
        ll acc = coin[v];
        for(int u : g_reversed[v]){
            if(color[u] == 0) 
                acc += self(self, u);
        }
        comp[v] = cnt;
        color[v] = 2;
        return acc;
    };

    color.assign(n, 0);
    for(int v : order){
        if(color[v] == 0){
            ll acc = dfs2(dfs2, v);
            cnt ++;
            coin_condensed.push_back(acc);
        }
    }

    // Quero condensar o grafo 
    vector<vector<int>> g_condensed(cnt);
    for(int v = 0; v < n; v ++){
        for(int u: g[v]) {
            if(comp[v] != comp[u]){
                g_condensed[comp[v]].push_back(comp[u]);
            }
        }
    }

    // Quero fazer a dp no grafo condensado
    vector<ll> dp(cnt, -1);
    auto dfs3 = [&](auto&& self, int v) -> ll {
        if(dp[v] != -1) return dp[v];
        ll res = 0;
        for(int u : g_condensed[v]){
            res = max(res, self(self, u));
        }
        return dp[v] = res + coin_condensed[v];
    };

    ll maxv = -LINF;
    for(int i = 0; i < cnt; i ++){
        maxv = max(maxv, dfs3(dfs3, i));
    }
    cout << maxv << endl;
}