#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges(m); // c - v - u
    vector<int> weights;
    for(auto& [c, v, u] : edges) cin >>  v >> u >> c, weights.push_back(c);

    sort(edges.begin(), edges.end());
    sort(weights.begin(), weights.end());

    int l = -1e10, r = 1e10; // limit the minimum weight
    while(l + 1 < r){
        int m = (l + r)/2;
        if(check(m)) r = 
    }

    return 0;
} 
