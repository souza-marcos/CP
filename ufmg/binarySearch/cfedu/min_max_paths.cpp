#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<vector<pair<int, int>>> g; // in_node, weight 
vector<int> parent, saved;

int n, m, d;

bool bfs(int v, int peso_max){
    queue<pair<int, int>> q; // vertice, deep
    q.push({0, 0});
    vector<bool> vis(n, false);
    parent.assign(n, -1);
    while(!q.empty()){
        auto [v, deep] = q.front(); q.pop();

        if(deep > d) return false;
        if(v == n -1) return true;

        for(auto [u, w]: g[v]){
            if(!vis[u] and w <= peso_max){
                vis[u] = true;
                q.push({u, deep + 1});
                parent[u] = v;
            }
        }
    }
    return false;
}

bool valid(int peso_max){
    if(bfs(0, peso_max)){
        saved = parent;
        return true;
    }
    return false;
}

int main(){ _
    cin >> n >> m >> d;
    g.resize(n);

    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a --, b--;
        g[a].push_back({b, c});
    }

    int l = -1, r = 1e9 + 2;
    while (l + 1 < r)
    {
        int m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    
    if(r == 1e9 + 2){ cout << -1 << endl; return 0; }
    
    vector<int> path; path.push_back(n-1);
    while(path.back() != 0){
        path.push_back(saved[path.back()]);
    }
    reverse(path.begin(), path.end());
    cout << sz(path) -1 << endl;
    for(auto el: path) cout << el + 1 << " ";
    cout << endl;
    
    return 0;
} 
