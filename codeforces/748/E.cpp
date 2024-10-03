#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, k;
vector<vector<int>> g;


void solve(){
    cin >> n >> k;

    g.assign(n, {});
    for(int i = 1; i < n; i ++){
        int u, v; cin >> u >> v; u --, v--;
        g[u].push_back(v), g[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vector<int> dist(n, -1); 
    vector<int> deg(n);

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        deg[i] = sz(g[i]);
        if(sz(g[i]) <= 1) 
            dist[i] = 1, 
            q.push({i, 1});
    }

    // cout << "SIZE => " << sz(q) << endl;

    while(!q.empty()){
        auto [cur, dist_c] = q.front();
        q.pop();
        for(int el: g[cur]) 
            if(dist[el] < 0){
                deg[el] --;
                if(deg[el] <= 1)
                    dist[el] = dist_c + 1,
                    q.push({el, dist_c + 1});
            }
    }

    for(int i = 0; i < n; i ++){
        if(dist[i] <= k) cnt++;
    }

    cout << n - cnt << endl;
}


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
