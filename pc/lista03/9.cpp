#include <bits/stdc++.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
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

vector<vector<int>> g;
vector<vector<int>> memo(100, vector<int>(100));
vector<vector<int>> vis(100, vector<int>(100, -1));
int n, m, cnt = 0;

// Size of longest common of subsequence [1..i] for the first and [1..j] for the second
int dp(vector<int> &person, vector<int> &toy, int i, int j)
{
    if (i == sz(person) or j == sz(toy))
        return 0;
    int &v = vis[i][j];
    int &p = memo[i][j];
    if (v >= cnt)
        return p;
    v = cnt;

    if (person[i] == toy[j])
        return p = 1 + dp(person, toy, i + 1, j + 1);
    return p = max(dp(person, toy, i + 1, j), dp(person, toy, i, j + 1));
}

void solve()
{
    g.resize(n + m);

    // read input
    for (int i = 0; i < n + m; i++)
    {
        string s;
        cin >> s;
        g[i].resize(sz(s));
        map<char, int> cnt;
        for (int j = 0; j < sz(s); j++)
        {
            cnt[s[j]]++;
            g[i][j] = s[j] - 'A' + 1 + (cnt[s[j]] - 1) * 26;
            // cout << g[i][j] << " ";
        }
        // cout << endl;
    }

    Dinitz dz(n + m + 2, 0, n + m + 1);

    // Source edges
    for (int i = 1; i <= n; i++)
        dz.add_edges(0, i, 1);

    // Sink edges
    for (int i = n + 1; i <= n + m; i++)
        dz.add_edges(i, n + m + 1, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < n + m; j++)
        {
            int res = dp(g[i], g[j], 0, 0);
            int has = sz(g[i]) + sz(g[j]) - 2 * res;
            if (has % 5 == 0)
                dz.add_edges(i + 1, j + 1, 1);

            cnt++;
        }
    }

    cout << "P = " << dz.flow() * 100 / (double)n << endl;
}

int main()
{
    _
            cout
        << fixed << setprecision(2);
    while (cin >> n >> m and n != 0)
        solve();
}