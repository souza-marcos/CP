#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ //_ 

    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<ll> weight, par(n, -1); 
    for(int i = 0 ; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a --, b--;
        edges.push_back({a, b});
        weight.push_back(c);
    }

    vector<ll> dist(n, 0);

    int x = -1;
    for(int i = 0; i < 2*n; i ++){
        x = -1;
        for(int j = 0; j < m; j ++){
            auto [a, b] = edges[j];
            if(dist[b] > dist[a] + weight[j]){
                dist[b] = dist[a] + weight[j];
                par[b] = a;
                if(x == -1) x = a;
            }
        }
    }

    if(x == -1){
        cout << "NO\n";
    } else {
        int end = x;
        vector<int> ans = {x};
        vector<int> color(n, 0);
        color[x] = 1;

        while(par[x] != end and color[par[x]] == 0){
            // cout << x << " " << par[x] << " " << end << endl;
            ans.push_back(par[x]);
            x = par[x];
            color[x] = 1;
        }
        
        ans.push_back(par[x]);
        set<int> ok;
        cout << "YES\n";
        for(auto it = ans.rbegin(); it != ans.rend(); ++it){
            cout << 1 + *it << " ";
            if(ok.count(*it)){
                cout << endl;
                exit(0);
            }
            ok.insert(*it);
        }
        
    }
}