#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

const int MAX = 1e5 + 10;
vector<vector<pair<int, int>>> seg(4*MAX);

vector<int> tin, tout;
vector<int> order, depth;

typedef vector<pair<int, int>> vpii;

vpii combine(vpii left, vpii right){
    vpii res;
    int i = 0, j = 0; 
    while(i < sz(left) and j < sz(right)){
        auto [key1, val1] = left[i];
        auto [key2, val2] = right[j];
        if(key1 < key2) res.push_back({key1, val1}), i ++;
        else if(key2 < key1) res.push_back({key2, val2}), j ++;
        else res.push_back({key2, val1 + val2}), i ++, j ++;
    }
    while(i < sz(left))
        res.push_back(left[i ++]);

    while(j < sz(right))
        res.push_back(right[j ++]);

    return res;
}

vpii build(int p, int l, int r){
    if(l == r) return seg[p] = {{depth[order[l]],1}};
    int m = (l + r)>>1;
    return seg[p] = combine(build(p << 1, l, m), build(p << 1 | 1, m+1, r));
}

int query(int p, int l, int r, int lq, int rq, int pos){
    if(lq > r or rq < l) return 0;
    if(l >= lq and r <= rq) {
        auto it = lower_bound(seg[p].begin(), seg[p].end(), make_pair(pos, 0));
        if(it == seg[p].end() or it->first != pos) return 0;
        return it->second;
    }
    int m = (l + r)>>1;
    return query(p << 1, l, m, lq, rq, pos) + query(p << 1 | 1, m + 1, r, lq, rq, pos);
}

int main(){ _
    vector<int> roots;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i ++){
        int p; cin >> p; p --;
        if(p == -1) roots.push_back(i);
        else {
            g[p].push_back(i),
            g[i].push_back(p);
        }
    }

    // Quero criar um tour euleriano para cada raiz
    // e construir uma seg tree (merge sort tree) para
    // armazenar a contagem de vertices de cada profundidade

    int timer = 0, l = ceil(log2(n));
    vector<vector<int>> up(n, vector<int>(l + 1, -1));
    depth.resize(n);
    tin.resize(n), tout.resize(n);
    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        tin[v] = timer ++;
        order.push_back(v);
        up[v][0] = p;

        for(int i = 1; i <= l; i ++){
            if(up[v][i-1] == -1) break;
            up[v][i] = up[up[v][i-1]][i-1];
        }

        for(auto u : g[v]) if(u != p){
            depth[u] = depth[v] + 1;
            dfs(dfs, u, v);
        }
        tout[v] = timer;
    };
    for(auto el : roots)
        depth[el] = 0,
        dfs(dfs, el, -1);

    build(1, 0, n-1);
    
    auto isAncestor = [&](int anc, int a){
        return tin[anc] <= tin[a] and tout[anc] >= tout[a];
    };

    auto kth = [&](int a, int k) -> int {
        int i = 0;
        while(k > 0){
            if(a == -1) break;
            if(k & 1) a = up[a][i];
            i ++, k >>= 1;
        }
        return a;
    };


    int q; cin >> q;
    while(q --){
        int v, p; cin >> v >> p;
        v --;

        int anc = kth(v, p);
        if(anc == -1) 
            cout << 0 << " ";
        else{
            cout << query(1, 0, n-1, tin[anc], tout[anc], depth[v]) -1 << " ";
        }
    }
    cout << endl;
    return 0;
} 
