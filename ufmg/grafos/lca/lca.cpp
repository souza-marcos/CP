#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<int> height, first, euler, segtree;
vector<bool> vis;
vector<vector<int>> g;
int n;

void dfs(int v, int h){
    vis[v] = true;
    height[v] = h;
    first[v] = euler.size();
    euler.push_back(v);

    for(auto u: g[v]) if(!vis[u]){
        dfs(u, h + 1);
        euler.push_back(v);
    }
}


// Build a segtree of nodes of minimum height in the range 
void build(int node, int l, int r){
    if(l == r) {
        segtree[node] = euler[l];
        return; 
    }

    int m = (l + r)/2;
    build(node << 1, l, m),
    build(node << 1 | 1, m + 1, r);

    int nodel = segtree[node << 1], noder = segtree[node << 1 | 1];
    segtree[node] = (height[nodel] < height[noder] ? nodel : noder);
}


int query(int a, int b, int node, int l, int r){
    if(b < l or a > r) return -1;
    if(a <= l and b >= r) return segtree[node];

    int m = (l + r)/2;

    int nodel = query(a, b, node << 1, l, m),
        noder = query(a, b, node << 1 | 1, m + 1, r);

    if(nodel == -1) return noder;
    if(noder == -1) return nodel;

    return (height[nodel] < height[noder] ? nodel: noder);
}

void init(){
    n = g.size();
    height.resize(n); 
    euler.reserve(n * 2); 
    vis.assign(n, false);
    first.resize(n);

    // Build Eulerian Tour of graph
    dfs(0, 0);

    int m = euler.size();
    segtree.resize(m * 4);

    // Build the Segment Tree of the minimum height 
    build(1, 0, m-1);
}


int main(){ _

    int n, m, q; cin >> n >> m >> q;
    g.assign(n, {});
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    init(); // Euler tour

    while (q --){
        int v, u; cin >> v >> u; v--, u--;

        int left = first[v], right = first[u];
        if(left > right) swap(left, right);

        cout << query(left, right, 1, 0, euler.size() -1) + 1 << endl;
    }

    // cout << "EULER: ";
    // for(auto el: euler) cout << el << " ";
    // cout << endl;

    // cout << "FIRST: ";
    // for(auto el: first) cout << el << " ";
    // cout << endl;

    // cout << "HEIGHT: ";
    // for(auto el: height) cout << el << " ";
    // cout << endl;


    // cout << "SEG: ";
    // for(auto el: segtree) cout << el << " ";
    // cout << endl;

    return 0;
} 
