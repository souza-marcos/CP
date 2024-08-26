#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;
#define sz(x) (int)x.size()

struct FlowEdge {
    int v, u; 
    ll cap, flow = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap){}
};

struct Dinitz{
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
        edges.push_back({u, v, 0}); // Aresta residual

        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs(){
        while(!q.empty()){
            int v = q.front(); q.pop();

            for(int id: adj[v]){
                if(edges[id].cap - edges[id].flow < 1) continue; // Aresta saturada
                if(level[edges[id].u] != -1) continue; // Nivel ja visitado

                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }

        return level[t] != -1;
    }

    ll dfs(int v, ll pushed){
        if(pushed == 0) return 0;
        if(v == t) return pushed;

        for(int& cid = ptr[v]; cid < sz(adj[v]); cid ++){
            int id = adj[v][cid];
            int u = edges[id].u;

            if(level[v] + 1 != level[u] or edges[id].cap - edges[id].flow < 1) continue;

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

int n, m, g;
void solve() {
    vector<int> pts(n, 0);
    map<pair<int, int>, int> cnt; // <less, greater> = cnt
    for (int i = 0; i < g; i++) {
        int a, b; char s; cin >> a >> s >> b;

        if (s == '=') pts[a]++, pts[b]++;
        else if (s == '<') pts[b] += 2;
        else pts[a] += 2;

        if (a > b) swap(a, b);
        cnt[{a, b}]++;
    }

    int acc = 0;
    list<pair<int, int>> l;
    for (auto el : cnt) {
        auto [key, val] = el;
        auto [fr, sn] = key;
        if (fr == 0) {
            acc++;
            l.push_back(key);
        }
    }
    for (auto key : l) cnt.erase(key);

    int max_points = pts[0] + (m * (n - 1) - acc) * 2;

    int n_compl_edges = m * n * (n - 1) / 2 - g - acc;
    int tot = n - 1 + n_compl_edges + 2;
    Dinitz d(tot, 0, tot - 1);

    int i = n;
    int tot_edges = 0;
    for (auto [key, val] : cnt) {
        auto [fr, sn] = key;
        int rest = m - val;
        tot_edges += rest;
        while (rest--) {
            d.add_edges(0, i, 2);
            d.add_edges(i, fr, 2);
            d.add_edges(i, sn, 2);
            i++;
        }
    }

    for (int i = 1; i < n; i++) {
        int lim = max_points - pts[i] - 1;
        if (lim < 0) { cout << "N\n"; return; }
        d.add_edges(i, tot - 1, lim);
    }

    ll f = d.flow();
    if (f == tot_edges * 2) cout << "Y\n";
    else cout << "N\n";
}


int main(){
    while(cin >> n >> m >> g and n != 0) solve();
    return 0;
}
