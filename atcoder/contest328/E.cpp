#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

vector<int> id, sz;

int find(int x){
    return id[x] = (id[x] == x ? x: find(id[x]));
}

void uni(int a, int b){
    a = find(a), b = find(b);

    if(sz[a] > sz[b]) swap(a, b);

    id[a] = b;
    sz[b] += sz[a];
}


int main(){ _


    int n, m; ll k; cin >> n >> m >> k;
    id.resize(n);
    sz.resize(n, 1);
    iota(id.begin(), id.end(), 0);

    vector<tuple<ll, int, int>> edges(m); // weight, a, b 
    for(auto& [w, a, b]: edges){
        cin >> a >> b >> w; a --, b --;
    }

    sort(edges.begin(), edges.end());


    int cont = 0;
    ll sum = 0;
    for(int i = 0; i < m; i ++){
        if(cont == n - 1) break;
        auto [w, a, b] = edges[i];
        if(find(a) != find(b)){
            sum = (sum + w);
            cont ++;
            uni(a, b);
        }
    }

    cout << sum % k << endl;

    return 0;
} 
