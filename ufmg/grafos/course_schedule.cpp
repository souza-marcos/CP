#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n, m;
vector<vector<int>> g(MAX);
vector<int> color(MAX, 0);
vector<int> ans;

bool dfs(int node){
    color[node] = 1;
    for(int adj: g[node]) {
        if(color[adj] == 1) return false;
        else if(color[adj] == 0 and !dfs(adj)) return false;
    }
    color[node] = 2;
    ans.push_back(node);
    return true;
}

int main(){ _
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++) if(color[i] == 0 and !dfs(i)){
        cout << "IMPOSSIBLE\n"; exit(0);
    }

    reverse(ans.begin(), ans.end());

    for(int el: ans) cout << el + 1 << " ";
    cout << endl;

    return 0;
} 
