#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()


struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < (int)g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};


// Quero encontrar as arestas que estão em algum corte mínimo
// e recuperar as arestas do corte. 


int main(){ _
    int n, m; cin >> n >> m;
    dinitz dz(n);
    
    
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        dz.add(a, b, 1);
        dz.add(b, a, 1);
    }
    
    int flow = dz.max_flow(0, n-1); 

    vector<bool> vis(dz.g.size(), false);
    auto dfs = [&](auto& dfs, int v) -> void {
        vis[v] = true;
        for(dinitz::edge u : dz.g[v]){
            if(!vis[u.to] and u.flow < u.cap){
                dfs(dfs, u.to);
            }
        }
    };

    dfs(dfs, 0);

    vector<pair<int, int>> res;
    for(int i = 0; i < sz(dz.g); i++){
        for(auto e: dz.g[i]){
            if(vis[i] and !vis[e.to] and !e.res)
                res.push_back({i, e.to});
        }
    }

    cout << flow << endl;

    for(auto [a, b] : res)
        cout << a + 1 << " " << b + 1 << endl;    
    return 0;
}