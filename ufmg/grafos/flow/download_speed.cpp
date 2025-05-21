#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

struct FlowEdge {
    int v, u;
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap){}
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

    Dinitz(int n, int s, int t) : n(n), s(s), t(t){
        adj.resize(n), level.resize(n), ptr.resize(n);
    }

    void add_edges(int v, int u, ll cap){
        edges.push_back({v, u, cap});
        edges.push_back({u, v, 0});     // Capacidade residual

        adj[v].push_back(m);        // Armazendo o id da aresta no vetor de adjacência
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs(){
        while(!q.empty()){
            int v = q.front(); q.pop();

            for(int id: adj[v]){
                if(edges[id].cap - edges[id].flow < 1) continue; // Aresta
                if(level[edges[id].u] != -1) continue;           // Ja cheguei no vertice

                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u); 
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, ll pushed){
        if(pushed == 0) return 0;
        if(v == t) return pushed;

        for(int& cid = ptr[v]; cid < sz(adj[v]); cid++){
            int id = adj[v][cid]; // Percorrendo as arestas adjacentes a v
            int u = edges[id].u;

            if(level[v] + 1 != level[u] or edges[id].cap - edges[id].flow < 1)
                continue; // Nao eh uma aresta valida no momento

            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));

            if(tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow(){
        ll f = 0;
        while(1){
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if(!bfs()) break;
            
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, flow_inf)){
                f += pushed;
            }
        }
        return f;
    }
};


int main(){ _

    int n, m; cin >> n >> m;
    Dinitz dz(n, 0, n-1);
    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a --, b--;
        dz.add_edges(a, b, c);
    }
    cout << dz.flow() << endl;
    return 0;
}