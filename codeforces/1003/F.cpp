#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> id(n); for(auto& el: id) cin >> el, el --;
    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    string res(n, '0');

    for(int v = 0; v < n; v ++){
        sort(g[v].begin(), g[v].end(), [&](int a, int b){
            return (id[a] < id[b]);
        }); 

        int last = -1;
        for(int u: g[v]) {
            if(id[u] == last or id[u] == id[v]){
                res[id[u]] = '1';
            }

            last = id[u];
        }
    }
    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
