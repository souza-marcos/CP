#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;

int find(int x){
    return (id[x] == x? x: find(id[x]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    id[a] = b;

    sz[b] += sz[a];
}

int main(){ _
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> g(m); // weight, a, b

    id.resize(n); sz.resize(n, 1);
    iota(id.begin(), id.end(), 0);

    for(auto& [w, a, b]: g) {
        cin >> a >> b >> w;
        a --; b --;
    }
    sort(g.begin(), g.end());

    int cont = 0;
    ll cost = 0;
    for(auto [w, a, b]: g){
        if(find(a) != find(b)){
            uni(a, b); cont ++;
            cost += w;
        }
        if(cont == n-1) break;
    }

    cout << cost << endl;
    return 0;
} 
