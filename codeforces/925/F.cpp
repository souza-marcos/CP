#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll 

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i < k; i ++){
        vector<int> arr(n); for(int& el : arr) cin >> el, el --;
        for(int i = 1; i + 1 < n; i ++){
            g[arr[i]].push_back(arr[i+1]);
        }
    }
    for(auto &row : g){
        sort(row.begin(), row.end());
        row.erase(unique(row.begin(), row.end()), row.end());
    }

    // Check the graph is a DAG
    vector<int> color(n);
    auto dfs = [&](auto&& self, int v) -> bool{
        color[v] = 1;
        for(auto u : g[v]){
            if(color[u] == 1) return false;
            if(color[u] == 0 and !self(self, u)) return false;
        }
        color[v] = 2;
        return true;
    };
    bool ok = true;
    for(int i = 0; i < n; i ++){
        if(color[i] == 0 and !dfs(dfs, i))
            ok = false; 
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
