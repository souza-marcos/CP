#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> g;

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while(!q.empty()){
        auto [cur, flow] = q.front(); q.pop();

        for(int next: g[cur]) if(parent[next] == -1 and capacity[cur][next]) {
            
            parent[next] = cur;
            int new_flow = min(flow, capacity[cur][next]);
            if(next == t) return new_flow;

            q.push({next, new_flow});
        }
    }

    return 0;
}

int maxflow(int s, int t){
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while((new_flow = bfs(s, t, parent))){
        flow += new_flow;
        cout << flow << endl;
        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[prev][cur] += new_flow;

            cur = prev;
        }
    }

    return flow;
}

int main(){
    cin >> n >> m;
    g.resize(n);
    capacity.resize(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        int a, b, cap; cin >> a >> b >> cap;
        a --, b--;

        g[a].push_back(b);
        g[b].push_back(a);

        capacity[a][b] = cap;
    }

    int res = maxflow(0, n-1);
    cout << res << endl;
    return 0;
} 
