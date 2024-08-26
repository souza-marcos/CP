#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;
vector<int> xp;

int find(int x){
    return (id[x] == x? x: find(id[x]));
}

void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v); // sz[u] is less than sz[v]
    id[u] = v;
    sz[v] += sz[u];

    xp[u] -= xp[v];       // Child
}

int getxp(int x, int acc){ // O(n)
    if(x == id[x]) return acc + xp[x];
    return getxp(id[x], acc + xp[x]);
}

int main(){ _

    int n, m; cin >> n >> m;
    id.resize(n);
    iota(id.begin(), id.end(), 0);
    sz.resize(n, 1);
    xp.resize(n, 0);

    while (m --)
    {
        string q; cin >> q;
        int u, v;
        if(q == "add"){
            cin >> u >> v; u--;
            u = find(u);
            xp[u] += v;
        } else if(q == "join"){
            cin >> u >> v; u--, v--;
            uni(u, v);
        } else{
            cin >> u; u --;
            cout << getxp(u, 0) << endl;
        }
    }
    return 0;
} 
