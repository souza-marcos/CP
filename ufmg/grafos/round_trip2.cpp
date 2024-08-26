#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;

vector<vector<int>> g(MAX);
vector<int> color(MAX, -1);
vector<int> par(MAX , -1);

int cycle_start, cycle_end;

bool dfs(int node){
    color[node] = 0;
    for(auto adj : g[node]){
        if(color[adj] == 0){ // Found a cycle
            cycle_start = node;
            cycle_end = adj;
            return true;
        }
        else if(color[adj] == -1){
            par[adj] = node;
            if (dfs(adj)) return true;
        }
           
    }
    color[node] = 1;
    return false;
}

int main(){ _
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a --, b --;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++){
        if(color[i] == -1 and dfs(i)){  // print cycle
            int cur = cycle_start;
            vector<int> cycle;
            while(cur != cycle_end){
                cycle.push_back(cur); cur = par[cur];
            }

            cycle.push_back(cycle_end);
            cycle.push_back(cycle_start);
            cout << cycle.size() << endl;
            for(auto it = cycle.rbegin(); it != cycle.rend(); ++it) cout << (*it) + 1 << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
} 
