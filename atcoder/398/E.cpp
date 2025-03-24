#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ // _

    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges;
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        g[a].push_back(b), g[b].push_back(a);
        edges.push_back({a, b});
    }
    vector<int> pa, pb;


    auto dfs = [&](auto &&self, int v, int p, bool a) -> void {
        if(a) pa.push_back(v);
        else pb.push_back(v);
        for(auto u: g[v]) if(u != p) self(self, u, v, !a);
    };

    dfs(dfs, 0, -1, true);

    ll total = sz(pa) * sz(pb) - sz(edges);
    
    set<pair<int, int>> pode;
    for(auto el : pa){
        for(auto it: pb){
            if(el > it) pode.insert({it, el});
            else pode.insert({el, it});
        }
    }

    for(auto [a, b]: edges){
        if(pode.count({a, b})) pode.erase({a, b});
    }

    bool first = total % 2 != 0; 
    if(!first) cout << "Second\n";
    else cout << "First\n";
    cout.flush();
    

    for(int i = 0; i < total; i ++){
        if(first){
            auto [a, b] = *pode.begin();
            pode.erase({a, b});
            cout << a + 1 << " " << b + 1 << endl;
            cout.flush();
        }else{
            int a, b; cin >> a >> b;
            if(a == -1 and b == -1){
                return 0;   
            }
            if(a > b) swap(a, b);
            assert(pode.count({a-1, b-1}));
            pode.erase({a-1, b-1});
        }
        first = !first;
    }

    int a, b; cin >> a >> b;
    return 0;
} 
