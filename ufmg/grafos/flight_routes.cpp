#include <bits/stdc++.h>
using namespace std;
using std::cin;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n, m;
vector<vector<int>> g(MAX);
vector<int> color(MAX, 0);
vector<int> order;

bool dfs(int v){
    color[v] = 1;
    for(int adj: g[v]){
        if(color[adj] == 1) return false;
        else if(color[adj] == 0 and !dfs(adj)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
}

int main(){ _
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++) if(color[i] == 0 and !dfs(i)) { cout << "IMPOSSIBLE\n"; return 0; }

    vector<int> dist(n, -1), par(n, -1);
    dist[0] = 0;
    par[0] = 0;
    for(auto it = order.rbegin(); it != order.rend(); ++it){
        if(dist[*it] == -1) continue;
        for(int adj: g[*it]){
            if(dist[*it] + 1 > dist[adj]){
                par[adj] = *it;
                dist[adj] = dist[*it] + 1;
            }
        }
    }

    if(dist[n -1] == -1) { cout << "IMPOSSIBLE\n"; return 0; }
    cout << dist[n -1] + 1 << endl;
    int i = n -1;
    vector<int> st;
    while(par[i] != i){
        st.push_back(i); i = par[i];
    }
    st.push_back(0);
    for(auto it = st.rbegin(); it != st.rend(); ++ it) cout << *it + 1 << " ";
    cout << endl;

    return 0;
} 
