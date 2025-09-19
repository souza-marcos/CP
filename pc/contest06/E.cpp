#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

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

int main(){ _
    int n_skills, m_achiv; cin >> n_skills >> m_achiv;
    vector<int> cost_skill(n_skills), reward_achiv(m_achiv);
    for(int& el: cost_skill) cin >> el;
    for(int& el: reward_achiv) cin >> el;

    vector<vector<int>> dependency(m_achiv, vector<int>(n_skills));
    for(auto& row: dependency){
        for(auto& needed : row) cin >> needed;
    }

    // Quero construir um grafo


    int node_idx = 0;
    int source = node_idx ++, sink = node_idx ++;
    vector<int> idx_achiv(m_achiv);
    for(int i = 0; i < m_achiv; i ++){
        idx_achiv[i] = node_idx ++;
    }
    vector<vector<int>> idx_level_skill(n_skills, vector<int>(6));
    for(int i = 0; i < n_skills; i ++){
        for(int j = 2; j <= 5; j ++){
            idx_level_skill[i][j] = node_idx++;
        }
    }

    dinitz dz(node_idx);
    ll sum = 0;
    for(int i = 0; i < m_achiv; i ++){
        dz.add(source, idx_achiv[i], reward_achiv[i]);

        for(int j = 0; j < n_skills; j ++){
            for(int k = 2; k <= dependency[i][j]; k ++){
                dz.add(idx_achiv[i], idx_level_skill[j][k], INF);
        
            }
        }
        sum += reward_achiv[i];
    }
    
    for(int i = 0; i < n_skills; i ++){
        for(int j = 2; j <= 5; j ++){
            dz.add(idx_level_skill[i][j], sink, cost_skill[i]);
        }
    }

    int flow = dz.max_flow(source, sink);
    cout << sum - flow << endl;
    return 0;
} 
