#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    // Aparentemente, remover dois vertices de maior grau pode funcionar
    // Dois casos: |-> Remove dois adjacentes |-> não adjacentes

    int n; cin >> n;
    vector<vector<int>> g(n);
    set<pair<int, int>> edges;
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b),
        g[b].push_back(a);

        edges.insert({a,b});
        edges.insert({b,a});
    }

    int maxv = 0;
    if(n == 2){
        cout << 0 << endl;
        return;
    }

    // Adjacentes
    for(auto [a, b] : edges){
        maxv = max(maxv, sz(g[a])+ sz(g[b])-2);
    }

    vector<pair<int, int>> ng; // |N(v)|, v
    for(int i = 0; i < n; i ++){
        ng.push_back({sz(g[i]), i});
    }

    sort(ng.rbegin(), ng.rend());

    for(int i = 0; i < 2; i ++){
        for(int j = i + 1; j < n; j ++){
            if(edges.count({ng[i].second, ng[j].second}) == 0){
                maxv= max(maxv, ng[i].first + ng[j].first -1);
            }
        }
    }
    


    cout << maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
