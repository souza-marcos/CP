#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n; cin >> n;
    vector<set<int>> sets(n);
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        sets[i].insert(a);
    } 

    vector<vector<int>> g(n);

    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> res(n, 0);

    // Quero que junte do menor para o maior.
    auto merge = [&](int a, int b) -> int {
        if(sz(sets[a]) < sz(sets[b])) swap(a, b);
        sets[a].merge(sets[b]);
        return a;
    };  

    auto dfs = [&](auto&& self, int v, int p) -> int{
        int myidx = v;
        for(int u : g[v]) if(u != p){
            int idx = self(self, u, v);
            myidx = merge(idx, myidx);
        }
        res[v] = sz(sets[myidx]);
        return myidx;
    };

    dfs(dfs, 0, -1);

    for(int el : res) cout << el << " ";
    cout << endl;
    return 0;
} 
