#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, m; 
vector<vector<int>> g;
vector<int> dist;

int main(){ _
    cin >> n >> m; 
    
    g.resize(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
    }

    dist.assign(n, -1);
    queue<int> q; q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(int u : g[v]) {
            if(u == 0){
                cout << dist[v] + 1 << endl;
                return 0;
            }
            if(dist[u] < 0) 
                dist[u] = dist[v] + 1,
                q.push(u);
        }
    }
    cout << -1 << endl;
    return 0;
} 
