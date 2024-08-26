#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

vector<vector<int>> g(1e5 + 10);
vector<int> dist(1e5 + 10, -1);
vector<int> parent(1e5 + 10, 0);

void bfs(int node){
    dist[node] = 0; parent[node] = node;
    queue<int> level; level.push(node);
    while(!level.empty()){
        int cur = level.front(); level.pop();
        for(auto adj: g[cur]) if(dist[adj] == -1){
            dist[adj] = dist[cur] + 1;
            level.push(adj);
            parent[adj] = cur;
        }
    }
}


int main(){ _

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);

    if(dist[n] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[n] + 1 << endl;
        int cur = n; vector<int> path;
        while(parent[cur] != cur){
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(cur);
        for(auto it = path.rbegin(); it != path.rend(); it++) cout << *it << " ";
        cout << endl;
    }

    return 0;
} 
