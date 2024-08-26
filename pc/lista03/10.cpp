#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;
#define sz(x) (int)x.size()

struct FlowEdge
{
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinitz
{
    const ll flow_inf = LINF;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinitz(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n), level.resize(n), ptr.resize(n);
    }

    void add_edges(int v, int u, ll cap)
    {
        edges.push_back({v, u, cap});
        edges.push_back({u, v, 0}); // Capacidade residual

        adj[v].push_back(m); // Armazendo o id da aresta no vetor de adjacência
        adj[u].push_back(m + 1);
        m += 2;
    }

    void reset_edges(){
        for(auto& el: edges) el.flow = 0;
    }

    bool bfs()
    {
        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue; // Aresta
                if (level[edges[id].u] != -1)
                    continue; // Ja cheguei no vertice

                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;

        for (int &cid = ptr[v]; cid < sz(adj[v]); cid++)
        {
            int id = adj[v][cid]; // Percorrendo as arestas adjacentes a v
            int u = edges[id].u;

            if (level[v] + 1 != level[u] or edges[id].cap - edges[id].flow < 1)
                continue; // Nao eh uma aresta valida no momento

            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));

            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow()
    {
        ll f = 0;
        while (1)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;

            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, flow_inf))
            {
                f += pushed;
            }
        }
        return f;
    }
};


void solve(){
    int n, m; cin >> n >> m;
    
    if(n == 1){ cout << 0 << endl; return;}

    map<pair<int, int>, ll> cn;

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        ll c; cin >> c;
        cn[{a, b}] = c;
    }

    Dinitz d(n, 0, n-1);
    for(auto [key, c]: cn){
        auto [a, b] = key;
        d.add_edges(a, b, c);
        d.add_edges(b, a, c);
    }

    ll min_cut = LINF; 
    for(int i = 1; i < n; i++){
        d.t = i;
        d.reset_edges();
        min_cut = min(min_cut, d.flow());
    }
    cout << min_cut << endl;
}

int main(){_
    int t; cin >> t;
    while(t --) solve();
    return 0;
}