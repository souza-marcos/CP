#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int n, m; cin >> n >> m;
    vector<int> vis(n, 0), res;
    vector<vector<int>> g(n);

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
    }

    vector<int> ind(n);
    for(auto &row: g){
        for(int u : row) ind[u] ++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i ++) 
        if(ind[i] == 0) pq.push(i);

    while(sz(pq)){
        int cur = pq.top(); pq.pop();
        res.push_back(cur);
        for(int u : g[cur]){
            if(--ind[u] == 0) pq.push(u);
        }
    }

    if(sz(res) == n){
        for(auto el: res) cout << el + 1 << " ";
        cout << endl;
    } else 
        cout << -1 << endl;

} 
