#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int max_dist, max_node;
vector<vector<int>> g;
int n; 

void dfs(int v, int p, int h){
    if(max_dist < h) max_dist = h, max_node = v;
    for(int u: g[v]) if(u != p) dfs(u, v, h+1);
}


int main(){ _
    cin >> n;
    int a, b;
    g.resize(n);
    for(int i = 1; i < n; i ++){
        cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(0,0,0);
    dfs(max_node, max_node, 0);
    cout << max_dist * 3 << endl;
    return 0;
} 
