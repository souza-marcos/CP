#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

const int MAX = 30;

vector<vector<int>> g;  
int vis[MAX];
set<int> comp;

void dfs(int node){
    vis[node] = true;
    comp.insert(node);
    for(auto el: g[node]) if(!vis[el]) dfs(el);
}

void solve(){
    memset(vis, 0, sizeof vis);
    int n, m; cin >> n >> m;
    g.clear(); g.resize(n + 1);
    while(m --){
        char a, b; cin >> a >> b;
        int newa = a - 'a', newb = b - 'a';
        g[newa].push_back(newb);
        g[newb].push_back(newa);
    }
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]) {
            if(comp.size() != 0){
                for(auto el: comp) cout << (char)(el + 'a') << ",";
                cout << endl;
                comp.clear();
            }
            dfs(i); cont ++;
        }
    }
    if(comp.size() != 0){
        for(auto el: comp) cout << (char)(el + 'a') << ",";
        cout << endl;
        comp.clear();
    }

    cout << cont << " connected components\n\n";

}

int main(){_

    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cout << "Case #" << i + 1  << ":" << endl;
        solve();  
    }

    return 0;
}