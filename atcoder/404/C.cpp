#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;
    vector<int> vis(n, 0);
    
    vector<vector<int>> g(n);
    vector<int> degree(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b),
        g[b].push_back(a);

        degree[a] ++, degree[b] ++;
    }

    queue<int> q; q.push(0);

    while(sz(q)){
        int v = q.front(); q.pop();
        vis[v] = 1;
        for(auto u : g[v]){
            if(!vis[u]) q.push(u);   
        }
    }


    for(int i = 0; i < n; i ++) 
        if(vis[i] == 0 and degree[i] != 2) { 
            cout << "No\n"; 
            return 0; 
        }
    cout << "Yes\n";
    return 0;
} 
