#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<int> szo, id;

int find(int a){
    return id[a] = (a == id[a]? a : find(id[a]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(szo[a] > szo[b]) swap(a, b);
    id[a] = id[b];
    szo[b] += szo[a];
}

int main(){ _
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> g; // Edges=> cost, a, b;

    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost; a --, b--;
        g.push_back({cost, a, b});
    }

    id.resize(n), szo.resize(n, 1);
    iota(id.begin(), id.end(), 0);
    sort(g.begin(), g.end());

    ll total_cost = 0;
    int cont = 0;
    for(auto [cost, a, b] : g){
        if(find(a) != find(b)){
            total_cost += cost;
            uni(a, b);
            cont ++;
        }
        if(cont == n-1) break;
    }
    cout << total_cost << endl;

    return 0;
} 
