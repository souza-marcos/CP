#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> vis;

int main(){ _

    int n, m; cin >> n >> m;
    g.resize(n); vis.resize(n, false);

    while(m --){
        int i, j; cin >> i >> j;
        i --, j --;
        g[i].push_back(j);
        g[j].push_back(i);
    }

    pair<int, int> min_v = {-1, INF};
    for(int i = 0; i < n; i++){
        if(g[i].size() < min_v.s) {
            min_v.f = i;
            min_v.s = g[i].size();
        }
    }
    set<int> comp;
    comp.insert(min_v.f);
    for(auto el: g[min_v.f]){
        comp.insert(el);
    }

    for(int i = 0; i < n; i++){
        cout << (comp.count(i) == 0?"1":"0") << " ";
    }
    cout << endl;

    return 0;
} 
