#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast") 
#pragma GCC target("avx2")

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<vector<int>> g;
queue<int> queries, order;
vector<bool> live;
int timer;

void dfs(int v, int p){
    order.push(v);
    for(int u: g[v]) if(u != p) dfs(u, v);
}


int main(){ _
    int q, t, x; cin >> q;
    g.resize(1e5 + 10), live.resize(1e5 + 10, 1);
    while(q --){
        cin >> t >> x; x--;
        if(t == 1){
            g[x].push_back(++timer);
            g[timer].push_back(x);
        }else queries.push(x);
    }

    dfs(0, 0);
    while(!queries.empty()){
        q = queries.front(); queries.pop();
        live[q] = false;
        while(!live[order.front()]) order.pop();
        cout << order.front() + 1 << endl;
    }

    return 0;
} 
