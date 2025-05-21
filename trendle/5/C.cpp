#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


vector<int> id, szo;

int find(int x){
    return id[x] = (x == id[x] ? x : find(id[x]));
}

void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(szo[u] > szo[v]) swap(u, v);

    id[u] = v;
    szo[v] += szo[u];
}


int main(){ _ 
    int n, m; cin >> n >> m;
    szo.resize(n + m, 0), id.resize(n+m);
    for(int i = 0; i < n; i ++) szo[i] = 1;
    iota(id.begin(), id.end(), 0);
    
    for(int i = 0; i < m; i ++){
        int k; cin >> k; 
        for(int j = 0; j < k; j ++){
            int a; cin >> a; a--;
            uni(a, n+i);
        }
    }

    for(int i = 0; i < n; i ++){
        cout << szo[find(i)] << " ";
    }
    cout << endl;
} 
