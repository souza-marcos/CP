#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, m; cin >> n >> m;
    vector<vector<int>> g_reversed(n);
    vector<int> in_degree(n), order;
        
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g_reversed[b].push_back(a);
        in_degree[a] ++;
    }
    
    priority_queue<int> pq; // max-heap

    for(int i = 0; i < n; i ++){
        if(in_degree[i]==0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        order.push_back(v);

        for(int u : g_reversed[v]){
            in_degree[u] --;
            if(in_degree[u] == 0) pq.push(u);
        }
    }

    reverse(order.begin(), order.end());

    for(int el : order){
        cout << el + 1 << " ";
    }

    cout << endl;
}
