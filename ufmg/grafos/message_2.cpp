#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX_SIZE = 1e5 + 10;

vector<vector<int>> g;
int dist[MAX_SIZE], par[MAX_SIZE], n, m; 


void bfs(int x){
    queue<int> q;
    q.push(x);
    dist[x] = 0; 

    while(!q.empty()){
        int cur = q.front(); q.pop();

        for(auto el: g[cur]) if(dist[el] == -1){
            dist[el] = dist[cur] + 1;
            q.push(el);
            par[el] = cur;
        }
    }
}


int main(){ _
    cin >> n >> m;
    memset(dist, -1, sizeof dist);
    g.resize(n);
    memset(par, -1, sizeof par);
    
    int a, b;
    while(m --){
        cin >> a >> b; a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);

    }

    bfs(0);
    if(dist[n-1] == -1) cout << "IMPOSSIBLE" << endl;
    else {
        stack<int> s;
        int cur = n - 1;
        s.push(cur);
        while(cur != 0){
            cur = par[cur];
            s.push(cur);
        }

        cout << s.size() << endl;

        while(!s.empty()) {
            cout << s.top() + 1 << " "; s.pop();
        }
        cout << endl;
    }
    return 0;
} 
