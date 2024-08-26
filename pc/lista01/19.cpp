#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

vector<vector<pair<int, int>>> g;
vector<int> rep, sz;

int find(int a){
    return rep[a] = (a == rep[a] ? a : find(rep[a])); 
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a, b);
    rep[a] = b;
    sz[b] += sz[a];
}

int main(){_
    int n; cin >> n; // 2 * n = x * (x + 1)
    int x = ceil(sqrt(2* n)) + 1;
    rep.resize(x), sz.resize(x, 1);
    iota(rep.begin(), rep.end(), 0);

    set<tuple<int, int, int>> ed, edn;
    for(int i = 0; i < n; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        ed.insert({w, a, b});
        edn.insert({-w, a, b});
    }
    int mint = 0;
    for(auto [w, a, b] : ed){
        a = find(a), b = find(b);
        if(a == b) continue;
        mint += w;
        uni(a, b);
    }


    int maxt = 0;
    iota(rep.begin(), rep.end(), 0);
    sz.assign(n, 1);

    for(auto [w, a, b] : edn){
        a = find(a), b = find(b);
        if(a == b) continue;
        maxt += w;
        uni(a, b);
    }

    cout << -maxt << endl << mint << endl;

    return 0;
}