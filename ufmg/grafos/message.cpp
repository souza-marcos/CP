#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g(1e5+10);
vector<bool> vis(1e5+10);
vector<int> pai(1e5+10);

void bfs(int v){
    queue<int> q;
    q.push(v); vis[v] = true;

    pai[v] = v;

    while (!q.empty())
    {
        int w = q.front(); q.pop();

        for(auto u: g[w])
            if(!vis[u]){
                q.push(u); vis[u] = true;
                pai[u] = w;
            }
    }
}

vector<int> path(int v){
    vector<int> ret;
    if(!vis[v]) return ret;


    ret.push_back(v);
    while(pai[v] != v){
        v = pai[v];
        ret.push_back(v);
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

int main(){ _

    int n, m; cin >> n >> m;
    while(m --){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(0);
    vector<int> ans = path(n - 1);

    if(ans.size() == 0) cout << "IMPOSSIBLE" << endl;
    else{
        cout << ans.size() << endl;
        for(auto el: ans) cout << el + 1 << " ";
        cout << endl;
    }

    return 0;
} 
