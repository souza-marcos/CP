// https://cses.fi/problemset/task/1674
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, timer = 0; 
vector<vector<int>> g;
vector<int> pre, pos;

void dfs(int p, int v){
    pre[v] = timer;
    for(int u: g[v]) if(u != p) ++timer, dfs(v, u);
    pos[v] = timer;
}

int main(){ _
    cin >> n;
    g.resize(n), pre.resize(n), pos.resize(n);
    for(int i = 1; i < n; i ++){
        int boss; cin >> boss; boss --;
        g[i].push_back(boss);
        g[boss].push_back(i);
    }

    dfs(-1, 0);
    for(int i = 0; i < n; i ++){
        cout << pos[i] - pre[i] << " ";
    }
    cout << endl;
    return 0;
} 
