#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

#define int ll

struct DSU {
    vector<int> id, szo;

    int find(int x){
        return id[x] = (id[x] == x ? x : find(id[x]));
    }

    void uni(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(szo[a] > szo[b]) swap(a, b);

        id[a] = b;
        szo[b] += szo[a];
    }
};

void solve(){
    int n, m1, m2; cin >> n >> m1 >> m2;

    DSU g;
    g.id.resize(n), g.szo.resize(n, 1);
    iota(g.id.begin(), g.id.end(), 0);

    vector<pair<int, int>> edges_F;
    for(int i = 0; i < m1; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        edges_F.emplace_back(a, b);
    }
    for(int i = 0; i < m2; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g.uni(a, b);
    }

    DSU f;
    f.id.resize(n), f.szo.resize(n, 1);
    iota(f.id.begin(), f.id.end(), 0);

    int cnt = 0;
    
    // Removing edges
    for(auto [a, b] : edges_F){
        if(g.find(a) == g.find(b)) f.uni(a, b);
        else cnt ++;
    }

    // Counting components of both
    int cntf = 0, cntg = 0;
    set<int> repr;
    for(auto el: f.id) repr.insert(f.find(el));
    cntf = repr.size();

    repr.clear();
    for(auto el: g.id) repr.insert(g.find(el));
    cntg = repr.size();
    
    cnt += max(0LL, cntf - cntg);
    cout << cnt << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
