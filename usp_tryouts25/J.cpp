#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

const ll mod = 1e9+7;

int32_t main() { _
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    
    vector<vector<int>> adj(n);
    while(m--) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> qto(n,0), qts(n,0), dist(n,INT_MAX);
    dist[s] = 0;
    qto[s] = 1;

    queue<int> q;
    q.push(s);
    int d = -1;
    
    while(not q.empty()) {
        if(dist[q.front()]==d) continue;
        d = dist[q.front()];

        vector<int> aux;
        while(q.size() and dist[q.front()]==d) {
            aux.push_back(q.front());
            q.pop();
        }

        for(int v:aux) for(int u:adj[v]) if(dist[u]==dist[v]) qts[u]=(qts[u]+qto[v])%mod;
        
        for(int v:aux) {
            for(int u:adj[v]) {
                if(dist[u]==INT_MAX) {
                    q.push(u);
                    dist[u] = dist[v]+1;
                }
                if(dist[u]==dist[v]+1) {
                    qto[u]+=qto[v];
                    qts[u]+=qts[v];
                    qts[u]%=mod;
                    qto[u]%=mod;
                    
                }
            }
        }
    }

    cout << qts[t]%mod << '\n';
}