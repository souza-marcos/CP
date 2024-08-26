#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n, m;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX, false);
vector<int> ans;

void dfs(int node){
    vis[node] = true;
    for(int adj: g[node]) if(!vis[adj]) dfs(adj);
    ans.push_back(node);
}

int main(){ _
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);

    reverse(ans.begin(), ans.end());

    for(int el: ans) cout << el + 1 << " ";
    cout << endl;

    return 0;
} 
