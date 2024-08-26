#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;

int n, m; 
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

void dfs(int node){
    vis[node] = true;
    for(auto adj: g[node]){
        if(!vis[adj]) dfs(adj);
    }
}

int main(){ _

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a --, b --;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<pair<int, int>> roads;
    int prev = -1;
    for(int i = 0; i < n; i ++){
        if(!vis[i]){
            if(prev != -1) roads.pb({prev, i});
            prev = i;
            dfs(i);
        }
    }


    cout << roads.size() << endl;
    for(auto r : roads) cout << r.first + 1 << " " << r.second + 1 << endl;

    return 0;
} 
